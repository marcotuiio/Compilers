%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 211

#define H_VIEW_LO -6.500000
#define H_VIEW_HI 6.500000
#define V_VIEW_LO -3.500000
#define V_VIEW_HI 3.500000
#define FLOAT_PRECISION 6
#define INTEGRAL_STEPS_VALUE 1000
#define DRAW_AXIS true
#define ERASE_PLOT true
#define CONNECT_DOTS_OP false

extern int yylex();
void yyerror(void *s);

extern int yychar;
extern int myEof;

int erroAux = 0;
int semanticError = 0;

float h_view_lo = H_VIEW_LO;
float h_view_hi = H_VIEW_HI;
float v_view_lo = V_VIEW_LO;
float v_view_hi = V_VIEW_HI;
int float_precision = FLOAT_PRECISION;
int integral_steps_value = INTEGRAL_STEPS_VALUE;
bool draw_axis = DRAW_AXIS;
bool erase_plot = ERASE_PLOT;
bool connect_dots_op = CONNECT_DOTS_OP;

typedef struct node {
    int key;
    char *value;
    struct node *next;
} HashNode;

void showSettings();
void resetSettings();
void showAbout();

// int hash();
// void insertHash();
// int lookForValueInHash();
// void freeHash();

// void **myHashTable = NULL;

%}

%union {
    int v_int;
    float v_float;
    char *v_string;
    void *teste;
}

%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token POWER
%token REMAINDER
%token ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token COLON_ASSIGN
%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token ABOUT
%token ABS
%token AXIS
%token CONNECT_DOTS
%token COS
%token DETERMINANT
%token ERASE
%token EULER
%token FLOAT
%token H_VIEW
%token INTEGRAL_STEPS
%token INTEGRATE
%token LINEAR_SYSTEM
%token MATRIX
%token OFF
%token ON
%token PI
%token PLOT
%token PRECISION
%token QUIT
%token RESET
%token RPN
%token SEN
%token SET
%token SETTINGS
%token SHOW
%token SOLVE
%token SUM
%token SYMBOLS
%token TAN
%token V_VIEW
%token VAR_X
%token <v_string> ID
%token <v_int> NUM_INT
%token <v_float> NUM_FLOAT
%token EOL
%start S

%type <teste> ExpressaoPrimaria

%%

S: Programa EOL { return 0; }

Programa: Comandos SEMICOLON { } 
    | Expressao { } ;

Comandos: SHOW SETTINGS { showSettings(); } 
    | RESET SETTINGS { resetSettings(); } 
    | SET H_VIEW Expressao COLON Expressao { 
        // if ($3 > $5) {
        //     printf("\nERROR: h_view_lo must be less than h_view_hi\n");
        // } else {
        //     h_view_lo = $3;
        //     h_view_hi = $5;
        // }
    }
    | SET V_VIEW Expressao COLON Expressao {
        // if ($3 > $5) {
        //     printf("\nERROR: v_view_lo must be less than v_view_hi\n");
        // } else {
        //     v_view_lo = $3;
        //     v_view_hi = $5;
        // }
    }
    | SET AXIS ON { } 
    | SET AXIS OFF { }
    | PLOT { }
    | PLOT L_PAREN Funcao R_PAREN { }
    | SET ERASE PLOT OFF { }
    | SET ERASE PLOT ON { }
    | SET RPN L_PAREN Expressao R_PAREN { }
    | SET INTEGRAL_STEPS NUM_INT { }
    | INTEGRATE L_PAREN NUM_FLOAT COLON NUM_FLOAT COMMA Funcao R_PAREN { }
    | SUM L_PAREN ID COMMA NUM_FLOAT COLON NUM_FLOAT COMMA Expressao R_PAREN { } 
    | MATRIX ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET { }
    | SHOW MATRIX { }
    | SOLVE DETERMINANT { }
    | SOLVE LINEAR_SYSTEM { }
    | ABOUT { showAbout(); }
    | ID COLON_ASSIGN Expressao { }
    | ID COLON_ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET { }
    | ID { }
    | SHOW SYMBOLS { }
    | SET FLOAT PRECISION NUM_INT { }
    | SET CONNECT_DOTS ON { }
    | SET CONNECT_DOTS OFF { }
;

Repet_Matrix: COMMA NUM_FLOAT Repet_Matrix { }
    | { } ;

Repet_Dimen: COMMA L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen { }
    | { } ;

Funcao: SEN L_PAREN Expressao R_PAREN { }
    | COS L_PAREN Expressao R_PAREN { }
    | TAN L_PAREN Expressao R_PAREN { }
    | ABS L_PAREN Expressao R_PAREN { } ;
 
Expressao: QUIT { return QUIT; }
    | ExpressaoAditiva { } ;

OpUnario: PLUS { }
    | MINUS { } ;

OpMult: MULTIPLY { }
    | DIVIDE { }
    | REMAINDER { } 
    | POWER { } ;

ExpressaoAditiva: ExpressaoMultiplicativa { }
    | ExpressaoAditiva OpUnario ExpressaoMultiplicativa { } ;

ExpressaoMultiplicativa: ExpressaoUnaria { }
    | ExpressaoMultiplicativa OpMult ExpressaoUnaria { } ;

ExpressaoUnaria: ExpressaoPrimaria { }
    | OpUnario ExpressaoPrimaria { } ;

ExpressaoPrimaria: ID { }
    | VAR_X { }
    | NUM_INT { }
    | NUM_FLOAT { }    
    | PI { $$ = 3.14159265; }
    | EULER { $$ = 2.71828182; } 
    | L_PAREN Expressao R_PAREN { } ;

%%

void yyerror(void *s) {
    printf("\nSYNTAX ERROR: NAO SEI AINDA\n");
}

void showSettings() {
    printf("\nh_view_lo: %.6f\n", h_view_lo);
    printf("h_view_hi: %.6f\n", h_view_hi);
    printf("v_view_lo: %.6f\n", v_view_lo);
    printf("v_view_hi: %.6f\n", v_view_hi);
    printf("float_precision: %d\n", float_precision);
    printf("integral_steps_value: %d\n", integral_steps_value);
    printf("\nDraw Axis: %s\n", draw_axis ? "ON" : "OFF");
    printf("Erase Plot: %s\n", erase_plot ? "ON" : "OFF");
    printf("Connect Dots: %s\n\n", connect_dots_op ? "ON" : "OFF");
}

void resetSettings() {
    h_view_lo = H_VIEW_LO;
    h_view_hi = H_VIEW_HI;
    v_view_lo = V_VIEW_LO;
    v_view_hi = V_VIEW_HI;
    float_precision = FLOAT_PRECISION;
    integral_steps_value = INTEGRAL_STEPS_VALUE;
    draw_axis = DRAW_AXIS;
    erase_plot = ERASE_PLOT;
    connect_dots_op = CONNECT_DOTS_OP;
}

void showAbout() {
    printf("\n+-------------------------------------------------------+\n");
    printf("|                                                       |\n");
    printf("|              Marco Tulio Alves de Barros              |\n");
    printf("|                     202100560105                      |\n");
    printf("|                                                       |\n");
    printf("+-------------------------------------------------------+\n\n");
}   

/* int hash() {
    int hash = 0;
    for (int i = 0; i < strlen(yylval.token.valor); i++)
        hash += yylval.token.valor[i];
    return hash % HASH_SIZE;
}

void insertHash() {
    int index = hash(yylval.token.valor);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->key = currentType;
    aux->value = calloc(strlen(yylval.token.valor) + 1, sizeof(char));
    strcpy(aux->value, yylval.token.valor);

    HashNode *head = (HashNode *) myHashTable[index];
    if (!head) {
        myHashTable[index] = aux;
    } else {
        while (head->next) 
            head = head->next;
        head->next = aux;
    }

}

int lookForValueInHash() {
    if (!myHashTable) return 0;
    int index = hash(yylval.token.valor);
    int ocorrencias = 0;
    HashNode *head = (HashNode *) myHashTable[index];

    while (head) {
        if (!strcmp(yylval.token.valor, head->value)) { // existe outro daquele identificador na hash
            ocorrencias++;
            if (ocorrencias == 1) continue;  // se for o primeiro, continua 
            if (currentType == head->key) {  // se for do mesmo tipo
                if (textBefore) printf("\n");
                printf("%d: identifier '%s' already declared", yylval.token.line, yylval.token.valor);
                semanticError = 1;
                textBefore = 1;
                return 1;

            } else {  // se for de tipo diferente
                if (textBefore) printf("\n");
                printf("%d: redefinition of identifier '%s'", yylval.token.line, yylval.token.valor);
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
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *head = myHashTable[i];
        while (head) {
            HashNode *aux = head->next;
            if (head->value) 
                free(head->value);
            free(head);
            head = aux;
        }
        myHashTable[i] = NULL; 
    }
} */

int main(int argc, char *argv[]) {
    while (true) {
        printf(">");
        if (yyparse() == QUIT) break;
    }
    return 0;
}