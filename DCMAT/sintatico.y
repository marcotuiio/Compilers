%{
    
// Author: Marco Tulio Alves de Barros

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ast.h"
#include "hash.h"
#include "graphs_manager.h"

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
float **myMatrix = NULL;
float **myMatrixAux = NULL;

int isRpn = 0;

int isPlot = 0;
int hasFunction = 0;
Expression *myFunction = NULL;

int lineMat = 0;
int colMat = 1;
int auxColMat = 1;
int lineBack = 0;

void showSettings();
void resetSettings();
void plotGraph(Expression *expr);
float gaussDeterminant(float **a, int line);
float *gaussLinearSystem(float **m, int line);
void showAbout();

%}

%union {
    int op;
    char *value;
    Expression *expr;
    ResultExpression *result;
    Function *func;
}

%token <value> PLUS
%token <value> MINUS
%token <value> MULTIPLY
%token <value> DIVIDE
%token <value> POWER
%token <value> REMAINDER
%token <value> ASSIGN
%token <value> SEMICOLON
%token <value> COMMA
%token <value> COLON
%token <value> COLON_ASSIGN
%token <value> L_PAREN
%token <value> R_PAREN
%token <value> L_SQUARE_BRACKET
%token <value> R_SQUARE_BRACKET
%token <value> ABOUT
%token <value> ABS
%token <value> AXIS
%token <value> CONNECT_DOTS
%token <value> COS
%token <value> DETERMINANT
%token <value> ERASE
%token <value> EULER
%token <value> FLOAT
%token <value> H_VIEW
%token <value> INTEGRAL_STEPS
%token <value> INTEGRATE
%token <value> LINEAR_SYSTEM
%token <value> MATRIX
%token <value> OFF
%token <value> ON
%token <value> PI
%token <value> PLOT
%token <value> PRECISION
%token <value> QUIT
%token <value> RESET
%token <value> RPN
%token <value> SEN
%token <value> SET
%token <value> SETTINGS
%token <value> SHOW
%token <value> SOLVE
%token <value> SUM
%token <value> SYMBOLS
%token <value> TAN
%token <value> V_VIEW
%token <value> VAR_X
%token <value> ID
%token <value> NUM_INT
%token <value> NUM_FLOAT
%token EOL

%start S

%type <func> Funcao
%type <op> OpUnario
%type <op> OpMult
%type <value> Token_Matrix_Id
%type <result> Expressao
%type <expr> ExpressaoAditiva
%type <expr> ExpressaoMultiplicativa
%type <expr> ExpressaoUnaria
%type <expr> ExpressaoPrimaria

%%

S: Comandos EOL { printf(">"); return 0; }
    | Expressao EOL {
        if (hasFunction) {
            hasFunction = 0;
            printf("\nThe x variable cannot be present on expressions.\n\n");
        } else {
            if ($1) {
                switch ($1->type) {
                    case NUM_INT:
                    case NUM_FLOAT:
                        printf("\n%.*f\n\n", float_precision, $1->r_float);
                        break;
                    case MATRIX:
                        showMatrix($1->matrix, $1->line, $1->column, float_precision);
                        break;
                    case ID:
                        break;
                    default:
                        printf("\nERROR: Invalid Expression\n\n");
                        break;
                }
            } else {
                printf("\n\n");
            }
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
    | PLOT SEMICOLON {
        if (!myFunction) {
            printf("\nNo Function defined!\n\n");
            return 0;
        }
        plotGraph(myFunction);
        hasFunction = 0;
    }
    | PLOT L_PAREN ExpressaoAditiva R_PAREN SEMICOLON {
        if (!$3) {
            printf("\n\n");
            return 0;
        }
        plotGraph($3);
        hasFunction = 0;
    }
    | SET ERASE PLOT OFF SEMICOLON { erase_plot = false; }
    | SET ERASE PLOT ON SEMICOLON { erase_plot = true; }
    | Token_Rpn ExpressaoAditiva R_PAREN SEMICOLON {
        isRpn = 0;
        printf("\n\n");
        // hasFunction = 0;
        // myFunction = NULL;
    }
    | SET INTEGRAL_STEPS Expressao SEMICOLON { 
        if ((int) $3->r_float < 1) {
            printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
            return 0;
        } else {
            integral_steps_value = (int) $3->r_float;
        }
    }
    | INTEGRATE L_PAREN Expressao COLON Expressao COMMA ExpressaoAditiva R_PAREN SEMICOLON {
        if (!$3 || !$5) {
            printf("\n\n");
            return 0;
        }

        if ($3->r_float > $5->r_float) {
            printf("\nERROR: integral lower limit must be smaller than upper limit\n\n");
            return 0;
        
        } else {
            float integral = 0;
            float step = ($5->r_float - $3->r_float) / integral_steps_value;
            ResultExpression *integrand = NULL;
            
            HashNode *xVar = getIdentifierNode(myHashTable, "x");
            xVar->valueId = $3->r_float;

            for (int i = 0; i < integral_steps_value; i++) {
                integrand = evalExpression($7, myHashTable);
                if (!integrand) {
                    printf("\n\n");
                    return 0;
                }
                integral += integrand->r_float;
                xVar->valueId += step;
            }
            integral *= step;
            printf("\n%.*f\n\n", float_precision, integral);
        }
    }
    | SUM L_PAREN ID COMMA Expressao COLON Expressao COMMA ExpressaoAditiva R_PAREN SEMICOLON {
        float sum = 0;
        insertHash(myHashTable, $3, $5->r_float, NUM_FLOAT);
        ResultExpression *summand = NULL;
        
        HashNode *node = getIdentifierNode(myHashTable, $3);

        for (int i = (int) node->valueId; i <= (int) $7->r_float; i++) {
            summand = evalExpression($9, myHashTable);
            if (!summand) {
                printf("\n\n");
                removeNode(myHashTable, $3);
                return 0;
            }
            sum += summand->r_float;
            node->valueId++;
        }
        printf("\n%.*f\n\n", float_precision, sum);
        removeNode(myHashTable, $3); // opção de remover a variável do hash pois trata-se de um iterador e nao de uma variável
    } 
    | Token_Matrix ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET Expressao Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON {
        if (auxColMat > colMat) {
            colMat = auxColMat; 
        }
        if (lineMat > MAX_MATRIX_SIZE || colMat > MAX_MATRIX_SIZE) {
            printf("\nERROR: Matrix limits out of boundaries.\n\n");
            return 0;
        }
        // printf("dimensoes [%d][%d]\n", lineMat, colMat);
 
        myMatrix[0][colMat-1] = $5->r_float;
        // printf("inserting first in matrix: %f 0-%d\n", $5->r_float, colMat-1);

        HashNode *node = getIdentifierNode(myHashTable, "matrix");
        node->lineMatrix = lineMat;
        node->columnMatrix = colMat;
        fixMatrix(myMatrix, lineMat, colMat);
    }
    | SHOW MATRIX SEMICOLON {
        HashNode *node = getIdentifierNode(myHashTable, "matrix");
        showMatrix(myMatrix, node->lineMatrix, node->columnMatrix, float_precision); 
    }
    | SOLVE DETERMINANT SEMICOLON {
        if (!myMatrix) {
            printf("\nNo Matrix defined!\n\n");
            return 0;
        }
        HashNode *node = getIdentifierNode(myHashTable, "matrix");
        if (node->lineMatrix != node->columnMatrix) {
            printf("\nMatrix format incorrect!\n\n");
            return 0;
        }
        float det = gaussDeterminant(myMatrix, node->lineMatrix);
        printf("\n%.*f\n\n", float_precision, det);
    }
    | SOLVE LINEAR_SYSTEM SEMICOLON {
        if (!myMatrix) {
            printf("\nNo Matrix defined!\n\n");
            return 0;
        }
        HashNode *node = getIdentifierNode(myHashTable, "matrix");
        if (node->columnMatrix != node->lineMatrix + 1) {
            printf("\nMatrix format incorrect!\n\n");
            return 0;
        }
        float *x = gaussLinearSystem(myMatrix, lineMat);
        if (x) {
            printf("\nMatrix x:\n");
            for (int i = 0; i < lineMat; i++) {
                printf("\n%.*f ", float_precision, x[i]);
            }
            printf("\n\n");
        }
    }
    | ABOUT SEMICOLON { showAbout(); }
    | ID COLON_ASSIGN Expressao SEMICOLON {
        if ($3) {   
            if ($3->type == MATRIX) {
                showMatrix($3->matrix, $3->line, $3->column, float_precision);
                insertHash(myHashTable, $1, 0, MATRIX);
                HashNode *node = getIdentifierNode(myHashTable, $1);
                node->matrix = $3->matrix;
                node->lineMatrix = $3->line;
                node->columnMatrix = $3->column;
            } else {
                insertHash(myHashTable, $1, $3->r_float, NUM_FLOAT);
                printf("\n%.*f\n\n", float_precision, $3->r_float);
            }
            
        } else {
            printf("\n\n");
        }
        return 0;
    }
    | Token_Matrix_Id Expressao Repet_Matrix R_SQUARE_BRACKET Repet_Dimen R_SQUARE_BRACKET SEMICOLON {
        if (auxColMat > colMat) {
            colMat = auxColMat; 
        }
        if (lineMat > MAX_MATRIX_SIZE || colMat > MAX_MATRIX_SIZE) {
            printf("\nERROR: Matrix limits out of boundaries.\n\n");
            return 0;
        }
        // printf("dimensoes [%d][%d]\n", lineMat, colMat);
        myMatrix[0][colMat-1] = $2->r_float;
        // printf("inserting first in matrix: %f 0-%d\n", $2->r_float, colMat-1);

        HashNode *node = getIdentifierNode(myHashTable, $1);
        node->lineMatrix = lineMat;
        node->columnMatrix = colMat;
        fixMatrix(myMatrix, lineMat, colMat);
        showMatrix(myMatrix, node->lineMatrix, node->columnMatrix, float_precision);
        myMatrix = myMatrixAux;
    }
    | ID SEMICOLON {
        HashNode *node = getIdentifierNode(myHashTable, $1);
        if (!node) {
            printf("\nUndefined symbol [%s]\n\n", $1);
            return 0;
        }
        if (node->typeVar == NUM_FLOAT || node->typeVar == NUM_INT) {
            printf("\n%s = %.*f\n\n", node->varId, float_precision, node->valueId);
        } else if (node->typeVar == MATRIX) {
            showMatrix(node->matrix, node->lineMatrix, node->columnMatrix, float_precision);
        }
        return 0;
    }
    | SHOW SYMBOLS SEMICOLON { showSymbols(myHashTable); return 0; }
    | SET FLOAT PRECISION Expressao SEMICOLON {
        if ((int) $4->r_float < 0 || (int) $4->r_float > 8) {
            printf("\nERROR: float_precision must be from 0 to 8\n\n");
            return 0;
        } 
        float_precision = (int) $4->r_float; 
        return 0;
    }
    | SET CONNECT_DOTS ON SEMICOLON { connect_dots_op = true; /*connectDots();*/ }
    | SET CONNECT_DOTS OFF SEMICOLON { connect_dots_op = false; }
    | QUIT { freeHash(myHashTable); return QUIT; } ;

Token_Rpn: RPN L_PAREN {
        printf("\nExpression in RPN format:\n\n");
        isRpn = 1;
    };

Token_Matrix: MATRIX { 
        freeMatrix(myMatrix); 
        myMatrix = createMatrix(); 
        auxColMat = 1;
        lineMat = 0;
        colMat = 1;
    } ;

Token_Matrix_Id: ID COLON_ASSIGN L_SQUARE_BRACKET L_SQUARE_BRACKET {
        myMatrixAux = myMatrix;
        float **matrix = createMatrix();
        insertHash(myHashTable, $1, 0, MATRIX);
        HashNode *node = getIdentifierNode(myHashTable, $1);
        node->matrix = matrix;
        auxColMat = 1;
        lineMat = 0;
        colMat = 1;
        myMatrix = matrix;
        $$ = $1;
    };

Repet_Matrix: COMMA Expressao Repet_Matrix {
        auxColMat++;
        if (auxColMat > colMat) {
            colMat = auxColMat; 
        }
        myMatrix[lineMat-1][auxColMat-2] = $2->r_float;
        // printf("0 inserting in matrix: %f = [%d][%d]\n", $2->r_float, lineMat-1, auxColMat-2);
    }
    | { lineMat++; auxColMat = 1; } ;

Repet_Dimen: COMMA L_SQUARE_BRACKET Expressao Repet_Matrix R_SQUARE_BRACKET Repet_Dimen {
        myMatrix[lineBack][colMat-1] = $3->r_float;
        // printf("2 inserting in matrix: %f = [%d][%d]\n", $3->r_float, lineBack, colMat-1);
        lineBack--;
    }
    | { lineBack = lineMat - 1; } ;

Funcao: SEN L_PAREN ExpressaoAditiva R_PAREN {
        if (isRpn)
            printf("SEN ");
    
        Function *func = createFunction(SEN, $3);
        $$ = func;
    }
    | COS L_PAREN ExpressaoAditiva R_PAREN { 
        if (isRpn)
            printf("COS ");

        Function *func = createFunction(COS, $3);
        $$ = func;
    }
    | TAN L_PAREN ExpressaoAditiva R_PAREN {
        if (isRpn)
            printf("TAN ");
        Function *func = createFunction(TAN, $3);
        $$ = func;
    }
    | ABS L_PAREN ExpressaoAditiva R_PAREN {
        if (isRpn)
            printf("ABS ");
        Function *func = createFunction(ABS, $3);
        $$ = func;
    } ;

OpUnario: PLUS { $$ = PLUS; }
    | MINUS { $$ = MINUS; } ;

OpMult: MULTIPLY { $$ = MULTIPLY; }
    | DIVIDE { $$ = DIVIDE; }
    | REMAINDER { $$ = REMAINDER; } 
    | POWER { $$ = POWER; } ;

Expressao: ExpressaoAditiva { 
        ResultExpression *result = evalExpression($1, myHashTable); 
        if (hasFunction) {
            // printf("has function\n");
            myFunction = $1;
        }
        $$ = result;
    } ;

ExpressaoAditiva: ExpressaoMultiplicativa { $$ = $1; }
    | ExpressaoAditiva OpUnario ExpressaoMultiplicativa {
        if (isRpn) {
            switch ($2) {
                case PLUS:
                    printf("+ ");
                    break;
                case MINUS:
                    printf("- ");
                    break;
            }
        }
        Expression *expr = createExpression(ADITIVA, $2, NULL, $1, $3);
        $$ = expr;
    } ;

ExpressaoMultiplicativa: ExpressaoUnaria { $$ = $1; }
    | ExpressaoMultiplicativa OpMult ExpressaoUnaria {
        if (isRpn) {
            switch ($2) {
                case MULTIPLY:
                    printf("* ");
                    break;
                case DIVIDE:
                    printf("/ ");
                    break;
                case REMAINDER:
                    printf("%% ");
                    break;
                case POWER:
                    printf("^ ");
                    break;
            }
        }
        Expression *expr = createExpression(MULTIPLICATIVA, $2, NULL, $1, $3);
        $$ = expr;
    } ;

ExpressaoUnaria: ExpressaoPrimaria { $$ = $1; }
    | OpUnario ExpressaoPrimaria {
        if (isRpn) {
            switch ($1) {
                case PLUS:
                    printf("+ ");
                    break;
                case MINUS:
                    printf("- ");
                    break;
            }
        }
        Expression *expr = createExpression(UNARIA, $1, NULL, $2, NULL);
        $$ = expr;
    } ;

ExpressaoPrimaria: ID {
        if (isRpn)
            printf("%s ", $1);
        Expression *expr = createExpression(PRIMARIA, ID, $1, NULL, NULL);
        $$ = expr;
    }
    | VAR_X {
        if (isRpn)
            printf("x ");
        Expression *expr = createExpression(PRIMARIA, VAR_X, "x", NULL, NULL);
        hasFunction = 1;
        $$ = expr;
    }
    | NUM_INT {
        if (isRpn)
            printf("%.*f ", float_precision, atof($1));
        Expression *expr = createExpression(PRIMARIA, NUM_INT, $1, NULL, NULL);
        $$ = expr;
    }
    | NUM_FLOAT {
        if (isRpn)
            printf("%.*f ", float_precision, atof($1));
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, $1, NULL, NULL);
        $$ = expr;
    }    
    | PI {
        if (isRpn)
            printf("%.*f ", float_precision, 3.14159265);
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, "3.14159265", NULL, NULL);
        $$ = expr;
    }
    | EULER {
        if (isRpn)
            printf("%.*f ", float_precision, 2.71828182);
        Expression *expr = createExpression(PRIMARIA, NUM_FLOAT, "2.71828182", NULL, NULL);
        $$ = expr;
    } 
    | L_PAREN ExpressaoAditiva R_PAREN {
        $$ = $2;
    } 
    | Funcao {
        Expression *expr = createExpression(PRIMARIA, FUNCTION, NULL, NULL, NULL);
        expr->func = $1;
        $$ = expr;
    } ;

%%

void yyerror(void *s) {
    if (yychar == EOL) {
        printf("\nSYNTAX ERROR: Incomplete Command\n\n>");
        return;
    }
    if (yychar != 0) {
        printf("\nSYNTAX ERROR: [%s]\n\n", yylval.value);
    }
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

void plotGraph(Expression *expr) {
    if (erase_plot) clearAxis();
    float xStep = (h_view_hi - h_view_lo) / (float) (X_AXIS_SIZE + 1);

    HashNode *xVar = getIdentifierNode(myHashTable, "x");
    xVar->valueId = h_view_lo;

    isPlot = 1;
    ResultExpression *result = NULL;
    for (int i = 0; i < X_AXIS_SIZE + 1; i++) {
        result = evalExpression(expr, myHashTable);
        if (!result) {
            printf("\n\n");
            return;
        }
        float xValue = xVar->valueId;
        float yValue = result->r_float;
        insertPoint(i, xValue, yValue, h_view_lo, h_view_hi, v_view_lo, v_view_hi);
        xVar->valueId += xStep;
    }
    isPlot = 0;
    if (result) drawAxis(draw_axis);
}

void swap(float *a, float *b) {
    float aux = *a;
    *a = *b;
    *b = aux;
}

float gaussDeterminant(float **a, int line) {
    int i, j, j1, j2;
    float det = 1;
    float temp[line][line];

    // copy matrix
    for (i = 0; i < line; i++)
        for (j = 0; j < line; j++)
            temp[i][j] = a[i][j];

    // pivoting
    for (j = 0; j < line; j++) {
        if (temp[j][j] == 0) {  // if pivot is zero

            // basically trying to turn it into a upper triangular matrix
            for (i = j + 1; i < line; i++)  // find non-zero element in the same column below and swaps the rows
                if (temp[i][j] != 0)
                    break;

            if (i == line)  // if no non-zero element is found, determinant is zero
                return 0;

            for (j1 = j; j1 < line; j1++)
                swap(&temp[j][j1], &temp[i][j1]);
            det *= -1;  // if row was swapped, multiply determinant by -1
        }

        det *= temp[j][j];

        // subtracting multiples of the pivot row from all the rows below it to create zeros below the diagonal
        for (i = j + 1; i < line; i++) {
            for (j1 = line - 1; j1 >= j; j1--)
                temp[i][j1] -= temp[j][j1] * temp[i][j] / temp[j][j];
        }
    }
    return det;
}

float *gaussLinearSystem(float **m, int line) {
    // copy matrix so main matrix is not changed
    float a[line][line + 1];
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < line + 1; j++) {
            a[i][j] = m[i][j];
        }
    }

    // triangularization
    for (int i = 0; i < line - 1; i++) {
        for (int j = i + 1; j < line; j++) {
            
            // pivoting
            if (a[i][i] == 0) {
                for (int k = i + 1; k < line; k++) {
                    if (a[k][i] != 0) {
                        for (int l = i; l < line; l++) {
                            swap(&a[i][l], &a[k][l]);
                        }
                        break;
                    }
                }
            }

            float pivot = a[i][i];
            float m = a[j][i] / pivot;
            for (int k = 0; k < line + 1; k++) {
                a[j][k] = a[j][k] - m * a[i][k];
            }
        }
    }

    for (int i = 0; i < line; i++) {
        int j;
        for (j = 0; j < line; j++) {
            if (a[i][j] != 0)
                break;
        }
        // SI: if at any point of the triangularization, a line is all zeros except for the last element, 
        // the system has no solution eg: 0x + 0y + 0z = 1

        // SPI: if at any point of the triangularization, a line is all zeros except for the last element,
        // the system has infinitely many solutions eg: 0x + 0y + 0z = 0

        if (j == line && a[i][line] != 0) { //
            printf("\nSI - The Linear System has no solution\n\n");
            return NULL;
        } else if (j == line) {
            printf("\nSPI - The Linear System has infinitely many solutions\n\n");
            return NULL;
        }
    }

    // retrosubstitution
    float *x = calloc(line, sizeof(float));
    for (int i = line - 1; i >= 0; i--) {
        x[i] = a[i][line];
        for (int j = i + 1; j < line; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    return x;
}

void showAbout() {
    printf("\n+-------------------------------------------------------+\n");
    printf("|                                                       |\n");
    printf("|                     202100560105                      |\n");
    printf("|              Marco Tulio Alves de Barros              |\n");
    printf("|                                                       |\n");
    printf("+-------------------------------------------------------+\n\n");
}   

int main(int argc, char *argv[]) {
    myHashTable = createHash();
    printf(">");
    while (true) {
        if (yyparse() == QUIT || yychar == 0) break;
    }
    return 0;
}
