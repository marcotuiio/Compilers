#include "hash.h"

const int VAR_X = 304;
const int NUM_INT = 306;
const int NUM_FLOAT = 307;
const int MATRIX = 286;

void **createHash() {
    void **hashTable = calloc(HASH_SIZE, sizeof(HashNode));
    if (!hashTable) {
        printf("Erro ao alocar memoria para hash\n");
        exit(1);
    }
    insertHash(hashTable, "x", 0, VAR_X);
    insertHash(hashTable, "matrix", 0, MATRIX);
    return hashTable;
}

int hash(char *value) {
    int hash = 0;
    for (int i = 0; i < strlen(value); i++)
        hash += value[i] * (i + 1);
    return hash % HASH_SIZE;
}

HashNode *lookForValueInHash(void **hashTable, char *value) {
    if (!hashTable) return 0;
    int index = hash(value);
    HashNode *head = (HashNode *)hashTable[index];
    while (head) {
        if (!strcmp(value, head->varId)) return head;
        head = head->next;
    }
    return NULL;
}

void *insertHash(void **hashTable, char *varId, float valueId, int currentType) {
    if (!hashTable) return NULL;

    HashNode *aux = lookForValueInHash(hashTable, varId);
    if (aux) {
        aux->typeVar = currentType;
        aux->valueId = valueId;
        strcpy(aux->varId, varId);
        return aux;
    }

    int index = hash(varId);
    aux = calloc(1, sizeof(HashNode));
    aux->typeVar = currentType;
    aux->varId = calloc(strlen(varId) + 1, sizeof(char));
    strcpy(aux->varId, varId);
    aux->valueId = valueId;

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

float **createMatrix() {
    float **m = calloc(MAX_MATRIX_CREATABLE, sizeof(float *));
    for (int i = 0; i < MAX_MATRIX_CREATABLE; i++) {
        m[i] = calloc(MAX_MATRIX_CREATABLE, sizeof(float));
    }
    for (int i = 0; i < MAX_MATRIX_CREATABLE; i++) {
        for (int j = 0; j < MAX_MATRIX_CREATABLE; j++) {
            m[i][j] = DECOY;
        }
    }
    return m;
}

void fixMatrix(float **m, int line, int column) {
    float aux[line][column];
    int auxColumn = column - 1;

    // atribui os valores da matriz original na matriz auxiliar na ordem inversa
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            aux[i][auxColumn] = m[i][j];
            // printf("(%f) ", aux[i][auxColumn]);
            auxColumn--;
        }
        auxColumn = column - 1;
        // printf("\nauxColumn: %d\n", auxColumn);
    }

    // atribui os valores da matriz auxiliar na matriz original, colocando os valores DECOY no final substituindo os valores 0.0
    int decoyCount = 0;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            m[i][j] = aux[i][j];
            if (m[i][j] != DECOY) {
                m[i][decoyCount++] = m[i][j];
            }
        }
        while (decoyCount < column) {
            m[i][decoyCount++] = 0.0;
        }
        decoyCount = 0;
    }
}

void showMatrix(float **m, int line, int column, int floatPrecision) {
    if (!m) {
        printf("\nNo Matrix defined!\n\n");
        return;
    }

    printf("\n");
    // printf("\n+-");
    // // for (int j = 0; j < line; j++) {
    // //     printf(" ");
    // // }
    // printf("-+\n");

    for (int i = 0; i < line; i++) {
        printf("| ");
        for (int j = 0; j < column; j++) {
            printf("%.*f ", floatPrecision, m[i][j]);
        }
        printf("|\n");
    }

    // printf("+-");
    // for (int j = 0; j < column; j++) {
    //     printf(" ");
    // }
    // printf("-+\n\n");
    printf("\n");
}

void freeMatrix(float **m) {
    if (!m) return;
    for (int i = 0; i < MAX_MATRIX_CREATABLE; i++) {
        for (int j = 0; j < MAX_MATRIX_CREATABLE; j++) {
            m[i][j] = 0.0;
        }
        if (m[i]) free(m[i]);
    }
    free(m);
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

void showSymbols(void **hashTable) {
    if (!hashTable) return;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (!hashTable[i]) continue;
        HashNode *head = hashTable[i];
        while (head) {
            if (!strcmp(head->varId, "x") || !strcmp(head->varId, "matrix")) {
                head = head->next;
                continue;
            }
            char type[30];
            if (head->typeVar == NUM_FLOAT || head->typeVar == NUM_INT) {
                strcpy(type, "FLOAT");
            } else if (head->typeVar == MATRIX) {
                sprintf(type, "MATRIX[%d][%d]", head->lineMatrix, head->columnMatrix);
            }
            printf("\n%s - %s", head->varId, type);
            head = head->next;
        }
    }
    printf("\n\n");
}

void removeNode(void **hashTable, char *id) {
    if (!hashTable) return;
    int index = hash(id);
    HashNode *head = (HashNode *)hashTable[index];
    HashNode *prev = NULL;
    while (head) {
        if (!strcmp(id, head->varId)) {
            if (!prev) {
                hashTable[index] = head->next;
            } else {
                prev->next = head->next;
            }
            if (head->valueId) free(head->varId);
            free(head);
            return;
        }
        prev = head;
        head = head->next;
    }
}

void freeHash(void **hashTable) {
    if (!hashTable) return;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (!hashTable[i]) continue;
        HashNode *head = hashTable[i];
        while (head) {
            HashNode *aux = head->next;
            if (head->varId) free(head->varId);
            head->varId = NULL;
            if (head) free(head);
            head = aux;
        }
        // if (hashTable[i]) free(hashTable[i]);
        hashTable[i] = NULL;
    }
    if (hashTable) free(hashTable);
    hashTable = NULL;
}
