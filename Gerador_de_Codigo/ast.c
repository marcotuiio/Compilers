#include "ast.h"
#include "asm.h"
#include "hash.h"
#include "sintatico.tab.h"

extern FILE *mipsFile;

int functionWithNoReturn = 0;
extern void printLineError(int line, int column);
extern void deleteAuxFile();
extern int textBefore;
extern int defineAux;
extern int dimensionAux;
int teveReturn = 0;

void *last = NULL;

Program *createProgram(void **hash, void *functionsList, void *main) {
    Program *newProg = calloc(1, sizeof(Program));
    newProg->hashTable = hash;
    newProg->functionsList = functionsList;
    newProg->main = main;
    return newProg;
}

Function *createFunction(void **hash, int returnType, int pointer, char *name, void *commandList, void *next) {
    Function *newFunc = calloc(1, sizeof(Function));
    newFunc->hashTable = hash;
    newFunc->returnType = returnType;
    newFunc->pointer = pointer;
    newFunc->name = name;
    newFunc->commandList = commandList;
    newFunc->next = next;
    return newFunc;
}

AuxToken *createAuxToken(char *valor, int line, int column, int type) {
    AuxToken *newAux = calloc(1, sizeof(AuxToken));
    newAux->valor = calloc(strlen(valor) + 1, sizeof(char));
    newAux->valor = valor;
    newAux->line = line;
    newAux->column = column;
    newAux->type = type;
    return newAux;
}

ExpParam *createExpParam(Expression *exp, ExpParam *next) {
    ExpParam *newExpParam = calloc(1, sizeof(ExpParam));
    newExpParam->exp = exp;
    newExpParam->next = next;
    return newExpParam;
}

Expression *createExpression(int type, int operator, void * value, void *left, void *right) {
    Expression *newExp = calloc(1, sizeof(Expression));
    newExp->type = type;
    newExp->operator= operator;
    newExp->value = value;
    newExp->left = left;
    newExp->right = right;
    newExp->dimension = NULL;
    newExp->ternary = NULL;
    return newExp;
}

Dimension *createDimension(int size) {
    Dimension *newDim = calloc(1, sizeof(Dimension));
    newDim->size = size;
    return newDim;
}

int countDimension(void *d) {
    Dimension *dimen = d;
    if (!dimen) return 0;
    int count = 1;
    Dimension *aux = dimen;
    while (aux->next) {
        count++;
        aux = aux->next;
    }
    return count;
}

Dimension *createDimensionWithExp(Expression *exp, AuxToken *auxToken) {
    Dimension *newDim = calloc(1, sizeof(Dimension));
    newDim->exp = exp;
    newDim->dimenAuxToken = auxToken;
    return newDim;
}

void setDimensionExpression(Expression *expression, Dimension *dimension) {
    if (!expression) return;
    if (!expression->dimension) {
        expression->dimension = dimension;
    } else {
        Dimension *aux = expression->dimension;
        while (aux->next) aux = aux->next;
        aux->next = dimension;
    }
}

Command *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next) {
    Command *newIf = calloc(1, sizeof(Command));
    newIf->type = IF;
    newIf->condition = condition;
    newIf->then = then;
    newIf->elseStatement = elseStatement;
    newIf->next = next;
    return newIf;
}

Command *createElseStatement(void *then, void *next) {
    Command *newElse = calloc(1, sizeof(Command));
    newElse->type = ELSE;
    newElse->then = then;
    newElse->next = next;
    return newElse;
}

Command *createDoWhileStatement(Expression *condition, void *then, void *next) {
    Command *newDoWhile = calloc(1, sizeof(Command));
    newDoWhile->type = DO;
    newDoWhile->condition = condition;
    newDoWhile->then = then;
    newDoWhile->next = next;
    return newDoWhile;
}

Command *createWhileStatement(Expression *condition, void *then, void *next) {
    Command *newWhile = calloc(1, sizeof(Command));
    newWhile->type = WHILE;
    newWhile->condition = condition;
    newWhile->then = then;
    newWhile->next = next;
    return newWhile;
}

Command *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next) {
    Command *newFor = calloc(1, sizeof(Command));
    newFor->type = FOR;
    newFor->init = init;
    newFor->condition = condition;
    newFor->increment = increment;
    newFor->then = then;
    newFor->next = next;
    return newFor;
}

Command *createPrintStatement(char *string, Expression *auxPrint, void *next) {
    Command *newPrint = calloc(1, sizeof(Command));
    newPrint->type = PRINTF;
    newPrint->string = string;
    newPrint->auxPrint = auxPrint;
    newPrint->next = next;
    return newPrint;
}

Command *createScanStatement(char *string, char *identifier, char *format, void *next) {
    Command *newScan = calloc(1, sizeof(Command));
    newScan->type = SCANF;
    newScan->string = string;
    newScan->identifier = identifier;
    newScan->format = format;
    newScan->next = next;
    return newScan;
}

Command *createReturnStatement(Expression *expression, void *next) {
    Command *newReturn = calloc(1, sizeof(Command));
    newReturn->type = RETURN;
    newReturn->condition = expression;
    newReturn->next = next;
    return newReturn;
}

Command *createExitStatement(Expression *expression, void *next) {
    Command *newExit = calloc(1, sizeof(Command));
    newExit->type = EXIT;
    newExit->condition = expression;
    newExit->next = next;
    return newExit;
}

Command *createCommandExpression(Expression *expression, void *next) {
    Command *newCommand = calloc(1, sizeof(Command));
    newCommand->type = LISTA_EXP_COMANDO;
    newCommand->condition = expression;
    newCommand->next = next;
    // printf("commandExpression %p %p\n", expression, newCommand);
    return newCommand;
}

ResultExpression *createResultExpression(int type, int pointer, int value) {
    ResultExpression *newResult = calloc(1, sizeof(ResultExpression));
    newResult->typeVar = type;
    newResult->pointer = pointer;
    newResult->assign = value;
    return newResult;
}

ResultExpression *evalExpression(Expression *expr, void **globalHash, void **localHash, Program *program) {
    if (!expr) return NULL;

    ResultExpression *left = NULL;
    ResultExpression *right = NULL;
    ResultExpression *result = NULL;

    HashNode *hashNode = NULL;

    int auxLeftPointer, auxRightPointer;
    int auxLeftType, auxRightType;
    int auxLeftValor, auxRightValor;

    // printf("evalExpression %p %d %d %d\n", expr, expr->type, expr->operator, expr->value->type);

    switch (expr->type) {
        case NUMEROS:
            if (expr->value->type == NUM_INT) {
                result = createResultExpression(expr->value->type, expr->value->pointer, atoi(expr->value->valor));
                return result;
            }
            printf("Numero que nao e int\n");
            break;

        case PRIMARIA:
            if (expr->operator== ID) {
                hashNode = getIdentifierNode(localHash, expr->value->valor);
                if (!hashNode) hashNode = getIdentifierNode(globalHash, expr->value->valor);
                if (!hashNode) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->value->valor);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                if (!hashNode->isConstant && (defineAux || dimensionAux)) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' initializer element is not constant", expr->value->line, expr->value->column, expr->value->valor);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                // printf("Achei %p %s %d %d (kind = %d) = %d\n", hashNode, hashNode->varId, hashNode->typeVar, hashNode->pointer, hashNode->kind, hashNode->assign);

                if (hashNode->typeVar == VOID) {
                    // if (textBefore) printf("\n");
                    // printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                    // printLineError(expr->value->line, expr->value->column);
                    // freeAST(program);
                    // deleteAuxFile();
                    // exit(0);
                    result = createResultExpression(VOID, hashNode->pointer, hashNode->assign);
                    if (hashNode->kind == VECTOR) result->pointer = 1;
                    result->auxIdNode = hashNode;
                    return result;
                } else if (hashNode->typeVar == NUM_INT || hashNode->typeVar == INT) {
                    result = createResultExpression(hashNode->typeVar, hashNode->pointer, hashNode->assign);
                    if (hashNode->kind == VECTOR) result->pointer = 1;
                    result->auxIdNode = hashNode;
                    return result;
                } else if (hashNode->typeVar == CHARACTER || hashNode->typeVar == CHAR) {
                    result = createResultExpression(hashNode->typeVar, hashNode->pointer, hashNode->assign);
                    if (hashNode->kind == VECTOR) result->pointer = 1;
                    result->auxIdNode = hashNode;
                    return result;
                } else if (hashNode->typeVar == STRING) {
                    result = createResultExpression(CHAR, 1, 0);
                    result->auxIdNode = hashNode;
                    return result;
                }

            } else if (expr->operator== CHARACTER) {
                result = createResultExpression(expr->value->type, expr->value->pointer, expr->value->valor[0]);
                return result;

            } else if (expr->operator== STRING) {
                result = createResultExpression(STRING, 0, 0);
                return result;
            }
            break;

        case ATRIBUICAO:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("assign left %p %d %d \nright %p %d %d \n", left, left->typeVar, left->pointer, right, right->typeVar, right->pointer);

            if ((left->typeVar == VOID && left->pointer == 0) || (right->typeVar == VOID && right->pointer == 0)) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            // atribuindo para constante
            if (left->typeVar == STRING || left->typeVar == CHARACTER) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: assignment of read-only location %s", expr->value->line, expr->value->column, expr->left->value->valor);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            // atribuindo sem ser id
            if (expr->left->value->type != ID) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: lvalue required as left operand of assignment", expr->value->line, expr->value->column);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT)
                    auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER)
                    auxLeftType = CHARACTER;
                else if (left->typeVar == VOID)
                    auxLeftType = VOID;
                auxLeftPointer = left->pointer;
                if (left->typeVar == STRING) {
                    auxLeftType = CHARACTER;
                    auxLeftPointer = 1;
                }
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                else if (right->typeVar == VOID)
                    auxRightType = VOID;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign;
            }

            if (expr->operator== ASSIGN) {
                if (right) {
                    if (auxLeftPointer != 0 || auxRightPointer != 0) {  // existem pointers envolvidos
                        // se forem de tipo diferente ou ponteiro diferente
                        if (auxLeftType != auxRightType || auxLeftPointer != auxRightPointer) {
                            if (textBefore) printf("\n");
                            char *type1 = getExactType(auxLeftType, auxLeftPointer);
                            char *type2 = getExactType(auxRightType, auxRightPointer);
                            printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
                            free(type1);
                            free(type2);
                            printLineError(expr->value->line, expr->value->column);
                            freeAST(program);
                            deleteAuxFile();
                            exit(0);
                        }
                    }

                } else {
                    if (auxLeftPointer != 0 || auxRightPointer != 0) {  // existem pointers envolvidos
                        // se forem de tipo diferente ou ponteiro diferente
                        if (auxLeftType != auxRightType || auxLeftPointer != auxRightPointer) {
                            if (textBefore) printf("\n");
                            char *type1 = getExactType(auxLeftType, auxLeftPointer);
                            char *type2 = getExactType(auxRightType, auxRightPointer);
                            printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
                            free(type1);
                            free(type2);
                            printLineError(expr->value->line, expr->value->column);
                            freeAST(program);
                            deleteAuxFile();
                            exit(0);
                        }
                    }
                }
                result = createResultExpression(auxLeftType, auxLeftPointer, auxRightValor);

            } else if (expr->operator== ADD_ASSIGN || expr->operator== MINUS_ASSIGN) {
                if (right) {
                    if (auxLeftPointer != 0) {
                        if (auxRightType != NUM_INT || auxRightType != CHARACTER) {
                            if (textBefore) printf("\n");
                            char *type1 = getExactType(left->typeVar, left->pointer);
                            char *type2 = getExactType(right->typeVar, right->pointer);
                            printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
                            free(type1);
                            free(type2);
                            printLineError(expr->value->line, expr->value->column);
                            freeAST(program);
                            deleteAuxFile();
                            exit(0);
                        }
                    }
                } else {
                    if (auxLeftPointer != 0) {
                        if (auxRightType != NUM_INT || auxRightType != CHARACTER) {
                            if (textBefore) printf("\n");
                            char *type1 = getExactType(auxLeftType, auxLeftPointer);
                            char *type2 = getExactType(auxRightType, auxRightPointer);
                            printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
                            free(type1);
                            free(type2);
                            printLineError(expr->value->line, expr->value->column);
                            freeAST(program);
                            deleteAuxFile();
                            exit(0);
                        }
                    }
                }

                if (expr->operator== ADD_ASSIGN)
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
                else if (expr->operator== MINUS_ASSIGN)
                    result = createResultExpression(left->typeVar, left->pointer, auxLeftValor - auxRightValor);
            }
            HashNode *hashNodeTemp = getIdentifierNode(localHash, expr->left->value->valor);
            if (!hashNodeTemp) hashNodeTemp = getIdentifierNode(globalHash, expr->left->value->valor);
            if (hashNodeTemp) setAssign(hashNodeTemp, result->assign);
            hashNodeTemp = NULL;

            result->auxLine = expr->value->line;
            result->auxColumn = expr->value->column;
            fprintf(mipsFile, "\t# assignment na ast\n");
            printAssignment(mipsFile, result->assign);
            return result;
            break;

        case LISTA_EXP:  // nao sei fazer ainda
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("left %p %d %d \nright %p %d %d \n", left, left->typeVar, left->pointer, right, right->typeVar, right->pointer);
            if (left) {
                // printf("left %d %d\n", left->typeVar, left->assign);
            }
            if (right) {
                // printf("right %d %d\n", right->typeVar, right->assign);
            }

            break;

        case TERNARY:
            ResultExpression *condition = evalExpression(expr->ternary, globalHash, localHash, program);
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            // auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT)
                    auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER)
                    auxLeftType = CHARACTER;
                else if (left->typeVar == VOID)
                    auxLeftType = VOID;
                auxLeftPointer = left->pointer;
                if (left->typeVar == STRING) {
                    auxLeftType = CHARACTER;
                    auxLeftPointer = 1;
                }
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            // auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                else if (right->typeVar == VOID)
                    auxRightType = VOID;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign;
            }
            if (auxLeftType != auxRightType || auxLeftPointer != auxRightPointer) {
                if (textBefore) printf("\n");
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                printf("warning:%d:%d: '%s'/'%s' type mismatch in conditional expression", expr->value->line, expr->value->column, type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                textBefore = 1;
            }

            if (condition->assign)
                result = createResultExpression(auxLeftType, auxLeftPointer, left->assign);
            else
                result = createResultExpression(auxRightType, auxRightPointer, right->assign);
            result->auxLine = expr->value->line;
            result->auxColumn = expr->value->column;
            return result;

        case OR_LOGICO:
        case AND_LOGICO:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT)
                    auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER)
                    auxLeftType = CHARACTER;
                auxLeftPointer = left->pointer;
                if (left->typeVar == STRING) {
                    auxLeftType = CHARACTER;
                    auxLeftPointer = 1;
                }
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign;
            }
            if (expr->type == OR_LOGICO) result = createResultExpression(INT, 0, auxLeftValor || auxRightValor);
            // else if (expr->type == AND_LOGICO) result = createResultExpression(INT, 0, auxLeftValor && auxRightValor);
            result->auxLine = expr->value->line;
            result->auxColumn = expr->value->column;
            return result;

        case RELACIONAL:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT)
                    auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER)
                    auxLeftType = CHARACTER;
                else if (left->typeVar == VOID)
                    auxLeftType = VOID;
                auxLeftPointer = left->pointer;
                if (left->typeVar == STRING) {
                    auxLeftType = CHARACTER;
                    auxLeftPointer = 1;
                }
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                else if (right->typeVar == VOID)
                    auxRightType = VOID;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign;
            }

            // ponteiro com int ou char gera warning
            // ponteiro com ponteiro diferente gera erro
            if ((auxLeftPointer == 0 && auxRightPointer != 0) || (auxLeftPointer != 0 && auxRightPointer == 0)) {
                if (textBefore) printf("\n");
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                printf("warning:%d:%d: comparison between '%s' and '%s' operator '%s'", expr->value->line, expr->value->column, type1, type2, expr->value->valor);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                textBefore = 1;

                // comparacao entre ponteiros de tipos diferentes
            } else if (auxLeftType != auxRightType) {
                // printf("\nauxLeftType %d  %d auxRightType %d  %d\n", auxLeftType, auxLeftPointer, auxRightType, auxRightPointer);
                // exit(0);
                if (textBefore) printf("\n");
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                printf("error:semantic:%d:%d: comparison between '%s' and '%s' operator '%s'", expr->value->line, expr->value->column, type1, type2, expr->value->valor);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }
            if (expr->operator== LESS_THAN) {
                result = createResultExpression(INT, 0, left->assign < right->assign);
            } else if (expr->operator== GREATER_THAN) {
                result = createResultExpression(INT, 0, left->assign > right->assign);
            } else if (expr->operator== LESS_EQUAL) {
                result = createResultExpression(INT, 0, left->assign <= right->assign);
            } else if (expr->operator== GREATER_EQUAL) {
                result = createResultExpression(INT, 0, left->assign >= right->assign);
            } else if (expr->operator== EQUAL) {
                result = createResultExpression(INT, 0, left->assign == right->assign);
            } else if (expr->operator== NOT_EQUAL) {
                result = createResultExpression(INT, 0, left->assign != right->assign);
            }
            result->auxLine = expr->value->line;
            result->auxColumn = expr->value->column;
            return result;

        case SHIFT:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

            if (left->typeVar == VOID || right->typeVar == VOID) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }
            int leftBits = 0;

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT) {
                    auxLeftType = NUM_INT;
                    leftBits = 32;
                } else if (left->typeVar == CHAR || left->typeVar == CHARACTER) {
                    auxLeftType = CHARACTER;
                    leftBits = 8;
                }
                auxLeftPointer = left->pointer;
                if (left->typeVar == STRING) {
                    auxLeftType = CHARACTER;
                    auxLeftPointer = 1;
                }
                if (auxLeftPointer > 0) leftBits = 32;
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign;
            }

            if (auxRightPointer != 0) {
                if (textBefore) printf("\n");
                char t[5];
                if (expr->operator== R_SHIFT)
                    strcpy(t, ">>");
                else if (expr->operator== L_SHIFT)
                    strcpy(t, "<<");
                char *type2 = getExactType(auxRightType, auxRightPointer);
                printf("error:semantic:%d:%d: cannot convert from '%s' to int", expr->value->line, expr->value->column, type2);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            if (auxRightValor < 0) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: %s shift count is negative", expr->value->line, expr->value->column, expr->operator== R_SHIFT ? "right" : "left");
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            // verificar se o valor da direita é maior que o tamanho do tipo da esquerda
            if (auxRightValor >= leftBits) {
                if (textBefore) printf("\n");
                printf("warning:%d:%d: %s shift count >= width of type", expr->value->line, expr->value->column, expr->operator== R_SHIFT ? "right" : "left");
                printLineError(expr->value->line, expr->value->column);
                textBefore = 1;
            }
            if (expr->operator== R_SHIFT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor >> auxRightValor);
            } else if (expr->operator== L_SHIFT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor << auxRightValor);
            }
            result->auxLine = expr->value->line;
            result->auxColumn = expr->value->column;
            return result;

        case ADITIVIVA:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

            // if (left->typeVar == VOID || right->typeVar == VOID) {
            //     if (textBefore) printf("\n");
            //     printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
            //     printLineError(expr->value->line, expr->value->column);
            //     freeAST(program);
            //     deleteAuxFile();
            //     exit(0);
            // }

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT)
                    auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER)
                    auxLeftType = CHARACTER;
                auxLeftPointer = left->pointer;
                if (left->typeVar == STRING) {
                    auxLeftType = CHARACTER;
                    auxLeftPointer = 1;
                }
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign;
            }
            // printf("\naditivia left %d %d \naditiva right %d %d\n", auxLeftType, auxLeftPointer, auxRightType, auxRightPointer);
            // se sao dois pointers nao pode
            if (auxLeftPointer != 0 && auxRightPointer != 0) {  // ALERTA MUDEI
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator== PLUS ? "+" : "-", type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            if (expr->operator== PLUS) {
                // pode somar pointer e char ou int
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
                result->auxLine = expr->value->line;
                result->auxColumn = expr->value->column;
                printAddition(mipsFile, auxLeftValor, auxRightValor);
                return result;

            } else if (expr->operator== MINUS) {
                if (auxRightPointer != 0) {
                    char *type1 = getExactType(auxLeftType, auxLeftPointer);
                    char *type2 = getExactType(auxRightType, auxRightPointer);
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator== PLUS ? "+" : "-", type1, type2);
                    free(type1);
                    free(type2);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor - auxRightValor);
                result->auxLine = expr->value->line;
                result->auxColumn = expr->value->column;
                printSubtraction(mipsFile, auxLeftValor, auxRightValor);
                return result;
            }
            break;

        case MULTIPLICATIVA:
        case OR_BIT:
        case XOR_BIT:
        case AND_BIT:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

            // if (left->typeVar == VOID || right->typeVar == VOID) {
            //     if (textBefore) printf("\n");
            //     printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
            //     printLineError(expr->value->line, expr->value->column);
            //     freeAST(program);
            //     deleteAuxFile();
            //     exit(0);
            // }

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT)
                    auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER)
                    auxLeftType = CHARACTER;
                auxLeftPointer = left->pointer;
                if (left->typeVar == STRING) {
                    auxLeftType = CHARACTER;
                    auxLeftPointer = 1;
                }
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign;
            }

            if (auxLeftPointer == 0 && auxRightPointer == 0 &&
                (auxLeftType == NUM_INT || auxLeftType == CHARACTER) && (auxRightType == NUM_INT || auxRightType == CHARACTER)) {
                // printf("certo!\n");
            } else {
                char c;
                if (expr->operator== MULTIPLY)
                    c = '*';
                else if (expr->operator== DIVIDE)
                    c = '/';
                else if (expr->operator== REMAINDER)
                    c = '%';
                else if (expr->operator== OR_BIT)
                    c = '|';
                else if (expr->operator== XOR_BIT)
                    c = '^';
                else if (expr->operator== AND_BIT)
                    c = '&';
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: invalid operands to binary '%c' (have '%s' and '%s')", expr->value->line, expr->value->column, c, type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            if (expr->operator== MULTIPLY) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor * auxRightValor);
            } else if (expr->operator== DIVIDE) {
                if (right->assign == 0 || auxRightValor == 0) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: division by zero", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor / auxRightValor);
            } else if (expr->operator== REMAINDER) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor % auxRightValor);
            } else if (expr->operator== OR_BIT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor | auxRightValor);
            } else if (expr->operator== XOR_BIT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor ^ auxRightValor);
            } else if (expr->operator== AND_BIT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor & auxRightValor);
            }
            result->auxLine = expr->value->line;
            result->auxColumn = expr->value->column;
            return result;
            break;

        case CASTING:
            right = evalExpression(expr->right, globalHash, localHash, program);

            if (right->typeVar == STRING) {
                right->typeVar = CHAR;
                right->pointer = 1;
            }

            if (right->typeVar == VOID && expr->value->type != VOID && right->pointer == 0) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            // para serem de tamanhos diferentes deve:
            // a) na direita ter um int e na esquerda um char sem ponteiro (8) 32
            // b) na direita ter um char* e na esquerda um char sem ponteiro (8) 32
            // c) na direita ter um int* e na esquerda um char sem ponteiro (8) 32

            auxLeftPointer = expr->value->pointer;
            if (expr->value->type == INT || expr->value->type == NUM_INT)
                auxLeftType = NUM_INT;
            else if (expr->value->type == CHAR || expr->value->type == CHARACTER)
                auxLeftType = CHARACTER;
            else if (expr->value->type == VOID)
                auxLeftType = VOID;
            if (right) {
                auxRightPointer = right->pointer;
                if (right->typeVar == INT || right->typeVar == NUM_INT)
                    auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
                    auxRightType = CHARACTER;
                else if (right->typeVar == VOID)
                    auxRightType = VOID;
                HashNode *temp = right->auxIdNode;
                if (temp) {
                    if (temp->kind == VECTOR)
                        auxRightPointer = 1;
                }
            }

            int auxLeftSize = 0;
            int auxRightSize = 0;

            if (auxLeftType == NUM_INT)
                auxLeftSize = 32;
            else if (auxLeftType == CHARACTER)
                auxLeftSize = 8;
            else if (auxLeftType == VOID)
                auxLeftSize = 8;

            if (auxRightType == NUM_INT)
                auxRightSize = 32;
            else if (auxRightType == CHARACTER)
                auxRightSize = 8;
            else if (auxRightType == VOID)
                auxRightSize = 8;

            if (auxLeftPointer != 0) auxLeftSize = 32;
            if (auxRightPointer != 0) auxRightSize = 32;

            if (auxLeftSize < auxRightSize) {
                // printf("\ncasting %d %d %d %d %d\n", expr->value->line, auxLeftType, auxLeftPointer, auxRightType, auxRightPointer);
                if (textBefore) printf("\n");
                char *type1 = getExactType(auxRightType, auxRightPointer);
                char *type2 = getExactType(auxLeftType, auxLeftPointer);
                printf("warning:%d:%d: cast from '%s' to '%s' of different size", expr->value->line, expr->value->column, type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                textBefore = 1;
            }
            result = createResultExpression(auxLeftType, auxLeftPointer, right->assign);
            result->auxLine = expr->value->line;
            result->auxColumn = expr->value->column;
            return result;

        case UNARIA:
            left = evalExpression(expr->left, globalHash, localHash, program);

            // if (left->typeVar == VOID) {
            //     if (textBefore) printf("\n");
            //     printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
            //     printLineError(expr->value->line, expr->value->column);
            //     freeAST(program);
            //     deleteAuxFile();
            //     exit(0);
            // }

            if (expr->operator== PLUS || expr->operator== MINUS || expr->operator== BITWISE_NOT) {
                if ((left->typeVar == NUM_INT || left->typeVar != CHARACTER || left->typeVar != INT || left->typeVar != CHAR)) {
                    if (left->pointer != 0 && expr->operator!= BITWISE_NOT) {
                        if (textBefore) printf("\n");
                        printf("error:semantic:%d:%d: wrong type argument to unary %s", expr->value->line, expr->value->column, expr->operator== PLUS ? "plus" : "minus");
                        printLineError(expr->value->line, expr->value->column);
                        freeAST(program);
                        deleteAuxFile();
                        exit(0);
                    }
                }

                if (left->typeVar != NUM_INT && left->typeVar && CHARACTER && left->typeVar != INT && left->typeVar != CHAR && (left->typeVar != VOID && left->pointer == 0)) {
                    char c;
                    if (expr->operator== PLUS)
                        c = '+';
                    else if (expr->operator== MINUS)
                        c = '-';
                    else if (expr->operator== BITWISE_NOT)
                        c = '~';
                    char *type1 = getExactType(left->typeVar, left->pointer);

                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: invalid type argument of unary '%c' (have '%s')", expr->value->line, expr->value->column, c, type1);
                    free(type1);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                if (expr->operator== PLUS) {
                    result = createResultExpression(left->typeVar, left->pointer, +left->assign);
                } else if (expr->operator== MINUS) {
                    result = createResultExpression(left->typeVar, left->pointer, -left->assign);
                } else if (expr->operator== BITWISE_NOT) {
                    result = createResultExpression(left->typeVar, left->pointer, ~left->assign);
                }
                result->auxLine = expr->value->line;
                result->auxColumn = expr->value->column;
                return result;

            } else if (expr->operator== MULTIPLY) {
                if (expr->left->value->type != ID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: lvalue required as unary '%s' operand", expr->value->line, expr->value->column, expr->value->valor);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                if ((left->typeVar != NUM_INT || left->typeVar != CHARACTER  // alerta
                     || left->typeVar != INT || left->typeVar != CHAR) &&
                    left->pointer == 0) {
                    if (textBefore) printf("\n");
                    char *type1 = getExactType(left->typeVar, left->pointer);
                    printf("error:semantic:%d:%d: invalid type argument of unary '%c' (have '%s')", expr->value->line, expr->value->column, '*', type1);
                    free(type1);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }
                result = createResultExpression(left->typeVar, 0, *(&left->assign));
                result->auxLine = expr->value->line;
                result->auxColumn = expr->value->column;
                return result;

            } else if (expr->operator== BITWISE_AND || expr->operator== NOT || expr->operator== INC || expr->operator== DEC) {
                // printf("unaria expr->left->value->type %d %p %s\n", expr->left->value->type, expr->left, expr->left->value->valor);
                // printf("%d left %p %d %d\n", expr->operator, left, left->typeVar, left->pointer);
                // printf("auxIdNode %d\n", ((HashNode*) left->auxIdNode)->typeVar);
                if (expr->operator!= NOT && left->typeVar != ID && !left->auxIdNode) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: lvalue required as unary '%s' operand", expr->value->line, expr->value->column, expr->value->valor);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                auxLeftType = left->typeVar;
                auxLeftPointer = left->pointer;
                auxLeftValor = left->assign;
                if (left->typeVar == ID) {
                    auxLeftType = ((HashNode *)left->auxIdNode)->typeVar;
                    auxLeftPointer = ((HashNode *)left->auxIdNode)->pointer;
                    auxLeftValor = ((HashNode *)left->auxIdNode)->assign;
                }

                if (auxLeftType != NUM_INT && auxLeftType != CHARACTER && auxLeftType != INT && auxLeftType != CHAR && (auxLeftType != VOID && auxLeftPointer == 0)) {
                    char t[3];
                    if (expr->operator== BITWISE_AND)
                        strcpy(t, "&");
                    else if (expr->operator== NOT)
                        strcpy(t, "!");
                    else if (expr->operator== INC)
                        strcpy(t, "++");
                    else if (expr->operator== DEC)
                        strcpy(t, "--");
                    char *type1 = getExactType(auxLeftType, auxLeftPointer);
                    printf("error:semantic:%d:%d: invalid type argument of unary '%s' (have '%s')", expr->value->line, expr->value->column, t, type1);
                    free(type1);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                if (expr->operator== BITWISE_AND) {
                    result = createResultExpression(auxLeftType, 1, *(&auxLeftValor));
                } else if (expr->operator== NOT) {
                    result = createResultExpression(auxLeftType, auxLeftPointer, !(auxLeftValor));
                } else if (expr->operator== INC) {
                    result = createResultExpression(auxLeftType, auxLeftPointer, ++(auxLeftValor));
                } else if (expr->operator== DEC) {
                    result = createResultExpression(auxLeftType, auxLeftPointer, --(auxLeftValor));
                }
                result->auxLine = expr->value->line;
                result->auxColumn = expr->value->column;
                return result;
            }
            break;

        case POS_FIXA:
            // if (expr->value->type == L_PAREN) {
            //     printf("\npos fixa %p %d %d\n", expr, expr->operator, expr->value->type);
            //     printf("hihi ainda nao fizzzz funcao 968\n");
            //     exit(0);
            // }
            left = evalExpression(expr->left, globalHash, localHash, program);
            // printf("left %p %d %d %p\n", left, left->typeVar, left->pointer, left->auxIdNode);

            if (expr->operator== INC || expr->operator== DEC) {
                if (!left->auxIdNode) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: lvalue required as increment operand", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                int auxAssign;
                if (expr->operator== INC) {
                    auxAssign = left->assign + 1;
                    result = createResultExpression(left->typeVar, left->pointer, auxAssign);
                } else if (expr->operator== DEC) {
                    auxAssign = left->assign - 1;
                    result = createResultExpression(left->typeVar, left->pointer, auxAssign);
                }
                // set assign do id referente ao left
                result->auxLine = expr->value->line;
                result->auxColumn = expr->value->column;
                // printf("pos fixa result %p %d %d = %d\n", result, result->typeVar, result->pointer, result->assign);

                HashNode *hashNodeTemp = getIdentifierNode(localHash, expr->left->value->valor);
                if (!hashNodeTemp) hashNodeTemp = getIdentifierNode(globalHash, expr->left->value->valor);
                if (hashNodeTemp) setAssign(hashNodeTemp, result->assign);
                hashNodeTemp = NULL;
                return result;

            } else if (expr->operator== L_SQUARE_BRACKET) {
                HashNode *auxIdNode = left->auxIdNode;
                // printf("pos fixa l square %p %d %d %d\n", left, left->typeVar, left->pointer, auxIdNode->kind);
                // vendo se de fato é um array
                if (auxIdNode->kind != VECTOR) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: subscripted value is neither array nor pointer", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);

                } else {
                    // printf("qntd dimensoes esperadas %d\n", auxIdNode->qntdDimen);
                    int qntdDimenRecebidas = 0;
                    Dimension *dimenRecebidas = expr->dimension;
                    Dimension *dimenEsperada = auxIdNode->dimensions;
                    ResultExpression *dimenResult = NULL;
                    // percorrer as dimensoes recebidas e verificar se sao inteiros e se a qntd bate
                    while (dimenRecebidas) {
                        qntdDimenRecebidas++;
                        // printf("\n\nline column dimen %d %d\n\n", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
                        // printf("qntd dimensoes recebidas %d\n", qntdDimenRecebidas);
                        if (qntdDimenRecebidas != auxIdNode->qntdDimen) {
                            if (textBefore) printf("\n");
                            printf("error:semantic:%d:%d: subscripted value is neither array nor pointer", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
                            printLineError(dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
                            freeAST(program);
                            deleteAuxFile();
                            exit(0);
                        }

                        dimenResult = evalExpression(dimenRecebidas->exp, globalHash, localHash, program);
                        if ((dimenResult->typeVar != NUM_INT && dimenResult->typeVar != INT) || dimenResult->pointer != 0) {
                            if (textBefore) printf("\n");
                            printf("error:semantic:%d:%d: array subscript is not an integer", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
                            printLineError(dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
                            freeAST(program);
                            deleteAuxFile();
                            exit(0);
                        } else {
                            // printf("dimensao atrib = %d dimensao maxima = %d\n", dimenResult->assign, dimenEsperada->size);
                            if (dimenResult->assign >= dimenEsperada->size || dimenResult->assign < 0) {
                                if (textBefore) printf("\n");
                                printf("warning:%d:%d: array index out of bounds", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
                                printLineError(dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
                                textBefore = 1;
                            }
                        }

                        dimenEsperada = dimenEsperada->next;
                        dimenRecebidas = dimenRecebidas->next;
                    }
                }
                result = createResultExpression(auxIdNode->typeVar, 0, 0);
                result->auxIdNode = auxIdNode;
                // printf("pos fixa result %p %d %d = %d\n", result, result->typeVar, result->pointer, result->assign);
                return result;

            } else if (expr->operator== L_PAREN) {
                HashNode *auxIdNode = left->auxIdNode;
                // printf("%p hihi ainda nao fizzzz %p %d\n", left, auxIdNode, expr->operator);
                if (auxIdNode->kind != FUNCTION) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: called object '%s' is not a function or function pointer", expr->value->line, expr->value->column, auxIdNode->varId);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                // verificar se a quantidade de parametros bate
                ExpParam *auxParamRecebido = expr->param;
                int qntdParamRecebido = 0;
                while (auxParamRecebido) {
                    qntdParamRecebido++;
                    auxParamRecebido = auxParamRecebido->next;
                }
                if (qntdParamRecebido != auxIdNode->qntdParams) {
                    if (textBefore) printf("\n");
                    if (qntdParamRecebido > auxIdNode->qntdParams) {
                        printf("error:semantic:%d:%d: too many arguments to function '%s'", expr->value->line, expr->value->column, auxIdNode->varId);
                    } else {
                        printf("error:semantic:%d:%d: too few arguments to function '%s'", expr->value->line, expr->value->column, auxIdNode->varId);
                    }
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }
                Param *auxParam = auxIdNode->param;
                auxParamRecebido = expr->param;
                ResultExpression *resultParam = NULL;
                // printf("--------- %p \n", auxParam);
                int i = 1;
                while (auxParamRecebido && auxParam) {
                    resultParam = evalExpression(auxParamRecebido->exp, globalHash, localHash, program);

                    auxLeftPointer = auxParam->pointer;
                    if (auxParam->type == INT || auxParam->type == NUM_INT)
                        auxLeftType = NUM_INT;
                    else if (auxParam->type == CHAR || auxParam->type == CHARACTER)
                        auxLeftType = CHARACTER;
                    else if (auxParam->type == VOID)
                        auxLeftType = VOID;

                    auxRightPointer = resultParam->pointer;
                    if (resultParam->typeVar == VOID)
                        auxRightType = VOID;
                    else if (resultParam->typeVar == INT || resultParam->typeVar == NUM_INT)
                        auxRightType = NUM_INT;
                    else if (resultParam->typeVar == CHAR || resultParam->typeVar == CHARACTER)
                        auxRightType = CHARACTER;
                    else if (resultParam->typeVar == STRING) {
                        auxRightType = CHARACTER;
                        auxRightPointer = 1;
                    }

                    // printf("argumentos esperados %s %d %d %d x %d %d = %d\n", auxParam->identifier, auxLeftType, auxLeftPointer, auxParam->kindParam, auxRightType, auxRightPointer, resultParam->assign);
                    if (auxParam->kindParam == VECTOR && auxRightType == auxLeftType) {
                        // printf("ok\n");
                    } else if (auxRightType != auxLeftType) {
                        if (textBefore) printf("\n");
                        char *type1 = getExactType(auxRightType, auxRightPointer);
                        char *type2 = getExactType(auxLeftType, auxLeftPointer);
                        printf("error:semantic:%d:%d: incompatible type for argument '%d' of 'foo' expected '%s' but argument is of type '%s'", expr->value->line, expr->value->column, i, type2, type1);
                        free(type1);
                        free(type2);
                        printLineError(expr->value->line, expr->value->column);
                        freeAST(program);
                        deleteAuxFile();
                        exit(0);
                    }

                    auxParam = auxParam->next;
                    auxParamRecebido = auxParamRecebido->next;
                    i++;
                }
                result = createResultExpression(auxIdNode->typeVar, auxIdNode->pointer, 0);
                result->auxLine = expr->value->line;
                result->auxColumn = expr->value->column;
                // printf("result %p %d %d = %d\n", result, result->typeVar, result->pointer, 0);
                // exit(1);
                return result;
            }
            break;

        default:
            printf("Tipo de expressão não suportado %p\n", expr);
            deleteAuxFile();
            exit(0);
    }
    return 0;
}

void traverseASTCommand(Command *command, void **globalHash, void **localHash, Program *program, Function *currentFunction) {
    if (!command) return;
    if (teveReturn) return;
    if (command == last) return;
    last = command;
    // printf("traverseASTCommand %d %p %p %p\n",command->type, command, command->next, last);
    // Para cada comando percorrer seus blocos de comandos e expressoes relacionadas recursivamente
    // Atencao as expressoes condicionais das estruturas, qua NAO PODEM ter expressoes de retorno tipo void
    if (command->type == LISTA_EXP_COMANDO) {
        evalExpression(command->condition, globalHash, localHash, program);
        traverseASTCommand(command->next, globalHash, localHash, program, currentFunction);
    } 

    if (command->type == IF || command->type == ELSE) {
        ResultExpression *ifResult = NULL;
        ifResult = evalExpression(command->condition, globalHash, localHash, program);
        if (ifResult->typeVar == VOID && ifResult->pointer == 0) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", ifResult->auxLine, ifResult->auxColumn);
            printLineError(ifResult->auxLine, ifResult->auxColumn);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
        traverseASTCommand(command->elseStatement, globalHash, localHash, program, currentFunction);
    }

    if (command->type == WHILE || command->type == DO) {
        ResultExpression *whileResult = NULL;
        whileResult = evalExpression(command->condition, globalHash, localHash, program);
        if (whileResult->typeVar == VOID && whileResult->pointer == 0) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", whileResult->auxLine, whileResult->auxColumn);
            printLineError(whileResult->auxLine, whileResult->auxColumn);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
    }

    if (command->type == FOR) {
        ResultExpression *forResult = NULL;
        evalExpression(command->init, globalHash, localHash, program);
        forResult = evalExpression(command->condition, globalHash, localHash, program);
        if (forResult->typeVar == VOID && forResult->pointer == 0) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", forResult->auxLine, forResult->auxColumn);
            printLineError(forResult->auxLine, forResult->auxColumn);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        evalExpression(command->increment, globalHash, localHash, program);
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
    }

    if (command->type == PRINTF || command->type == SCANF) {
        ResultExpression *toPrint = evalExpression(command->auxPrint, globalHash, localHash, program);
        if (command->type == PRINTF) {
            if (command->auxPrint) {
                char *stringWithoutFormat = calloc(strlen(command->string) + 1, sizeof(char));
                strcpy(stringWithoutFormat, command->string+1);
                strtok(stringWithoutFormat, "%d");
                strcat(stringWithoutFormat, "\0");
                printString(mipsFile, stringWithoutFormat);
                printInteger(mipsFile, toPrint->assign);
                free(stringWithoutFormat++);
            } else {
                printString(mipsFile, command->string);
            }
        
        } else {
            printString(mipsFile, command->string);
            printScanInt(mipsFile);
        } 

    }

    if (command->type == RETURN) {
        // printf("\nreturn %p %d\n", command->condition, command->condition->type);
        functionWithNoReturn = 1;
        if (currentFunction->returnType == VOID && currentFunction->pointer == 0) {
            if (command->condition) {
                HashNode *auxFunc = getIdentifierNode(globalHash, currentFunction->name);
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: return with a value, in function returning void", auxFunc->line, auxFunc->column);
                printLineError(auxFunc->line, auxFunc->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }
        } else {
            if (!command->condition) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: return with no value, in function returning non-void", command->auxToken->line, command->auxToken->column);
                printLineError(command->auxToken->line, command->auxToken->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }
        }
        if (command->condition) {
            ResultExpression *returnAux = evalExpression(command->condition, globalHash, localHash, program);
            int auxReturnType = returnAux->typeVar;
            if (returnAux->typeVar == NUM_INT || returnAux->typeVar == INT)
                auxReturnType = INT;
            else if (returnAux->typeVar == CHARACTER || returnAux->typeVar == CHAR)
                auxReturnType = CHAR;
            if (auxReturnType != currentFunction->returnType) {
                if (textBefore) printf("\n");
                char *type1 = getExactType(returnAux->typeVar, returnAux->pointer);
                char *type2 = getExactType(currentFunction->returnType, currentFunction->pointer);
                printf("error:semantic:%d:%d: incompatible types when returning type '%s' but '%s' was expected", command->auxToken->line, command->auxToken->column, type1, type2);
                free(type1);
                free(type2);
                printLineError(command->auxToken->line, command->auxToken->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }
        }
        if (!command->next)
            teveReturn = 1;
    }

    if (command->type == EXIT) {
        if (command->condition) evalExpression(command->condition, globalHash, localHash, program);
    }
}

int traverseAST(Program *program) {
    if (!program) return -1;
    // Percorra as funções na lista de funções
    Function *currentFunction = program->functionsList;
    while (currentFunction != NULL) {
        teveReturn = 0;
        // printf("Function: %s %p\n", currentFunction->name, currentFunction);
        // Percorra os comandos na função
        Command *command = currentFunction->commandList;
        while (command != NULL) {
            traverseASTCommand(command, program->hashTable, currentFunction->hashTable, program, currentFunction);
            command = command->next;
        }
        if (functionWithNoReturn == 0 && currentFunction->returnType != VOID) {
            HashNode *funcNode = getIdentifierNode(program->hashTable, currentFunction->name);
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: no return statement in function returning non-void", funcNode->line, funcNode->column);
            printLineError(funcNode->line, funcNode->column);
            freeAST(program);
            exit(0);
        }
        functionWithNoReturn = 0;
        currentFunction = currentFunction->next;
    }
    return 0;
}

void freeAST(Program *program) {
    if (!program) return;
    freeHash(program->hashTable);

    Function *functions = program->functionsList;
    while (functions) {
        Function *functions2 = functions->next;
        Command *cmd = functions->commandList;
        while (cmd) {
            Command *cmd2 = cmd->next;
            if (cmd->condition) {
                if (cmd->condition->value) free(cmd->condition->value);
                free(cmd->condition);
            }
            if (cmd->init) {
                if (cmd->init->value) free(cmd->init->value);
                free(cmd->init);
            }
            if (cmd->increment) {
                if (cmd->increment->value) free(cmd->increment->value);
                free(cmd->increment);
            }
            if (cmd->auxPrint) {
                if (cmd->auxPrint->value) free(cmd->auxPrint->value);
                free(cmd->auxPrint);
            }
            if (cmd->auxToken) free(cmd->auxToken);
            free(cmd);
            cmd = cmd2;
        }
        freeHash(functions->hashTable);
        if (functions->name) free(functions->name);
        free(functions);
        functions = functions2;
    }
    free(program);
}