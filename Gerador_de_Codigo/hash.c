#include "hash.h"

extern void printLineError(int line, int column);
extern void deleteAuxFile();
extern int countDimension(void *dimensions);

extern void deleteMipsFileOnError(FILE *mipsFile, char *mipsPath);
extern FILE *mipsFile;
extern char *mipsPath;

void **createHash() {
    void **hashTable = calloc(HASH_SIZE, sizeof(HashNode));
    if (!hashTable) {
        printf("Erro ao alocar memoria para hash\n");
        deleteMipsFileOnError(mipsFile, mipsPath);
        deleteAuxFile();
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

void *insertHash(void **hashTable, char *varId, int currentType, int pointer) {
    int index = hash(varId);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->typeVar = currentType;
    aux->varId = calloc(strlen(varId) + 1, sizeof(char));
    strcpy(aux->varId, varId);
    aux->pointer = pointer;
    aux->assign = 1;
    aux->sRegister = -1;

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

void setIsConstant(void *node) {
    HashNode *aux = node;
    aux->isConstant = 1;
}

void setIsGlobal(void *node) {
    HashNode *aux = node;
    aux->isGlobal = 1;
}

void setQntdParams(void *node, int qntdParams) {
    HashNode *aux = node;
    aux->qntdParams = qntdParams;
}

void setParam(void *node, Param *p) {
    HashNode *aux = node;
    aux->param = p;
}

void setAssign(void *node, int assign) {
    HashNode *aux = node;
    aux->assign = assign;
}

void setDimensions(void *node, void *dimensions) {
    HashNode *aux = node;
    aux->dimensions = dimensions;
    int qntdDimen = countDimension(dimensions);
    aux->qntdDimen = qntdDimen;
    if (qntdDimen > 0) {
        aux->kind = VECTOR;
    } else {
        aux->kind = VAR;
    }
}

void setKind(void *node, int kind) {
    HashNode *aux = node;
    // printf("setting kind %s = %d %p\n", aux->varId, kind, node);
    aux->kind = kind;
}

void setHashExpr(void *node, void *hashExpr) {
    HashNode *aux = node;
    aux->hashExpr = hashExpr;
}

void setSRegisterInHash(void *node, int sRegister) {
    HashNode *aux = node;
    aux->sRegister = sRegister;
}

int getSRegisterFromHash(void *node) {
    HashNode *aux = node;
    return aux->sRegister;
}

int lookForValueInHash(void **hashTable, char *varId, int currentType) {
    if (!hashTable) return 0;
    int index = hash(varId);
    int ocorrencias = 0;
    HashNode *head = (HashNode *)hashTable[index];
    // printf("\nlooking for varId: %s in %p\n", varId, hashTable);
    while (head) {
        if (!strcmp(varId, head->varId)) {  // existe outro daquele identificador na hash
            ocorrencias++;
            if (ocorrencias == 1) continue;      // se for o primeiro, continua
            if (currentType == head->typeVar) {  // se for do mesmo tipo
                freeHash(hashTable);
                deleteAuxFile();
                exit(1);
            } else {  // se for de tipo diferente
                freeHash(hashTable);
                deleteAuxFile();
                exit(1);
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