#include "ast.h"

#include "hash.h"
#include "sintatico.tab.h"

int functionWithNoReturn = 0;
extern void printLineError(int line, int column);
extern int textBefore;
extern int defineAux;

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
    newResult->type = type;
    newResult->pointer = pointer;
    newResult->value = value;
    return newResult;
}

ResultExpression *evalExpression(Expression *expr, void **globalHash, void **localHash, Program *program) {
    if (!expr) return NULL;

    ResultExpression *leftExp = NULL;
    ResultExpression *rightExp = NULL;
    ResultExpression *result = NULL;
    HashNode *left = NULL;
    HashNode *right = NULL;

    int auxLeftPointer, auxRightPointer;
    int auxLeftType, auxRightType;
    int auxLeftValor, auxRightValor;

    printf("type: %d\n", expr->type);

    switch (expr->type) {
        case NUMEROS:
            printf("numeros\n");
            if (expr->value->type == NUM_INT) {
                result = createResultExpression(expr->value->type, expr->value->pointer, atoi(expr->value->valor));
                return result;
            }
            printf("Numero que nao e int\n");
            break;

        case PRIMARIA:
            if (expr->operator == ID) {
                left = getIdentifierNode(localHash, expr->value->valor);
                if (!left) left = getIdentifierNode(globalHash, expr->value->valor);
                if (!left) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->value->valor);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    exit(0);
                }
                
                if (left->typeVar == VOID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    exit(0);
                } else if (left->typeVar == NUM_INT) {
                    result = createResultExpression(left->typeVar, left->pointer, left->assign);
                    return result;
                } else if (left->typeVar == CHARACTER) {
                    result = createResultExpression(left->typeVar, left->pointer, left->assign);
                    return result;
                } else if (left->typeVar == STRING) {
                    result = createResultExpression(CHAR, 1, 0);
                    return result;
                }
            
            } else if (expr->operator == CHARACTER) {
                result = createResultExpression(expr->value->type, expr->value->pointer, expr->value->valor[0]);
                return result;
                
            } else if (expr->operator == STRING) {
                result = createResultExpression(CHAR, 1, 0);
                return result;
            } 
            break;
        
        case ATRIBUICAO:
            // atribuindo para constante
            if (expr->left->value->type == STRING || expr->left->value->type == CHARACTER) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: assignment of read-only location %s", expr->value->line, expr->value->column, expr->left->value->valor);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                exit(0);
            }

            // atribuindo sem ser id
            if (expr->left->value->type != ID) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: lvalue required as left operand of assignment", expr->value->line, expr->value->column);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                exit(0);
            }

            // transformar em funcao de verificar se for declarada mesmo
            left = getIdentifierNode(localHash, expr->left->value->valor);
            if (!left) left = getIdentifierNode(globalHash, expr->left->value->valor);
            if (!left) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->left->value->valor);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                exit(0);
            }
            if (expr->right->value->type == ID) {
                right = getIdentifierNode(localHash, expr->right->value->valor);
                if (!right) right = getIdentifierNode(globalHash, expr->right->value->valor);
                if (!right) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->right->value->valor);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    exit(0);
                }
                if (right->typeVar == VOID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    exit(0);
                }
            }
            
            if (expr->operator == ASSIGN) {
                printf("assign %s %s\n", (char *)expr->left->value->valor, (char *)expr->right->value->valor);

                if (right) {
                    // nao esta preparado para casting
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
                            exit(0);
                        }
                    } 
                }

            } else if (expr->operator == ADD_ASSIGN || expr->operator == MINUS_ASSIGN) {
                printf("add assign or sub assign\n");

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
                            exit(0);
                        }
                    }
                }
                // retorna o valor calculado com o tipo do ponteiro da esquerda?  
            } 
            break;
        
        case LISTA_EXP:
            printf("lista_exp\n");
            break;
        
        case TERNARY:
            if (evalExpression(expr->left, globalHash, localHash, program)) {
                printf("ternary\n");
                return evalExpression(expr->right->left, globalHash, localHash, program);
            } else {
                printf("ternary\n");
                return evalExpression(expr->right->right, globalHash, localHash, program);
            }
        
        case OR_LOGICO:
            printf("or logico\n");
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);
            result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value || rightExp->value);
            return result;
        
        case AND_LOGICO:
            printf("and logico\n");
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);
            result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value && rightExp->value);
            return result;

        case OR_BIT:
            printf("or bit\n");
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);
            result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value | rightExp->value);
            return result;
        
        case XOR_BIT:
            printf("xor bit\n");
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);
            result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value ^ rightExp->value);
            return result;
        
        case AND_BIT:
            printf("and bit\n");
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);
            result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value & rightExp->value);
            return result;
        
        case RELACIONAL:
            leftExp = evalExpression(expr->left, globalHash, localHash, program); 
            rightExp = evalExpression(expr->right, globalHash, localHash, program);

            if (expr->operator == LESS_THAN) {
                printf("less than\n");
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value < rightExp->value);
            } else if (expr->operator == GREATER_THAN) {
                printf("greater than\n");
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value > rightExp->value);
            } else if (expr->operator == LESS_EQUAL) {
                printf("less equal\n");
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value <= rightExp->value);
            } else if (expr->operator == GREATER_EQUAL) {
                printf("greater equal\n");
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value >= rightExp->value);
            } else if (expr->operator == EQUAL) {
                printf("equal\n");
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value == rightExp->value);
            } else if (expr->operator == NOT_EQUAL) {
                printf("not equal\n");
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value != rightExp->value);
            }
            return result;
            break;
        
        case SHIFT:
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);
            // verificar tipos etc etc
            if (expr->operator == R_SHIFT) {
                printf("r shift\n");    
                // verificar se o valor da direita é maior que o tamanho do tipo da esquerda
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value >> rightExp->value);
                return result;
            } else if (expr->operator == L_SHIFT) {
                printf("l shift\n");
                // verificar se o valor da direita é maior que o tamanho do tipo da esquerda
                result = createResultExpression(leftExp->type, leftExp->pointer, leftExp->value << rightExp->value);
                return result;
            }
        
        case ADITIVIVA:
            // printf("antes do left aditiva %p %s\n", expr->left, expr->left->value->valor);
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);
            // printf("aditiva o que houve? %p %d\n", leftExp, rightExp->value);
            // exit(0);
            if (defineAux) {
                if (expr->left->value->type == ID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' initializer element is not constant", expr->left->value->line, expr->left->value->column, expr->left->value->valor);
                    printLineError(expr->left->value->line, expr->left->value->column);
                    freeAST(program);
                    exit(0);
                } else if (expr->right->value->type == ID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' initializer element is not constant", expr->right->value->line, expr->right->value->column, expr->right->value->valor);
                    printLineError(expr->right->value->line, expr->right->value->column);
                    freeAST(program);
                    exit(0);
                }
            }

            // se for um id, verificar se ele existe
            left = NULL;
            if (expr->left->value->type == ID) {
                left = getIdentifierNode(localHash, expr->left->value->valor);
                if (!left) left = getIdentifierNode(globalHash, expr->left->value->valor);
                if (!left) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->left->value->valor);
                    printLineError(expr->left->value->line, expr->left->value->column);
                    freeAST(program);
                    exit(0);
                }   
            }
            right = NULL;
            if (expr->right->value->type == ID) {
                right = getIdentifierNode(localHash, expr->right->value->valor);
                if (!right) right = getIdentifierNode(globalHash, expr->right->value->valor);
                if (!right) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->right->value->valor);
                    printLineError(expr->right->value->line, expr->right->value->column);
                    freeAST(program);
                    exit(0);
                }
            }

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT) auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR) auxLeftType = CHARACTER;
                auxLeftPointer = left->pointer;
                auxLeftValor = left->assign;
            } 
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT) auxRightType = NUM_INT;
                else if (right->typeVar == CHAR) auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                auxRightValor = right->assign; 
            }
            // printf("cuzin2 left %d %d %d\n", auxLeftPointer, auxLeftType, auxLeftValor);
            // printf("cuzin2 right %d %d %d\n", auxRightPointer, auxRightType, auxRightValor);
            
            // se tem tipo diferente de char e int ou sao dois pointers

            if ((auxLeftPointer == 0 || auxRightPointer == 0) && 
                (auxLeftType == NUM_INT || auxLeftType == CHARACTER) &&
                (auxRightType == NUM_INT || auxRightType == CHARACTER)) {
                    printf("certo!\n");

            } else {
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator == PLUS ? "+" : "-", type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                exit(0);
            }

            if (expr->operator == PLUS) {
                printf("plus\n");
                // pode somar pointer e char ou int                
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
                return result;  

            } else if (expr->operator == MINUS) {
                printf("minus\n");  
                if (auxRightPointer != 0) {
                    char *type1 = getExactType(auxLeftType, auxLeftPointer);
                    char *type2 = getExactType(auxRightType, auxRightPointer);
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator == PLUS ? "+" : "-", type1, type2);
                    free(type1);
                    free(type2);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    exit(0);
                }
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor - auxRightValor);
                return result;  
            }
            break;
        
        case MULTIPLICATIVA:
            leftExp = evalExpression(expr->left, globalHash, localHash, program);
            rightExp = evalExpression(expr->right, globalHash, localHash, program);

            if (defineAux) {
                if (expr->left->value->type == ID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' initializer element is not constant", expr->left->value->line, expr->left->value->column, expr->left->value->valor);
                    printLineError(expr->left->value->line, expr->left->value->column);
                    freeAST(program);
                    exit(0);
                } else if (expr->right->value->type == ID) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' initializer element is not constant", expr->right->value->line, expr->right->value->column, expr->right->value->valor);
                    printLineError(expr->right->value->line, expr->right->value->column);
                    freeAST(program);
                    exit(0);
                }
            }

            // se for um id, verificar se ele existe
            left = NULL;
            if (expr->left->value->type == ID) {
                left = getIdentifierNode(localHash, expr->left->value->valor);
                if (!left) left = getIdentifierNode(globalHash, expr->left->value->valor);
                if (!left) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->left->value->valor);
                    printLineError(expr->left->value->line, expr->left->value->column);
                    freeAST(program);
                    exit(0);
                }   
            }
            right = NULL;
            if (expr->right->value->type == ID) {
                right = getIdentifierNode(localHash, expr->right->value->valor);
                if (!right) right = getIdentifierNode(globalHash, expr->right->value->valor);
                if (!right) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->right->value->valor);
                    printLineError(expr->right->value->line, expr->right->value->column);
                    freeAST(program);
                    exit(0);
                }
            }

            auxLeftPointer = expr->left->value->pointer;
            auxLeftType = expr->left->value->type;
            auxLeftValor = atoi(expr->left->value->valor);
            if (left) {
                if (left->typeVar == INT) auxLeftType = NUM_INT;
                else if (left->typeVar == CHAR) auxLeftType = CHARACTER;
                auxLeftPointer = left->pointer;
                auxLeftValor = left->assign;
            }
            auxRightPointer = expr->right->value->pointer;
            auxRightType = expr->right->value->type;
            auxRightValor = atoi(expr->right->value->valor);
            if (right) {
                if (right->typeVar == INT) auxRightType = NUM_INT;
                else if (right->typeVar == CHAR) auxRightType = CHARACTER;
                auxRightPointer = right->pointer;
                auxRightValor = right->assign;
            }
            // printf("cuzin3 left %d %d %d\n", auxLeftPointer, auxLeftType, auxLeftValor);
            // printf("cuzin3 right %d %d %d\n", auxRightPointer, auxRightType, auxRightValor);

            if (auxLeftPointer == 0 && auxRightPointer == 0 && 
                (auxLeftType == NUM_INT || auxLeftType == CHARACTER) 
                && (auxRightType == NUM_INT || auxRightType == CHARACTER)) {
                    printf("certo!\n");
            } else {
                char c;
                if (expr->operator == MULTIPLY) c = '*';
                else if (expr->operator == DIVIDE) c = '/';
                else if (expr->operator == REMAINDER) c = '%';
                char *type1 = getExactType(auxLeftType, auxLeftPointer);
                char *type2 = getExactType(auxRightType, auxRightPointer);
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: invalid operands to binary '%c' (have '%s' and '%s')", expr->value->line, expr->value->column, c, type1, type2);
                free(type1);
                free(type2);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                exit(0);
            }

            if (expr->operator == MULTIPLY) {
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor * auxRightValor);
                printf("\nmultiply %d\n", result->value);
                return result;
            } else if (expr->operator == DIVIDE) {
                printf("divide\n");
                if (rightExp->value == 0 || auxRightValor == 0) {
                    if (textBefore) printf("\n");
                    printf("error:semantic:%d:%d: division by zero", expr->value->line, expr->value->column);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    exit(0);
                }
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor / auxRightValor);
                return result;
            } else if (expr->operator == REMAINDER) {
                printf("remainder\n");
                result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor % auxRightValor);
                return result;
            }
            break;
        
        case CASTING:
            
            printf("casting\n");
            break;
        
        case UNARIA:
            leftExp = evalExpression(expr->left, globalHash, localHash, program);

            if (expr->left->value->type != ID) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: lvalue required as unary '%s' operand", expr->value->line, expr->value->column, expr->value->valor);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                exit(0);
            }

            left = getIdentifierNode(localHash, expr->left->value->valor);
            if (!left) left = getIdentifierNode(globalHash, expr->left->value->valor);
            if (!left) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->left->value->valor);
                printLineError(expr->value->line, expr->value->column);
                freeAST(program);
                exit(0);
            }

            if (expr->operator == PLUS || expr->operator == MINUS || expr->operator == BITWISE_NOT) {
                printf("plus minus bitnot\n");

                if (left->typeVar == NUM_INT || left->typeVar != CHARACTER) {
                    if (left->pointer != 0 && expr->operator != BITWISE_NOT) {
                        if (textBefore) printf("\n");
                        printf("error:semantic:%d:%d: wrong type argument to unary %s", expr->value->line, expr->value->column, expr->operator == PLUS ? "plus" : "minus");
                        printLineError(expr->value->line, expr->value->column);
                        freeAST(program);
                        exit(0);
                    }
                }

                if (left->typeVar != NUM_INT || left->typeVar != CHARACTER) {
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
                    exit(0);
                }
                if (expr->operator == PLUS) {
                    result = createResultExpression(leftExp->type, leftExp->pointer, +leftExp->value);
                } else if (expr->operator == MINUS) {
                    result = createResultExpression(leftExp->type, leftExp->pointer, -leftExp->value);
                } else if (expr->operator == BITWISE_NOT) {
                    result = createResultExpression(leftExp->type, leftExp->pointer, ~leftExp->value);
                }
                return result;

            } else if (expr->operator == MULTIPLY) {
                printf("multply\n");

                if ((left->typeVar != NUM_INT || left->typeVar != CHARACTER) && left->pointer == 0) {
                    if (textBefore) printf("\n");
                    char *type1 = getExactType(left->typeVar, left->pointer);
                    printf("error:semantic:%d:%d: invalid type argument of unary '%c' (have '%s')", expr->value->line, expr->value->column, '*', type1);
                    free(type1);
                    printLineError(expr->value->line, expr->value->column);
                    freeAST(program);
                    exit(0);
                } 
                result = createResultExpression(leftExp->type, leftExp->pointer, *(&leftExp->value));
                return result;

            } else if (expr->operator == BITWISE_AND || expr->operator == NOT || expr->operator == INC || expr->operator == DEC) {
                printf("bitwise and not inc dec\n");
                if (left->typeVar != NUM_INT || left->typeVar != CHARACTER) {
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
                    exit(0);
                }

                if (expr->operator == BITWISE_AND) {
                    result = createResultExpression(leftExp->type, leftExp->pointer, *(&leftExp->value));
                } else if (expr->operator == NOT) {
                    result = createResultExpression(leftExp->type, leftExp->pointer, !leftExp->value);
                } else if (expr->operator == INC) {
                    result = createResultExpression(leftExp->type, leftExp->pointer, ++leftExp->value);
                } else if (expr->operator == DEC) {
                    result = createResultExpression(leftExp->type, leftExp->pointer, --leftExp->value);
                } 
                return result;
            } 
            break;

        case POS_FIXA:
            printf("pos fixa\n");
            
            break;
        
        default:
            printf("Tipo de expressão não suportado\n");
            return 0;
    }
    return 0;
}

void traverseASTCommand(Command *command, void **globalHash, void **localHash, Program *program, Function *currentFunction) {
    if (command == NULL) return;

    if (command->type == 9802) {
        printf("Command de expressão\n");
        evalExpression(command->condition, globalHash, localHash, program);
    }

    // Se o comando for um comando IF ou ELSE, percorra as condições e blocos
    if (command->type == IF || command->type == ELSE) {
        printf("Command de if ou else\n");
        evalExpression(command->condition, globalHash, localHash, program);
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
        traverseASTCommand(command->elseStatement, globalHash, localHash, program, currentFunction);
    }

    // Se o comando for um comando WHILE ou DO-WHILE, percorra a condição e o bloco
    if (command->type == WHILE || command->type == DO) {
        printf("Command de while ou do-while\n");
        evalExpression(command->condition, globalHash, localHash, program);
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
    }

    // Se o comando for um comando FOR, percorra a inicialização, condição, incremento e bloco
    if (command->type == FOR) {
        printf("Command de for\n");
        evalExpression(command->init, globalHash, localHash, program);
        evalExpression(command->condition, globalHash, localHash, program);
        evalExpression(command->increment, globalHash, localHash, program);
        traverseASTCommand(command->then, globalHash, localHash, program, currentFunction);
    }

    // Se o comando for um comando PRINTF ou SCANF, percorra os argumentos
    if (command->type == PRINTF || command->type == SCANF) {
        printf("Command de printf ou scanf\n");
        evalExpression(command->auxPrint, globalHash, localHash, program);
    }

    if (command->type == RETURN) {
        printf("Command de return\n");
        functionWithNoReturn = 1;
        if (currentFunction->returnType == VOID) {
            if (command->condition) {
                HashNode *auxFunc = getIdentifierNode(globalHash, currentFunction->name);
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: return with a value, in function returning void", auxFunc->line, auxFunc->column);
                printLineError(auxFunc->line, auxFunc->column);
                freeAST(program);
                exit(0);
            }
        } else {
            if (!command->condition) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: return with no value, in function returning non-void", command->auxToken->line, command->auxToken->column);
                printLineError(command->auxToken->line, command->auxToken->column);
                freeAST(program);
                exit(0);
            }
        }
        if (command->condition) {
            ResultExpression *returnAux = evalExpression(command->condition, globalHash, localHash, program);
            printf("retornou %d %d\n", returnAux->type, currentFunction->returnType);
            if (returnAux->type != currentFunction->returnType) {
                if (textBefore) printf("\n");
                char *type1 = getExactType(returnAux->type, returnAux->pointer);
                char *type2 = getExactType(currentFunction->returnType, currentFunction->pointer);
                printf("error:semantic:%d:%d: incompatible types when returning type '%s' but '%s' was expected", command->auxToken->line, command->auxToken->column, type1, type2);
                free(type1);
                free(type2);
                printLineError(command->auxToken->line, command->auxToken->column);
                freeAST(program);
                exit(0);
            }
        }
    }

    // Se o comando for um comando RETURN ou EXIT, percorra a expressão
    if (command->type == EXIT) {
        printf("Command de exit\n");
        if (command->condition) evalExpression(command->condition, globalHash, localHash, program);
    }

    command = command->next;
}

int traverseAST(Program *program) {
    if (!program) return -1;
    // Percorra as funções na lista de funções
    Function *currentFunction = program->functionsList;
    while (currentFunction != NULL) {

        printf("Function: %s\n", currentFunction->name);
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

// void freeExpressions(Expression *expression) {
//     if (!expression) return;

//     if (expression->dimension) {
//         Dimension *dim = expression->dimension;
//         while (dim) {
//             Dimension *dim2 = dim->next;
//             if (dim->size) free(dim->size);
//             free(dim);
//             dim = dim2;
//         }
//     }
//     if (expression->extra) free(expression->extra);
//     if (expression->ternary) free(expression->ternary);
//     if (expression->value) free(expression->value);

//     Expression *left = expression->left;
//     Expression *right = expression->right;

//     free(expression);

//     freeExpressions(left);
//     freeExpressions(right);
// }

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