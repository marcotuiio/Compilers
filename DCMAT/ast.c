#include "ast.h"

#include "sintatico.tab.h"

extern int isPlot;
int isFunction = 0;

Expression *createExpression(int type, int op, char *s, Expression *left, Expression *right) {
    Expression *expr = calloc(1, sizeof(Expression));
    expr->type = type;
    expr->operator= op;
    expr->e_string = s;
    expr->left = left;
    expr->right = right;
    return expr;
}

ResultExpression *createResultExpression(int type, float r_float, char *r_string) {
    ResultExpression *result = calloc(1, sizeof(ResultExpression));
    result->type = type;
    result->r_float = r_float;
    result->r_string = r_string;
    return result;
}

Function *createFunction(int type, Expression *expression) {
    Function *function = calloc(1, sizeof(Function));
    function->type = type;
    function->expression = expression;
    return function;
}

ResultExpression *evalExpression(Expression *expr, void **hash) {
    if (!expr) return NULL;

    ResultExpression *left = NULL;
    ResultExpression *right = NULL;
    ResultExpression *result = NULL;

    HashNode *hashNode = NULL;

    int resultType = 0;
    switch (expr->type) {
        case PRIMARIA:
            if (expr->operator== ID) {
                hashNode = getIdentifierNode(hash, expr->e_string);
                // printf("\nID: %s %p", expr->e_string, hashNode);
                if (!hashNode) {
                    printf("\nUndefined symbol [%s]", expr->e_string);
                    return NULL;
                }
                result = createResultExpression(hashNode->typeVar, hashNode->valueId, NULL);
                if (hashNode->typeVar == MATRIX) {
                    result->matrix = hashNode->matrix;
                    result->line = hashNode->lineMatrix;
                    result->column = hashNode->columnMatrix;
                }

            } else if (expr->operator== NUM_INT) {
                result = createResultExpression(NUM_INT, atof(expr->e_string), NULL);

            } else if (expr->operator== NUM_FLOAT) {
                result = createResultExpression(NUM_FLOAT, atof(expr->e_string), NULL);

            } else if (expr->operator== VAR_X) {
                // if (!isFunction && !isPlot) {
                //     printf("\nThe x variable cannot be present on expressions.\n\n");
                //     return NULL;
                // }
                hashNode = getIdentifierNode(hash, "x");
                result = createResultExpression(NUM_FLOAT, hashNode->valueId, NULL);
                // printf("\nVAR_X %f\n", result->r_float);

            } else if (expr->operator== FUNCTION) {
                result = evalFunction(expr->func, hash);
            }

            return result;
            break;

        case ADITIVA:
            left = evalExpression(expr->left, hash);
            right = evalExpression(expr->right, hash);

            if (!left || !right) return NULL;

            if (left->type == MATRIX && right->type != MATRIX) {
                printf("\nIncorrect type for operator '%s' - have MATRIX and FLOAT", (expr->operator== PLUS) ? "+" : "-");
                return NULL;

            } else if (left->type != MATRIX && right->type == MATRIX) {
                printf("\nIncorrect type for operator '%s' - have FLOAT and MATRIX", (expr->operator== PLUS) ? "+" : "-");
                return NULL;

            } else if (left->type == MATRIX && right->type == MATRIX) {
                float **middleMatrix = sumMatrix(left->matrix, right->matrix, left->line, left->column, right->line, right->column, expr->operator, hash);
                if (!middleMatrix) return NULL;
                result = createResultExpression(MATRIX, 0, NULL);
                result->matrix = middleMatrix;
                result->line = left->line;
                result->column = left->column;
                return result;
            }

            resultType = NUM_INT;
            if (left->type == NUM_FLOAT || right->type == NUM_FLOAT) {
                resultType = NUM_FLOAT;
            }

            if (expr->operator== PLUS) {
                result = createResultExpression(resultType, left->r_float + right->r_float, NULL);

            } else if (expr->operator== MINUS) {
                result = createResultExpression(resultType, left->r_float - right->r_float, NULL);
            }
            return result;
            break;

        case MULTIPLICATIVA:
            left = evalExpression(expr->left, hash);
            right = evalExpression(expr->right, hash);

            if (!left || !right) return NULL;

            resultType = NUM_INT;
            if (left->type == NUM_FLOAT || right->type == NUM_FLOAT) {
                resultType = NUM_FLOAT;
            }

            if (expr->operator== MULTIPLY) {
                if (left->type == MATRIX && right->type == MATRIX) {
                    float **middleMatrix = multMatrix(left->matrix, right->matrix, left->line, left->column, right->line, right->column, hash);
                    if (!middleMatrix) return NULL;
                    result = createResultExpression(MATRIX, 0, NULL);
                    result->matrix = middleMatrix;
                    result->line = left->line;
                    result->column = right->column;
                    return result;

                } else if (left->type == MATRIX && right->type != MATRIX) {
                    float **middleMatrix = createMatrix();
                    for (int i = 0; i < left->line; i++) {
                        for (int j = 0; j < left->column; j++) {
                            middleMatrix[i][j] = left->matrix[i][j] * right->r_float;
                        }
                    }
                    result = createResultExpression(MATRIX, 0, NULL);
                    result->matrix = middleMatrix;
                    result->line = left->line;
                    result->column = left->column;
                    return result;

                } else if (left->type != MATRIX && right->type == MATRIX) {
                    float **middleMatrix = createMatrix();
                    for (int i = 0; i < right->line; i++) {
                        for (int j = 0; j < right->column; j++) {
                            middleMatrix[i][j] = right->matrix[i][j] * left->r_float;
                        }
                    }
                    result = createResultExpression(MATRIX, 0, NULL);
                    result->matrix = middleMatrix;
                    result->line = right->line;
                    result->column = right->column;
                    return result;
                }

                result = createResultExpression(resultType, left->r_float * right->r_float, NULL);

            } else if (expr->operator== DIVIDE) {
                if (right->r_float == 0) {
                    // result = createResultExpression(ID, 0, "inf");
                    printf("\ninf");
                    return NULL;

                } else {
                    if ((int)left->r_float % (int)right->r_float != 0) resultType = NUM_FLOAT;
                    result = createResultExpression(resultType, left->r_float / right->r_float, NULL);
                }

            } else if (expr->operator== REMAINDER && resultType == NUM_INT) {
                result = createResultExpression(NUM_INT, (int)left->r_float % (int)right->r_float, NULL);

            } else if (expr->operator== POWER) {
                result = createResultExpression(resultType, pow(left->r_float, right->r_float), NULL);
            }

            return result;
            break;

        case UNARIA:
            left = evalExpression(expr->left, hash);

            if (!left) return NULL;

            if (expr->operator== PLUS) {
                result = createResultExpression(left->type, +left->r_float, NULL);

            } else if (expr->operator== MINUS) {
                if (left->type == MATRIX) {
                    float **middleMatrix = createMatrix();
                    for (int i = 0; i < left->line; i++) {
                        for (int j = 0; j < left->column; j++) {
                            middleMatrix[i][j] = -left->matrix[i][j];
                        }
                    }
                    result = createResultExpression(MATRIX, 0, NULL);
                    result->matrix = middleMatrix;
                    result->line = left->line;
                    result->column = left->column;

                } else {
                    result = createResultExpression(left->type, -left->r_float, NULL);
                }
            }

            return result;
            break;

        default:
            printf("Erro ao avaliar expressao\n");
            break;
    }
    return NULL;
}

ResultExpression *evalFunction(Function *func, void **hash) {
    if (!func) return NULL;
    isFunction = 1;
    ResultExpression *expr = evalExpression(func->expression, hash);
    // printf("evalFunc %f\n", expr->r_float);
    if (!expr) return NULL;

    if (expr->type == MATRIX) {
        printf("\nIncorrect type for operator '%s' - have MATRIX",
               (func->type == SEN) ? "SEN" : (func->type == COS) ? "COS"
                                         : (func->type == TAN)   ? "TAN"
                                                                 : "ABS");
        return NULL;
    }

    switch (func->type) {
        case SEN:
            isFunction = 0;
            return createResultExpression(NUM_FLOAT, sin(expr->r_float), NULL);
            break;
        case COS:
            isFunction = 0;
            return createResultExpression(NUM_FLOAT, cos(expr->r_float), NULL);
            break;
        case TAN:
            isFunction = 0;
            return createResultExpression(NUM_FLOAT, tan(expr->r_float), NULL);
            break;
        case ABS:
            isFunction = 0;
            return createResultExpression(NUM_FLOAT, fabs(expr->r_float), NULL);
            break;
        default:
            isFunction = 0;
            printf("Erro ao avaliar funcao\n");
            break;
    }
    return NULL;
}

float **sumMatrix(float **a, float **b, int aLin, int aCol, int bLin, int bCol, int op, void **hash) {
    if (!a || !b) return NULL;
    if (aLin != bLin || aCol != bCol) {
        printf("\nIncorrect dimensions for operator '%s' - have MATRIX [%d][%d] and MATRIX [%d][%d]",
               (op == PLUS) ? "+" : "-", aLin, aCol, bLin, bCol);
        return NULL;
    }

    float **m = createMatrix();
    for (int i = 0; i < aLin; i++) {
        for (int j = 0; j < aCol; j++) {
            if (op == PLUS) {
                m[i][j] = a[i][j] + b[i][j];
            } else {
                m[i][j] = a[i][j] - b[i][j];
            }
        }
    }
    return m;
}

// CURIOSIDADES INUTEIS!!!
// codigo historico diretamente das aulas de algoritmo com sakuray no 1º semestre
// aqui esta adaptado, mas foi o primeiro codigo que fiz e fique orgulhoso dele
float **multMatrix(float **a, float **b, int aLin, int aCol, int bLin, int bCol, void **hash) {
    if (!a || !b) return NULL;

    if (aCol != bLin) {
        printf("\nIncorrect dimensions for operator '*' - have MATRIX [%d][%d] and MATRIX [%d][%d]", aLin, aCol, bLin, bCol);
        return NULL;
    }

    float **m = createMatrix();
    float soma = 0;

    for (int j = 0; j < aLin; j++) {          // j controla linha da matriz produto C e linha de A
        for (int n = 0; n < bCol; n++) {      // n controla coluna da matriz produto C e coluna de B
            for (int i = 0; i < aCol; i++) {  // i controla colunas da matriz A e linhas da matriz B
                soma = soma + a[j][i] * b[i][n];
            }
            m[j][n] = soma;
            soma = 0;
        }
    }
    return m;
}
