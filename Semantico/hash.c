#include "hash.h"
extern void printLineError(int line, int column);

void **createHash() {
    void **hashTable = calloc(HASH_SIZE, sizeof(HashNode));
    if (!hashTable) {
        printf("Erro ao alocar memoria para hash\n");
        exit(1);
    }
    return hashTable;
}

int hash(char *value) {
    int hash = 0;
    for (int i = 0; i < strlen(value); i++)
        hash += value[i] * (i + 1);
    return hash % HASH_SIZE;
}

void *insertHash(void **hashTable, char *varId, int line, int column, int currentType, int pointer) {
    int index = hash(varId);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->typeVar = currentType;
    aux->varId = calloc(strlen(varId) + 1, sizeof(char));
    strcpy(aux->varId, varId);
    aux->line = line;
    aux->column = column;
    aux->pointer = pointer;

    HashNode *head = (HashNode *)hashTable[index];
    if (!head) {
        hashTable[index] = aux;
    } else {
        while (head->next)
            head = head->next;
        head->next = aux;
    }
    return aux;
}

void setPrototype(void *node) {
    HashNode *aux = (HashNode *)node;
    aux->prototype = 1;
}

void setQntdParams(void *node, int qntdParams) {
    HashNode *aux = (HashNode *)node;
    aux->qntdParams = qntdParams;
}

void setParam(void *node, Param *p) {
    HashNode *aux = (HashNode *)node;
    aux->param = p;
}

void setAssign(void *node, int assign) {
    HashNode *aux = (HashNode *)node;
    aux->assign = assign;
}

void setDimensions(void *node, void *dimensions) {
    HashNode *aux = (HashNode *)node;
    aux->dimensions = dimensions;
}

int lookForValueInHash(void **hashTable, char *varId, int line, int column, int currentType, int *textBefore, int *semanticError) {
    if (!hashTable) return 0;
    int index = hash(varId);
    int ocorrencias = 0;
    HashNode *head = (HashNode *)hashTable[index];

    while (head) {
        if (!strcmp(varId, head->varId)) {  // existe outro daquele identificador na hash
            if (head->prototype) continue;  // se for um prototipo, continua
            ocorrencias++;
            if (ocorrencias == 1) continue;      // se for o primeiro, continua
            if (currentType == head->typeVar) {  // se for do mesmo tipo
                if (*textBefore) printf("\n");
                printf("error:semantic:%d:%d: variable '%s' already declared, previous declaration in line %d column %d", line, column, varId, head->line, head->column);
                printLineError(line, column);
                freeHash(hashTable);
                exit(1);

            } else {  // se for de tipo diferente
                if (*textBefore) printf("\n");
                printf("error:semantic:%d:%d: redefinition of '%s' previous defined in line %d column %d", line, column, varId, head->line, head->column);
                printLineError(line, column);
                freeHash(hashTable);
                exit(1);
            }
        }
        head = head->next;
    }
    return 0;
}

Param *createParam(int type, char *identifier, int pointer, int line, int column, void *next) {
    Param *newParam = calloc(1, sizeof(Param));
    newParam->type = type;
    newParam->identifier = identifier;
    newParam->pointer = pointer;
    newParam->line = line;
    newParam->column = column;
    newParam->next = next;
    return newParam;
}

int lookForPrototypeInHash(void **hashTable, char *varId, int line, int column, int currentType, Param *p, int qntdParam, int *textBefore, int *semanticError) {
    if (!hashTable) return 0;
    int index = hash(varId);
    HashNode *head = (HashNode *)hashTable[index];

    while (head) {
        if (!strcmp(varId, head->varId) && head->prototype) {  // existe outro daquele identificador na hash
            if (currentType == head->typeVar) {                // se for do mesmo tipo
                Param *aux = head->param;
                if (head->qntdParams < qntdParam) {
                    if (*textBefore) printf("\n");
                    printf("error:semantic:%d:%d: prototype for '%s' declares fewer arguments", line, column, varId);
                    printLineError(line, column);
                    freeHash(hashTable);
                    exit(1);
                } else if (head->qntdParams > qntdParam) {
                    if (*textBefore) printf("\n");
                    printf("error:semantic:%d:%d: prototype for '%s' declares more arguments", line, column, varId);
                    printLineError(line, column);
                    freeHash(hashTable);
                    exit(1);
                } else {
                    while (aux) {
                        if (aux->type != p->type) {
                            if (*textBefore) printf("\n");
                            printf("error:semantic:%d:%d: argument '%s' does not match prototype", line, aux->column, aux->identifier);
                            printLineError(line, aux->column);
                            freeHash(hashTable);
                            exit(1);
                        }
                        aux = aux->next;
                        p = p->next;
                    }
                }
                return 0;

            } else {  // se for de tipo diferente
                if (*textBefore) printf("\n");
                printf("error:semantic:%d:%d: conflicting types for '%s'", line, column, varId);
                printLineError(line, column);
                freeHash(hashTable);
                exit(1);
            }
        }
        head = head->next;
    }
    return 0;
}

HashNode *getIdentifierNode(void **hashTable, char *id) {
    if (!hashTable) return NULL;
    int index = hash(id);
    HashNode *head = (HashNode *)hashTable[index];
    while (head) {
        // printf("head->value: %s %d\n", head->value, head->typeVar);
        if (!strcmp(id, head->varId)) return head;
        head = head->next;
    }
    return NULL;
}

char *getExactType(int type, int pointer) {
    char newType[50];
    switch (type) {
        case 275:  // int
        case 309:  // num_int
            strcpy(newType, "int");
            break;
        case 276:  // char
        case 313:  // character
            strcpy(newType, "char");
            break;
        case 277:  // void
            strcpy(newType, "void");
            break;
        case 312:  // string
            strcpy(newType, "char*");
            break;
        default:
            break;
    }
    for (int i = 0; i < pointer; i++) strcat(newType, "*");
    char *aux = calloc(strlen(newType) + 1, sizeof(char));
    strcpy(aux, newType);
    return aux;
}

void freeHash(void **hashTable) {
    if (!hashTable) return;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (!hashTable[i]) continue;
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
            if (head->varId) free(head->varId);
            head->varId = NULL;
            free(head);
            head = aux;
        }
        hashTable[i] = NULL;
    }
    free(hashTable);
    hashTable = NULL;
}