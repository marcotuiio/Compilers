%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ast.h"
#include "hash.h"

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

float h_view_lo = H_VIEW_LO;
float h_view_hi = H_VIEW_HI;
float v_view_lo = V_VIEW_LO;
float v_view_hi = V_VIEW_HI;
int float_precision = FLOAT_PRECISION;
int integral_steps_value = INTEGRAL_STEPS_VALUE;
bool draw_axis = DRAW_AXIS;
bool erase_plot = ERASE_PLOT;
bool connect_dots_op = CONNECT_DOTS_OP;

void **myHashTable = NULL;
ResultExpression *result = NULL;

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
    int op;
    char *value;
    Expression *expr;
    ResultExpression *result;
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
%token <value> ID
%token <value> NUM_INT
%token <value> NUM_FLOAT
%token EOL
/* %token ERROR */
%start S

%type <op> OpUnario
%type <op> OpMult
%type <result> Expressao
%type <expr> ExpressaoAditiva
%type <expr> ExpressaoMultiplicativa
%type <expr> ExpressaoUnaria
%type <expr> ExpressaoPrimaria

%%

S: Comandos EOL { printf(">"); return 0; }
    | Expressao EOL {
        switch ($1->type) {
            case NUM_INT:
                printf("\nNUM_INT: %d\n\n", (int)$1->r_float);
                break;
            case NUM_FLOAT:
                printf("\nNUM_FLOAT: %f\n\n", $1->r_float);
                break;
            case ID:
                printf("\nID: %s\n\n", $1->r_string);
                break;
            case VAR_X:
                printf("\nVAR_X: %s\n\n", $1->r_string);
                break;
            default:
                printf("\nERROR: Invalid Expression\n\n");
                break;
        }
        printf(">");
        return 0;   
    }
    | EOL { printf(">"); return 0; } ;

Comandos: SHOW SETTINGS SEMICOLON { showSettings(); } 
    | RESET SETTINGS SEMICOLON { resetSettings(); } 
    | SET H_VIEW Expressao COLON Expressao SEMICOLON { 
        if ($3->r_float > $5->r_float) {
            printf("\nERROR: h_view_lo must be less than h_view_hi\n\n");
            return 0;
        } else {
            h_view_lo = $3->r_float;
            h_view_hi = $5->r_float;
        }
    }
    | SET V_VIEW Expressao COLON Expressao SEMICOLON {
        if ($3->r_float > $5->r_float) {
            printf("\nERROR: v_view_lo must be less than v_view_hi\n\n");
            return 0;
        } else {
            v_view_lo = $3->r_float;
            v_view_hi = $5->r_float;
        }
    }
    | SET AXIS ON SEMICOLON { draw_axis = true; } 
    | SET AXIS OFF SEMICOLON { draw_axis = false; }
    | PLOT SEMICOLON { }
    | PLOT L_PAREN Funcao R_PAREN SEMICOLON { }
    | SET ERASE PLOT OFF SEMICOLON { erase_plot = false; }
    | SET ERASE PLOT ON SEMICOLON { erase_plot = true; }
    | SET RPN L_PAREN Expressao R_PAREN SEMICOLON { }
    | SET INTEGRAL_STEPS Expressao SEMICOLON { 
        if ((int) $3->r_float < 1) {
            printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
            return 0;
        } else {
            integral_steps_value = (int) $3->r_float;
        }
    }
    | INTEGRATE L_PAREN NUM_FLOAT COLON NUM_FLOAT COMMA Funcao R_PAREN SEMICOLON { }
    | SUM L_PAREN ID COMMA NUM_FLOAT COLON NUM_FLOAT COMMA Expressao R_PAREN SEMICOLON { } 
    | MATRIX ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON { }
    | SHOW MATRIX SEMICOLON { }
    | SOLVE DETERMINANT SEMICOLON { }
    | SOLVE LINEAR_SYSTEM SEMICOLON { }
    | ABOUT SEMICOLON { showAbout(); }
    | ID COLON_ASSIGN Expressao SEMICOLON {

    }
    | ID COLON_ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON { }
    | ID SEMICOLON { }
    | SHOW SYMBOLS SEMICOLON { }
    | SET FLOAT PRECISION Expressao SEMICOLON { float_precision = (int) $4->r_float; }
    | SET CONNECT_DOTS ON SEMICOLON { connect_dots_op = true; /*connectDots();*/ }
    | SET CONNECT_DOTS OFF SEMICOLON { connect_dots_op = false; }
    | QUIT { return QUIT; }
;

Repet_Matrix: COMMA NUM_FLOAT Repet_Matrix { }
    | { } ;

Repet_Dimen: COMMA L_SQUARE_BRACKET NUM_FLOAT Repet_Matrix R_SQUARE_BRACKET Repet_Dimen { }
    | { } ;

Funcao: SEN L_PAREN Expressao R_PAREN { }
    | COS L_PAREN Expressao R_PAREN { }
    | TAN L_PAREN Expressao R_PAREN { }
    | ABS L_PAREN Expressao R_PAREN { } ;

OpUnario: PLUS { $$ = PLUS; }
    | MINUS { $$ = MINUS; } ;

OpMult: MULTIPLY { $$ = MULTIPLY; }
    | DIVIDE { $$ = DIVIDE; }
    | REMAINDER { $$ = REMAINDER; } 
    | POWER { $$ = POWER; } ;

Expressao: ExpressaoAditiva { 
        result = evalExpression($1, myHashTable); 
        if (!result) {
            printf("\nERROR: Invalid Expression NULL\n\n");
            return 0;
        }
        $$ = result;
    } ;

ExpressaoAditiva: ExpressaoMultiplicativa { $$ = $1; }
    | ExpressaoAditiva OpUnario ExpressaoMultiplicativa {
        Expression *expr = createExpression(ADITIVA, $2, NULL, $1, $3);
        $$ = expr;
    } ;

ExpressaoMultiplicativa: ExpressaoUnaria { $$ = $1; }
    | ExpressaoMultiplicativa OpMult ExpressaoUnaria {
        Expression *expr = createExpression(MULTIPLICATIVA, $2, NULL, $1, $3);
        $$ = expr;
    } ;

ExpressaoUnaria: ExpressaoPrimaria { $$ = $1; }
    | OpUnario ExpressaoPrimaria {
        Expression *expr = createExpression(UNARIA, $1, NULL, $2, NULL);
        $$ = expr;
    } ;

ExpressaoPrimaria: ID {
        Expression *expr = createExpression(PRIMARIA, ID, $1, NULL, NULL);
        $$ = expr;
    }
    | VAR_X {
        Expression *expr = createExpression(PRIMARIA, VAR_X, "x", NULL, NULL);
        $$ = expr;
    }
    | NUM_INT {
        Expression *expr = createExpression(PRIMARIA, NUM_INT, $1, NULL, NULL);
        $$ = expr;
    }
    | NUM_FLOAT {
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, $1, NULL, NULL);
        $$ = expr;
    }    
    | PI {
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, "3.14159265", NULL, NULL);
        $$ = expr;
    }
    | EULER {
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, "2.71828182", NULL, NULL);
        $$ = expr;
    } 
    | L_PAREN ExpressaoAditiva R_PAREN {
        $$ = $2;
    } ;

%%

void yyerror(void *s) {
    if (yychar == EOL) {
        printf("\nSYNTAX ERROR: Incomplete Command\n\n");
        return;
    }
    printf("\nSYNTAX ERROR: [%d]\n\n", yychar);
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

int main(int argc, char *argv[]) {
    myHashTable = createHash();
    printf(">");
    while (true) {
        if (yyparse() == QUIT) break;
    }
    return 0;
}