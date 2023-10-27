%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
void yyerror(void *s);

extern int yychar;
extern int textBefore;

int erroAux = 0;
int semanticError = 0;

int currentType;

typedef struct node {
    int key;
    char *value;
    struct node *next;
} HashNode;

void **hashTable();
int hash(char *value);
void insertHash(char *value);
int lookForValueInHash(char *value);
void freeHash();

void **myHashTable = NULL;

%}

%union {
    struct {
        char *valor;
        int column;
        int line;
    } token;
}

%token MyEOF
%token EOL
%token ERRO
%token COMMA
%token INT
%token CHAR
%token FLOAT
%token ID

%start S

%%

S: D D_Prime EOL { erroAux = 0; return 0; }
    | error { erroAux = 1; return 0; } ;

D_Prime: D D_Prime { }
    | { } ;

D: T I { } ;

T: INT { currentType = INT; }
    | CHAR { currentType = CHAR; }
    | FLOAT { currentType = FLOAT; } ;

I: ID { 
    // printf(">> %d %s\n\n", currentType, yylval.token.valor);
    if (!lookForValueInHash(yylval.token.valor))
        insertHash(yylval.token.valor); 
}
    | I COMMA ID { 
        // printf("-> %d %s\n\n", currentType, yylval.token.valor);
        if (!lookForValueInHash(yylval.token.valor))
            insertHash(yylval.token.valor); 
} ;

%%

void yyerror(void *s) {}

void **hashTable() {
    void **hashTable = calloc(211, sizeof(HashNode));
    return hashTable;
}

int hash(char *value) {
    int hash = 0;
    for (int i = 0; i < strlen(value); i++) hash += value[i];
    return hash % 211;
}

void insertHash(char *value) {
    if (!myHashTable) myHashTable = hashTable();
    // printf("%p\n", myHashTable);
    int index = hash(value);
    // printf("index %d\n", index);
    HashNode *aux = calloc(1, sizeof(HashNode));
    printf("\n Node inserted: %s\n", aux->value);
    aux->key = currentType;
    strcpy(aux->value, value);

    exit(1);
    HashNode *head = (HashNode *) myHashTable[index];
    while (head) head = head->next;
    head = aux;
}

int lookForValueInHash(char *value) {
    if (!myHashTable) return 0;
    int index = hash(value);
    int ocorrencias = 0;
    HashNode *head = (HashNode *) myHashTable[index];

    while (head) {
        if (!strcmp(value, head->value)) { // existe outro daquele identificador na hash
            ocorrencias++;
            if (ocorrencias == 1) continue;  // se for o primeiro, continua 
            if (currentType == head->key) {  // se for do mesmo tipo
                if (textBefore) printf("\n");
                printf("identifier '%s' already declared", value);
                semanticError = 1;
                textBefore = 1;
                return 1;

            } else {  // se for de tipo diferente
                if (textBefore) printf("\n");
                printf("redefinition of identifier '%s'", value);
                semanticError = 1;
                textBefore = 1;
                return 1;
            }
        }
        head = head->next;
    }
    return 0;
}

void freeHash() {
    for (int i = 0; i < 211; i++) {
        HashNode *head = (HashNode *) myHashTable[i];
        while (head) {
            HashNode *aux = head;
            head = head->next;
            if (aux) free(aux);
        }
    }
    free(myHashTable);
}

int main(int argc, char *argv[]) {
    yyparse();

    if (textBefore) printf("\n");
    if (erroAux) {

        if (yychar == 0 || yychar == MyEOF) {
            printf("error:syntax:%d:%d: expected declaration or statement at end of input", yylval.token.line, yylval.token.column);
        
        } else {
            printf("error:syntax:%d:%d: %s", yylval.token.line, yylval.token.column, yylval.token.valor);
        }

    } else {
        if (semanticError == 0) {
            if (textBefore) printf("\n");
            printf("All Identifiers on Hash.");
            textBefore = 1;
        }
        if (myHashTable) freeHash(myHashTable);
    }
    return 0;
}