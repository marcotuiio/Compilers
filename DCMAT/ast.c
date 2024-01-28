#include "ast.h"

#include "sintatico.tab.h"

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
                if (!hashNode) {
                    printf("\nUndefined symbol [%s]", expr->e_string);
                    return NULL;
                }
                result = createResultExpression(hashNode->typeVar, hashNode->valueId, NULL);  // preciso arrumar

            } else if (expr->operator== NUM_INT) {
                result = createResultExpression(NUM_INT, atof(expr->e_string), NULL);

            } else if (expr->operator== NUM_FLOAT) {
                result = createResultExpression(NUM_FLOAT, atof(expr->e_string), NULL);

            } else if (expr->operator== VAR_X) {
                if (!isFunction) {
                    printf("\nThe x variable cannot be present on expressions.");
                    return NULL;
                }
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

            resultType = NUM_INT;
            if (left->type == NUM_FLOAT || right->type == NUM_FLOAT) {
                resultType = NUM_FLOAT;
            }

            // check if theres no matrix + int or float

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
                result = createResultExpression(resultType, left->r_float * right->r_float, NULL);

            } else if (expr->operator== DIVIDE) {
                if (right->r_float == 0) {
                    result = createResultExpression(ID, 0, "inf");
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
                result = createResultExpression(left->type, -left->r_float, NULL);
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