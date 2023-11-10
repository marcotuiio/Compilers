#include "ast.h"

#include "hash.h"
#include "sintatico.tab.h"

int functionWithNoReturn = 0;
extern void printLineError(int line, int column);
extern void deleteAuxFile();
extern int textBefore;
extern int defineAux;
extern int dimensionAux;

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

Expression *createExpression(int type, int operator, void *value, void *left, void *right) {
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

Command *createScanStatement(char *identifier, char *format, void *next) {
    Command *newScan = calloc(1, sizeof(Command));
    newScan->type = SCANF;
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
    newCommand->type = 9802;
    newCommand->condition = expression;
    newCommand->next = next;
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

    switch (expr->type) {
        case NUMEROS:
            if (expr->value->type == NUM_INT) {
                result = createResultExpression(expr->value->type, expr->value->pointer, atoi(expr->value->valor));
                return result;
            }
            printf("Numero que nao e int\n");
            break;

        case PRIMARIA:
            if (expr->operator == ID) {

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

                // printf("Achei %s %d %d = %d\n", hashNode->varId, hashNode->typeVar, hashNode->pointer, hashNode->assign);

                if (hashNode->typeVar == VOID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                } else if (hashNode->typeVar == NUM_INT || hashNode->typeVar == INT) {
                    result = createResultExpression(hashNode->typeVar, hashNode->pointer, hashNode->assign);
                    strcpy(result->id, expr->value->valor);
                    return result;
                } else if (hashNode->typeVar == CHARACTER || hashNode->typeVar == CHAR) {
                    result = createResultExpression(hashNode->typeVar, hashNode->pointer, hashNode->assign);
                    strcpy(result->id, expr->value->valor);
                    return result;
                } else if (hashNode->typeVar == STRING) {
                    result = createResultExpression(CHAR, 1, 0);
                    strcpy(result->id, expr->value->valor);
                    return result;
                }
            
            } else if (expr->operator == CHARACTER) {
                result = createResultExpression(expr->value->type, expr->value->pointer, expr->value->valor[0]);
                return result;
                
            } else if (expr->operator == STRING) {
                result = createResultExpression(STRING, 0, 0);
                return result;
            } 
            break;
        
        case ATRIBUICAO:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("testando assign left %p %d %d\n", left, expr->value->type, expr->value->pointer);
            // printf("testando assign right %p %d %d\n", right, expr->value->type, expr->value->pointer);

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

            if (expr->operator == ASSIGN) {
                if (right) {
                    if (left->pointer != 0 || right->pointer != 0) {  // existem pointers envolvidos
                        // se forem de tipo diferente ou ponteiro diferente
                        if (left->typeVar != right->typeVar || left->pointer != right->pointer) {  
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
                    AuxToken *localRight = expr->right->value;
                    if (left->pointer != 0 || localRight->pointer != 0) {  // existem pointers envolvidos
                        // se forem de tipo diferente ou ponteiro diferente
                        if (left->typeVar != localRight->type || left->pointer != localRight->pointer) {  
                            if (textBefore) printf("\n");
                            char *type1 = getExactType(left->typeVar, left->pointer);
                            char *type2 = getExactType(localRight->type, localRight->pointer);
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

            } else if (expr->operator == ADD_ASSIGN || expr->operator == MINUS_ASSIGN) {
                if (right) {
                    if (left->pointer != 0) {
                        if (right->typeVar != NUM_INT || right->typeVar != CHARACTER) {
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
                    AuxToken *localRight = expr->right->value;
                    if (left->pointer != 0) {
                        if (localRight->type != NUM_INT || localRight->type != CHARACTER) {
                            if (textBefore) printf("\n");
                            char *type1 = getExactType(left->typeVar, left->pointer);
                            char *type2 = getExactType(localRight->type, localRight->pointer);
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
                result = createResultExpression(left->typeVar, left->pointer, left->assign);
                return result;
            } 
            break;
        
        case LISTA_EXP:  // nao sei fazer ainda
            printf("lista_exp\n");
            break;
        
        case TERNARY: 
            ResultExpression *condition = evalExpression(expr->ternary, globalHash, localHash, program);
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

            if (left->typeVar != right->typeVar) {
                if (textBefore) printf("\n");
                char *type1 = getExactType(left->typeVar, left->pointer);
                char *type2 = getExactType(right->typeVar, right->pointer);
                printf("warning:%d:%d: '%s'/'%s' type mismatch in conditional expression", expr->value->line, expr->value->column, type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                textBefore = 1;
            }

            if (condition->assign) result = createResultExpression(left->typeVar, left->pointer, left->assign);
            else result = createResultExpression(right->typeVar, right->pointer, right->assign);
            return result;

        case OR_LOGICO:
        case AND_LOGICO:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("testando or and log left %p %d %d\n", left, expr->value->type, expr->value->pointer);
            // printf("testando or and log right %p %d %d\n", right, expr->value->type, expr->value->pointer);

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT) auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER) auxLeftType = CHARACTER;
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
                if (right->typeVar == INT || right->typeVar == NUM_INT) auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER) auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign; 
            }

            if (expr->type == OR_LOGICO) result = createResultExpression(INT, 0, auxLeftValor || auxRightValor);
            else if (expr->type == AND_LOGICO) result = createResultExpression(INT, 0, auxLeftValor && auxRightValor);
            return result;
        
        case RELACIONAL:
            left = evalExpression(expr->left, globalHash, localHash, program); 
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("testando relaccional left %p %d %d\n", left, left->typeVar, left->pointer);
            // printf("testando relaccional right %p %d %d\n", right, right->typeVar, right->pointer);

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT) auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER) auxLeftType = CHARACTER;
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
                if (right->typeVar == INT || right->typeVar == NUM_INT) auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER) auxRightType = CHARACTER;
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
                // printf("chegou left %p %d %d\n", left, left->pointer, left->typeVar);
                // printf("chegou right %p %d %d\n", right, right->pointer, right->typeVar);
                // printf("aqui: %d %d %d %d\n", auxLeftType, auxLeftPointer, auxRightType, auxRightPointer);
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

            if (expr->operator == LESS_THAN) {
                result = createResultExpression(INT, 0, left->assign < right->assign);
            } else if (expr->operator == GREATER_THAN) {
                result = createResultExpression(INT, 0, left->assign > right->assign);
            } else if (expr->operator == LESS_EQUAL) {
                result = createResultExpression(INT, 0, left->assign <= right->assign);
            } else if (expr->operator == GREATER_EQUAL) {
                result = createResultExpression(INT, 0, left->assign >= right->assign);
            } else if (expr->operator == EQUAL) {
                result = createResultExpression(INT, 0, left->assign == right->assign);
            } else if (expr->operator == NOT_EQUAL) {
                result = createResultExpression(INT, 0, left->assign != right->assign);
            }
            return result;
            break;
        
        case SHIFT:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("testando shift left %p %d %d\n", left, expr->value->type, expr->value->pointer);
            // printf("testando shift right %p %d %d\n", right, expr->value->type, expr->value->pointer);
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
                if (right->typeVar == INT || right->typeVar == NUM_INT) auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER) auxRightType = CHARACTER;
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
                if (expr->operator == R_SHIFT) strcpy(t, ">>");
                else if (expr->operator == L_SHIFT) strcpy(t, "<<");
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
                printf("error:semantic:%d:%d: %s shift count is negative", expr->value->line, expr->value->column, expr->operator == R_SHIFT ? "right" : "left");
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            // verificar se o valor da direita é maior que o tamanho do tipo da esquerda
            if (auxRightValor >= leftBits) {
                if (textBefore) printf("\n");
                printf("warning:%d:%d: %s shift count >= width of type", expr->value->line, expr->value->column, expr->operator == R_SHIFT ? "right" : "left");
                printLineError(expr->value->line, expr->value->column);
                textBefore = 1;
            }

            if (expr->operator == R_SHIFT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor >> auxRightValor);
            } else if (expr->operator == L_SHIFT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor << auxRightValor);
            }
            return result;
        
        case ADITIVIVA:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("testando aditivas left %p (%d) %d = %d\n", left, left->typeVar, expr->value->pointer, left->assign);
            // printf("testando aditivas right %p (%d) %d = %d\n", right, right->typeVar, expr->value->pointer, right->assign);

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT) auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER) auxLeftType = CHARACTER;
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
                if (right->typeVar == INT || right->typeVar == NUM_INT) auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER) auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign; 
            }

            // printf("left %p %d %d %d\n", left, auxLeftType, auxLeftPointer, auxLeftValor);
            // printf("right %p %d %d %d\n", right, auxRightType, auxRightPointer, auxRightValor);
            // se tem tipo diferente de char e int ou sao dois pointers
            if ((auxLeftPointer == 0 || auxRightPointer == 0) && 
                (auxLeftType == NUM_INT || auxLeftType == CHARACTER) &&
                (auxRightType == NUM_INT || auxRightType == CHARACTER)) {
                    // printf("certo!\n");
            } else {
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator == PLUS ? "+" : "-", type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }
            
            if (expr->operator == PLUS) {
                // pode somar pointer e char ou int                
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
                return result;  

            } else if (expr->operator == MINUS) {
                // printf("minus l %p %d %d = %d\n", left, left->typeVar, left->pointer, left->assign);
                // printf("minus r %p %d %d = %d\n", right, right->typeVar, right->pointer, right->assign);
                if (auxRightPointer != 0) {
                    char *type1 = getExactType(auxLeftType, auxLeftPointer);
                    char *type2 = getExactType(auxRightType, auxRightPointer);
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator == PLUS ? "+" : "-", type1, type2);
                    free(type1);
                    free(type2);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor - auxRightValor);
                // printf("minus %p %d %d = %d\n", result, result->typeVar, result->pointer, result->assign);
                return result;  
            }
            break;
        
        case MULTIPLICATIVA:
        case OR_BIT:
        case XOR_BIT:
        case AND_BIT:
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            // printf("testando multiplicativas left %p %d %d\n", left, expr->value->type, expr->value->pointer);
            // printf("testando multiplicativas right %p %d %d\n", right, expr->value->type, expr->value->pointer);

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT || left->typeVar == NUM_INT) auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR || left->typeVar == CHARACTER) auxLeftType = CHARACTER;
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
                if (right->typeVar == INT || right->typeVar == NUM_INT) auxRightType = NUM_INT;
                else if (right->typeVar == CHAR || right->typeVar == CHARACTER) auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                if (right->typeVar == STRING) {
                    auxRightType = CHARACTER;
                    auxRightPointer = 1;
                }
                auxRightValor = right->assign; 
            }

            if (auxLeftPointer == 0 && auxRightPointer == 0 && 
                (auxLeftType == NUM_INT || auxLeftType == CHARACTER) 
                && (auxRightType == NUM_INT || auxRightType == CHARACTER)) {
                    // printf("certo!\n");
            } else {
                char c;
                if (expr->operator == MULTIPLY) c = '*';
                else if (expr->operator == DIVIDE) c = '/';
                else if (expr->operator == REMAINDER) c = '%';
                else if (expr->operator == OR_BIT) c = '|';
                else if (expr->operator == XOR_BIT) c = '^';
                else if (expr->operator == AND_BIT) c = '&';
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

            if (expr->operator == MULTIPLY) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor * auxRightValor);
                // printf("criando mult %p %d %d = %d\n", result, result->typeVar, result->pointer, result->assign);
                return result;
            } else if (expr->operator == DIVIDE) {
                if (right->assign == 0 || auxRightValor == 0) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: division by zero", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor / auxRightValor);
                return result;
            } else if (expr->operator == REMAINDER) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor % auxRightValor);
                return result;
            } else if (expr->operator == OR_BIT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor | auxRightValor);
                return result;
            } else if (expr->operator == XOR_BIT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor ^ auxRightValor);
                return result;
            } else if (expr->operator == AND_BIT) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor & auxRightValor);
                return result;
            }
            break;
        
        case CASTING:
            right = evalExpression(expr->right, globalHash, localHash, program);

            // printf("\ncastando left %d %d\n", expr->value->type, expr->value->pointer);
            // printf("castando right %d %d\n", right->typeVar, right->pointer);
            if (right->typeVar == STRING) {
                right->typeVar = CHAR;
                right->pointer = 1;
            }

            if (right->typeVar == VOID && expr->value->type != VOID) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);                
            }

            if ((right->typeVar == NUM_INT || right->typeVar == INT) 
                && (expr->value->type != NUM_INT && expr->value->type != INT)) {
                if (textBefore) printf("\n");
                char *type1 = getExactType(right->typeVar, right->pointer);
                char *type2 = getExactType(expr->value->type, expr->value->pointer);
                printf("warning:%d:%d: cast from '%s' to '%s' of different size", expr->value->line, expr->value->column, type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                textBefore = 1;
            }
            result = createResultExpression(expr->value->type, expr->value->pointer, right->assign);
            // printf("\n\ncastando result %d %d\n", result->typeVar, result->pointer);
            return result;
        
        case UNARIA:
            left = evalExpression(expr->left, globalHash, localHash, program);
            // printf("testando unaria left %p %d %d\n", left, expr->value->type, expr->value->pointer);

            if (expr->left->value->type != ID) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: lvalue required as unary '%s' operand", expr->value->line, expr->value->column, expr->value->valor);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                deleteAuxFile();
                exit(0);
            }

            if (expr->operator == PLUS || expr->operator == MINUS || expr->operator == BITWISE_NOT) {

                if (left->typeVar == NUM_INT || left->typeVar != CHARACTER 
                    || left->typeVar != INT || left->typeVar != CHAR) {
                    
                    if (left->pointer != 0 && expr->operator != BITWISE_NOT) {
                        if (textBefore) printf("\n");
                        printf("error:semantic:%d:%d: wrong type argument to unary %s", expr->value->line, expr->value->column, expr->operator == PLUS ? "plus" : "minus");
                        printLineError(expr->value->line, expr->value->column);
                        freeAST(program);
                        deleteAuxFile();
                        exit(0);
                    }
                }

                if (left->typeVar != NUM_INT && left->typeVar && CHARACTER 
                    && left->typeVar != INT && left->typeVar != CHAR) {
                    
                    char c;
                    if (expr->operator == PLUS) c = '+';
                    else if (expr->operator == MINUS) c = '-';
                    else if (expr->operator == BITWISE_NOT) c = '~';
                    char *type1 = getExactType(left->typeVar, left->pointer);

                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: invalid type argument of unary '%c' (have '%s')", expr->value->line, expr->value->column, c, type1);
                    free(type1);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                if (expr->operator == PLUS) {
                    result = createResultExpression(left->typeVar, left->pointer, +left->assign);
                } else if (expr->operator == MINUS) {
                    result = createResultExpression(left->typeVar, left->pointer, -left->assign);
                } else if (expr->operator == BITWISE_NOT) {
                    result = createResultExpression(left->typeVar, left->pointer, ~left->assign);
                }
                return result;

            } else if (expr->operator == MULTIPLY) {

                if ((left->typeVar != NUM_INT || left->typeVar != CHARACTER   // alerta
                    || left->typeVar != INT || left->typeVar != CHAR)
                    && left->pointer == 0) {

                    if (textBefore) printf("\n");
                    char *type1 = getExactType(left->typeVar, left->pointer);
                    printf("error:semantic:%d:%d: invalid type argument of unary '%c' (have '%s')", expr->value->line, expr->value->column, '*', type1);
                    free(type1);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                } 
                result = createResultExpression(left->typeVar, left->pointer, *(&left->assign));
                return result;

            } else if (expr->operator == BITWISE_AND || expr->operator == NOT || expr->operator == INC || expr->operator == DEC) {

                if (left->typeVar != NUM_INT && left->typeVar != CHARACTER 
                    && left->typeVar != INT && left->typeVar != CHAR) {

                    char t[3];
                    if (expr->operator == BITWISE_AND) strcpy(t, "&");
                    else if (expr->operator == NOT) strcpy(t, "!");
                    else if (expr->operator == INC) strcpy(t, "++");
                    else if (expr->operator == DEC) strcpy(t, "--");
                    char *type1 = getExactType(left->typeVar, left->pointer);
                    printf("error:semantic:%d:%d: invalid type argument of unary '%s' (have '%s')", expr->value->line, expr->value->column, t, type1);
                    free(type1);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    deleteAuxFile();
                    exit(0);
                }

                if (expr->operator == BITWISE_AND) {
                    result = createResultExpression(left->typeVar, 1, *(&left->assign));
                } else if (expr->operator == NOT) {
                    result = createResultExpression(left->typeVar, left->pointer, !left->assign);
                } else if (expr->operator == INC) {
                    result = createResultExpression(left->typeVar, left->pointer, ++left->assign);
                } else if (expr->operator == DEC) {
                    result = createResultExpression(left->typeVar, left->pointer, --left->assign);
                } 
                return result;
            } 
            break;

        case POS_FIXA:
            printf("pos fixa\n");
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);
            printf("testando pos fixa left %p %d %d\n", left, expr->value->type, expr->value->pointer);
            printf("testando pos fixa right %p %d %d\n", right, expr->value->type, expr->value->pointer);
            deleteAuxFile();
            exit(0);
            break;
        
        default:
            printf("Tipo de expressão não suportado %p\n", expr);
            deleteAuxFile();
            exit(0);
    }
    return 0;
}

void traverseASTCommand(Command *command, void **globalHash, void **localHash, Program *program, Function *currentFunction) {
    if (command == NULL) return;

    if (command->type == 9802) {
        // printf("Command de expressão\n");
        evalExpression(command->condition, globalHash, localHash, program);
    }

    // Se o comando for um comando IF ou ELSE, percorra as condições e blocos
    if (command->type == IF || command->type == ELSE) {
        // printf("Command de if ou else\n");
        ResultExpression *ifResult = NULL;
        ifResult = evalExpression(command->condition, globalHash, localHash, program);
        // printf("resultValue %d\n", ifResult->assign);
        if (ifResult->typeVar == VOID) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", command->auxToken->line, command->auxToken->column);
            printLineError(command->auxToken->line, command->auxToken->column);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
        traverseASTCommand(command->elseStatement, globalHash, localHash, program, currentFunction);
    }

    // Se o comando for um comando WHILE ou DO-WHILE, percorra a condição e o bloco
    if (command->type == WHILE || command->type == DO) {
        // printf("Command de while ou do-while\n");
        ResultExpression *whileResult = NULL;
        whileResult = evalExpression(command->condition, globalHash, localHash, program);
        if (whileResult->typeVar == VOID) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", command->auxToken->line, command->auxToken->column);
            printLineError(command->auxToken->line, command->auxToken->column);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
    }

    // Se o comando for um comando FOR, percorra a inicialização, condição, incremento e bloco
    if (command->type == FOR) {
        // printf("Command de for\n");
        ResultExpression *forResult = NULL;
        forResult = evalExpression(command->init, globalHash, localHash, program);
        if (forResult->typeVar == VOID) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", command->auxToken->line, command->auxToken->column);
            printLineError(command->auxToken->line, command->auxToken->column);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        forResult = evalExpression(command->condition, globalHash, localHash, program);
        if (forResult->typeVar == VOID) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", command->auxToken->line, command->auxToken->column);
            printLineError(command->auxToken->line, command->auxToken->column);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        forResult = evalExpression(command->increment, globalHash, localHash, program);
        if (forResult->typeVar == VOID) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: void value not ignored as it ought to be", command->auxToken->line, command->auxToken->column);
            printLineError(command->auxToken->line, command->auxToken->column);
            freeAST(program);
            deleteAuxFile();
            exit(0);
        }
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
    }

    // Se o comando for um comando PRINTF ou SCANF, percorra os argumentos
    if (command->type == PRINTF || command->type == SCANF) {
        // printf("Command de printf ou scanf\n");
        evalExpression(command->auxPrint, globalHash, localHash, program);
    }

    if (command->type == RETURN) {
        // printf("Command de return\n");
        functionWithNoReturn = 1;
        if (currentFunction->returnType == VOID) {
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
            // printf("retornou %d %d\n", returnAux->typeVar, currentFunction->returnType);
            if (returnAux->typeVar != currentFunction->returnType) {
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
    }

    // Se o comando for um comando RETURN ou EXIT, percorra a expressão
    if (command->type == EXIT) {
        // printf("Command de exit\n");
        if (command->condition) evalExpression(command->condition, globalHash, localHash, program);
    }

    command = command->next;
}

int traverseAST(Program *program) {
    if (!program) return -1;
    // Percorra as funções na lista de funções
    Function *currentFunction = program->functionsList;
    while (currentFunction != NULL) {

        // printf("Function: %s\n", currentFunction->name);
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
                if (cmd->init->value) free(cmd->condition->value);
                free(cmd->init);
            } 
            if (cmd->increment) {
                if (cmd->increment->value) free(cmd->condition->value);
                free(cmd->increment); 
            }
            if (cmd->auxPrint) {
                if (cmd->auxPrint->value) free(cmd->condition->value);
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