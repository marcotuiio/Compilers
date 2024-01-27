#include "ast.h"

#include "sintatico.tab.h"

Expression *createExpression(int type, int op, char *s, Expression *left, Expression *right) {
    Expression *expr = calloc(1, sizeof(Expression));
    expr->type = type;
    expr->operator = op;
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

ResultExpression *evalExpression(Expression *expr, void **hash) {
    if (!expr) return NULL;
    
    ResultExpression *left = NULL;
    ResultExpression *right = NULL;
    ResultExpression *result = NULL;

    HashNode *hashNode = NULL;

    int resultType = 0;

    switch (expr->type) {
        case PRIMARIA:
            if (expr->operator == ID) {
                hashNode = getIdentifierNode(hash, expr->e_string);
                if (!hashNode) {
                    printf("Erro: variavel %s nao declarada\n", expr->e_string);
                    return NULL;
                }
                result = createResultExpression(hashNode->typeVar, 0, NULL); //preciso arrumar

            } else if (expr->operator == NUM_INT) {
                result = createResultExpression(NUM_INT, atof(expr->e_string), NULL);
            
            } else if (expr->operator == NUM_FLOAT) {
                result = createResultExpression(NUM_FLOAT, atof(expr->e_string), NULL);
            }

            return result;
            break;

        case ADITIVA:
            left = evalExpression(expr->left, hash);
            right = evalExpression(expr->right, hash);

            resultType = NUM_INT;
            if (left->type == NUM_FLOAT || right->type == NUM_FLOAT) {
                resultType = NUM_FLOAT;
            }

            // check if theres no matrix + int or float

            if (expr->operator == PLUS) {
                result = createResultExpression(resultType, left->r_float + right->r_float, NULL);

            } else if (expr->operator == MINUS) {
                result = createResultExpression(resultType, left->r_float - right->r_float, NULL);
            }
            return result;
            break;

        case MULTIPLICATIVA:
            left = evalExpression(expr->left, hash);
            right = evalExpression(expr->right, hash);

            resultType = NUM_INT;
            if (left->type == NUM_FLOAT || right->type == NUM_FLOAT) {
                resultType = NUM_FLOAT;
            }

            if (expr->operator == MULTIPLY) {
                result = createResultExpression(resultType, left->r_float * right->r_float, NULL);
            
            } else if (expr->operator == DIVIDE) {
                if (right->r_float == 0) {
                    printf("Erro: divisao por zero\n");
                    return NULL;
                }
                if ((int) left->r_float % (int) right->r_float != 0) resultType = NUM_FLOAT;
                result = createResultExpression(resultType, left->r_float / right->r_float, NULL);
            
            } else if (expr->operator == REMAINDER && resultType == NUM_INT) {
                result = createResultExpression(NUM_INT, (int) left->r_float % (int) right->r_float, NULL);

            } else if (expr->operator == POWER) {
                result = createResultExpression(resultType, pow(left->r_float, right->r_float), NULL);
            }

            return result;
            break;

        case UNARIA:
            left = evalExpression(expr->left, hash);

            if (expr->operator == PLUS) {
                result = createResultExpression(left->type, +left->r_float, NULL);
            
            } else if (expr->operator == MINUS) {
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