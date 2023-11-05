#include "hash.h"

void **createHash() {
    void **hashTable = calloc(HASH_SIZE, sizeof(HashNode));
    printf("criando hash %p\n", hashTable);
    if (!hashTable) {
        printf("Erro ao alocar memoria para hash\n");
        exit(-1);
    }
    return hashTable;
}

int hash(char *value) {
    int hash = 0;
    for (int i = 0; i < strlen(value); i++)
        hash += value[i] * (i + 1);
    return hash % HASH_SIZE;
}

void insertHash(void **hashTable, char *value, int line, int column, int currentType, int pointer, Param *p, int prototype, void *assign, void *dimensions) {
    printf("inserting %s in %p \n", value, hashTable);
    int index = hash(value);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->typeVar = currentType;
    aux->value = calloc(strlen(value) + 1, sizeof(char));
    strcpy(aux->value, value);
    aux->line = line;
    aux->column = column;
    aux->pointer = pointer;
    aux->assign = assign;
    aux->dimensions = dimensions;
    aux->param = p;
    aux->prototype = prototype;

    HashNode *head = (HashNode *) hashTable[index];
    if (!head) {
        hashTable[index] = aux;
    } else {
        while (head->next) 
            head = head->next;
        head->next = aux;
    }
}

int lookForValueInHash(void **hashTable, char *value, int line, int column, int currentType, int *textBefore, int *semanticError) {
    if (!hashTable) return 0;
    printf("looking for %s in %p \n", value, hashTable);
    int index = hash(value);
    int ocorrencias = 0;
    HashNode *head = (HashNode *) hashTable[index];

    while (head) {
        if (!strcmp(value, head->value)) { // existe outro daquele identificador na hash
            if (head->prototype) continue;  // se for um prototipo, continua
            ocorrencias++;
            if (ocorrencias == 1) continue;  // se for o primeiro, continua 
            if (currentType == head->typeVar) {  // se for do mesmo tipo
                if (*textBefore) printf("\n");
                printf("error:semantic:%d:%d: variable '%s' already declared, previous declaration in line %d column %d", line, column, value, head->line, head->column);
                *semanticError = 1;
                *textBefore = 1;
                freeHash(hashTable);
                exit(-1);

            } else {  // se for de tipo diferente
                if (*textBefore) printf("\n");
                printf("error:semantic:%d:%d: redefinition of '%s' previous defined in line %d column %d", line, column, value, head->line, head->column);
                *semanticError = 1;
                *textBefore = 1;
                freeHash(hashTable);
                exit(-1);
            }
        }
        head = head->next;
    }
    return 0;
}

Param *createParam(int type, char *identifier, int pointer, void *next) {
    Param *newParam = calloc(1, sizeof(Param));
    newParam->type = type;
    newParam->identifier = identifier;
    newParam->pointer = pointer;
    newParam->next = next;
    return newParam;
}

int lookForPrototypeInHash(void **hashTable, char *value, int line, int column, int currentType, Param *p, int *textBefore, int *semanticError) {
    if (!hashTable) return 0;
    printf("looking for prototype %s in %p \n", value, hashTable);
    int index = hash(value);
    HashNode *head = (HashNode *) hashTable[index];

    while (head) {
        if (!strcmp(value, head->value)) { // existe outro daquele identificador na hash
            if (currentType == head->typeVar) {  // se for do mesmo tipo
                Param *aux = head->param;
                while (aux && p) {
                    if (p->type != aux->type) {
                        if (*textBefore) printf("\n");
                        printf("error:semantic:%d:%d: argument '%s' does not match prototype", line, column, p->identifier);
                        *semanticError = 1;
                        *textBefore = 1;
                        freeHash(hashTable);
                        exit(-1);
                    }
                    aux = aux->next;
                    p = p->next;
                }
                return 0;

            } else {  // se for de tipo diferente
                if (*textBefore) printf("\n");
                printf("error:semantic:%d:%d: conflicting types for '%s'", line, column, value);
                *semanticError = 1;
                *textBefore = 1;
                freeHash(hashTable);
                exit(-1);
            }
        }
        head = head->next;
    }
    return 0;
}

void freeHash(void **hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *head = hashTable[i];
        while (head) {
            HashNode *aux = head->next;
            if (head->param) {
                Param *p = head->param;
                while (p) {
                    Param *auxP = p->next;
                    free(p);
                    p = auxP;
                }
            }
            if (head->value) 
                free(head->value);
            free(head);
            head = aux;
        }
        hashTable[i] = NULL; 
    }
    free(hashTable);
}