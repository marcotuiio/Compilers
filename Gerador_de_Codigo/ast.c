#include "ast.h"

#include <stdint.h>

#include "asm.h"
#include "hash.h"
#include "sintatico.tab.h"

int *tRegsAlive = NULL;

int inAtrib = 0;

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

ExpParam *createExpParam(Expression *exp, ExpParam *next) {
    ExpParam *newExpParam = calloc(1, sizeof(ExpParam));
    newExpParam->exp = exp;
    newExpParam->next = next;
    return newExpParam;
}

Expression *createExpression(int type, int operator, void * left, void *right) {
    Expression *newExp = calloc(1, sizeof(Expression));
    newExp->type = type;
    newExp->operator= operator;
    newExp->left = left;
    newExp->right = right;
    newExp->dimension = NULL;
    newExp->ternaryCondition = NULL;
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

Dimension *createDimensionWithExp(Expression *exp) {
    Dimension *newDim = calloc(1, sizeof(Dimension));
    newDim->exp = exp;
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

Command *createDoWhileStatement(Expression *condition, void *then, void *next) {
    Command *newDoWhile = calloc(1, sizeof(Command));
    newDoWhile->type = DO_WHILE;
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

Command *createScanStatement(char *string, char *identifier, void *next) {
    Command *newScan = calloc(1, sizeof(Command));
    newScan->type = SCANF;
    newScan->string = string;
    newScan->identifier = identifier;
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
    newResult->registerType = -1;
    newResult->registerNumber = -1;
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

    int leftType, rightType;
    int leftReg, rightReg;

    // printf("evalExpression %p %d %d %d\n", expr, expr->type, expr->operator, expr->value->type);

    switch (expr->type) {
        case PRIMARIA:

            switch (expr->operator) {
                case INT:
                case CHAR:
                    result = createResultExpression(expr->type, expr->pointer, expr->assign);
                    int regT = printConstant(result->assign);
                    result->registerType = 0;
                    result->registerNumber = regT;
                    return result;
                    break;

                case STRING:
                    result = createResultExpression(STRING, 0, 0);
                    strcpy(result->str, expr->string);
                    // printf("1. string na ast %s \n", result->str);
                    return result;
                    break;

                case ID:
                    hashNode = getIdentifierNode(localHash, expr->identifier);
                    if (!hashNode) hashNode = getIdentifierNode(globalHash, expr->identifier);
                    if (!hashNode) printf("Erro: Variável %s não declarada\n", expr->identifier);

                    if (hashNode->typeVar == VOID) {
                        result = createResultExpression(VOID, hashNode->pointer, hashNode->assign);
                        if (hashNode->kind == VECTOR) result->pointer = 1;
                        result->auxIdNode = hashNode;
                        if (hashNode->isConstant || hashNode->isGlobal) {
                            if (!inAtrib) {
                                result->registerNumber = printLoadIntGlobal(hashNode->varId);
                                result->registerType = 0;
                            }
                        } else {
                            if (hashNode->pointer > 0) {
                                result->registerType = 1;
                                result->registerNumber = hashNode->sRegister;
                            }
                        }
                        return result;

                    } else if (hashNode->typeVar == INT || (hashNode->typeVar == CHAR && hashNode->pointer == 0)) {
                        result = createResultExpression(hashNode->typeVar, hashNode->pointer, hashNode->assign);
                        if (hashNode->kind == VECTOR) result->pointer = 1;
                        result->auxIdNode = hashNode;
                        if (hashNode->isConstant || hashNode->isGlobal) {
                            if (!inAtrib) {
                                result->registerNumber = printLoadIntGlobal(hashNode->varId);
                                result->registerType = 0;
                            }
                        } else {
                            result->registerType = 1;
                            result->registerNumber = hashNode->sRegister;
                        }
                        return result;
                        break;

                    } else if (hashNode->typeVar == CHAR && hashNode->pointer == 1) {
                        result = createResultExpression(CHAR, 1, 0);
                        strcpy(result->str, expr->string);
                        result->auxIdNode = hashNode;
                        return result;
                        break;
                    }
                    break;

                default:
                    printf("Erro: Expressao primaria desconhecida\n");
                    break;
            }

        case BOP:

            switch (expr->operator) {
                case ASSIGN:
                    break;

                case ADD_ASSIGN:
                case MINUS_ASSIGN:
                    break;

                case PLUS:
                case MINUS:
                    break;

                case MULTIPLY:
                case DIVIDE:
                case REMAINDER:
                case BITWISE_OR:
                case BITWISE_AND:
                case BITWISE_XOR:
                    break;

                case LOGICAL_AND:
                case LOGICAL_OR:
                    break;

                case LESS_THAN:
                case LESS_EQUAL:
                case GREATER_THAN:
                case GREATER_EQUAL:
                case EQUAL:
                case NOT_EQUAL:
                    break;

                case R_SHIFT:
                case L_SHIFT:
                    break;

                default:
                    printf("Erro: Operador binario desconhecido\n");
                    break;
            }

            break;

        case UOP:

            switch (expr->operator) {
                case INC:
                case DEC:
                    if (expr->preOrPost == 1) {
                        printf("pre incremento ou decremento\n");
                    } else if (expr->preOrPost == 2) {
                        printf("pos incremento ou decremento\n");
                    }
                    break;

                case BITWISE_NOT:
                case PLUS:
                case MINUS:
                    break;

                case NOT:
                    break;

                case MULTIPLY:
                    break;

                default:
                    printf("Erro: Operador unario desconhecido\n");
            }

            break;

        case TERNARY:

            ResultExpression *condition = evalExpression(expr->ternaryCondition, globalHash, localHash, program);
            printTernary(condition->registerType, condition->registerNumber, abs((int)((intptr_t)condition)));
            printLabel("true_ternary_", abs((int)((intptr_t)condition)));
            left = evalExpression(expr->left, globalHash, localHash, program);
            printJump("end_ternary_", abs((int)((intptr_t)condition)));
            printLabel("false_ternary_", abs((int)((intptr_t)condition)));
            right = evalExpression(expr->right, globalHash, localHash, program);
            printLabel("end_ternary_", abs((int)((intptr_t)condition)));

            leftType = left->registerType;
            leftReg = left->registerNumber;
            rightType = right->registerType;
            rightReg = right->registerNumber;

            if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
                leftReg = printLoadFromArray(left->registerNumber);
                leftType = 0;
            }
            if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
                rightReg = printLoadFromArray(right->registerNumber);
                rightType = 0;
            }
            // printf("left reg %d %d right reg %d %d\n", leftType, leftReg, rightType, rightReg);
            if (condition->assign) {
                result = createResultExpression(auxLeftType, auxLeftPointer, left->assign);
                result->registerNumber = left->registerNumber;
                result->registerType = left->registerType;
                if (rightType == 0) freeRegister(rightType, rightReg);

            } else {
                result = createResultExpression(auxRightType, auxRightPointer, right->assign);
                result->registerNumber = right->registerNumber;
                result->registerType = right->registerType;
                if (leftType == 0) freeRegister(leftType, leftReg);
            }
            return result;
            break;

        case ARRAY_CALL:
            break;

        case FUNCTION_CALL:
            break;

        default:
            printf("Erro: Tipo de expressão desconhecido\n");
            break;
    }

    return 0;
}

void traverseASTCommand(Command *command, void **globalHash, void **localHash, Program *program, Function *currentFunction) {
    // printf(">> AST Comando %d %p %d\n", command ? command->type : -1, command, command->visited);
    if (!command || command->visited) return;
    command->visited = 1;

    // printf("traverseASTCommand %d %p %p\n",command->type, command, command->next);
    // Para cada comando percorrer seus blocos de comandos e expressoes relacionadas recursivamente
    // Atencao as expressoes condicionais das estruturas, qua NAO PODEM ter expressoes de retorno tipo void

    switch (command->type) {
        case IF:
            break;

        case DO_WHILE:
            break;

        case WHILE:
            break;

        case FOR:
            break;

        case PRINTF:
            break;

        case SCANF:
            break;

        case RETURN:
            break;

        case EXIT:
            break;

        case LISTA_EXP_COMANDO:
            evalExpression(command->condition, globalHash, localHash, program);
            traverseASTCommand(command->next, globalHash, localHash, program, currentFunction);
            break;

        default:
            printf("Erro: Comando desconhecido!\n");
            break;
    }
}

void lookForNodeInHashWithExpr(void **globalHash, void **localHash, Program *program) {
    if (!localHash) return;
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *node = (HashNode *)localHash[i];
        ResultExpression *atrib = NULL;
        while (node) {
            // printf("evaluanting hash %s %d %d \n", node->varId, node->kind, node->isGlobal);
            if (node->kind == FUNCTION || node->isConstant) {
                node = node->next;
                continue;
            }
            if (localHash == globalHash) {  // save globals to memory
                node->isGlobal = 1;
                int size = 0;
                if (node->kind == VAR) {
                    if (node->typeVar == NUM_INT || node->typeVar == INT || node->typeVar == VOID || node->pointer > 0)
                        size = 32;
                    else
                        size = 8;
                    printGlobalVariableInMemory(size, node->varId);
                }
            }

            if (node->kind == VECTOR) {
                Dimension *d = node->dimensions;
                int size = 0;
                while (d) {
                    size = size + d->size;
                    d = d->next;
                }
                // printf(">>>| size of %s = %d\n", node->varId, size);
                int s = printDeclareArray(node->varId, size, node->isGlobal);
                setSRegisterInHash(node, s);
            }

            if (node->hashExpr) {
                // printf(">>>>>>>>>>>>>> this noda has atrib expr %p %s = %p %d\n", node, node->varId, node->hashExpr, ((Expression*)node->hashExpr)->type);
                atrib = evalExpression(node->hashExpr, globalHash, localHash, program);
                // printf("<<<<<<<<<<<<<< retornou %d %d %d %s\n\n", atrib->typeVar, atrib->pointer, atrib->assign, atrib->str);

                int assignType, assignPointer = atrib->pointer;
                // printf("\nassignType %d %d\n", atrib->typeVar, atrib->assign);
                if (atrib->typeVar == CHAR) {
                    assignType = CHAR;
                } else if (atrib->typeVar == INT) {
                    assignType = INT;
                } else if (atrib->typeVar == STRING) {
                    assignType = CHAR;
                    assignPointer = 1;
                } else {
                    assignType = VOID;
                }

                if (globalHash == localHash) {  // globals must be stored and loaded in and not to $s register
                    // printf("nao to sabendo carregar variaveis globais ja inicializas :D %s = %d\n", node->varId, atrib->assign);
                    setGlobalVarAssign(node->varId, atrib->assign);

                } else {
                    if (assignType == CHAR && assignPointer == 1) {  // string
                        atrib->str[strlen(atrib->str) - 1] = '\0';
                        strcpy(atrib->str, atrib->str + 1);
                        int regS = printDeclareString(node->varId, atrib->str);
                        setSRegisterInHash(node, regS);
                        strcpy(node->string, atrib->str);

                    } else {
                        int regS = printAssignment(atrib->registerType, atrib->registerNumber);
                        setSRegisterInHash(node, regS);
                        setAssign(node, atrib->assign);
                    }
                }
            }
            node = node->next;
        }
    }
}

int traverseAST(Program *program) {
    if (!program) return -1;

    // Percorra as funções na lista de funções
    printf("\n.data\n");
    printDefines();
    lookForNodeInHashWithExpr(program->hashTable, program->hashTable, program);  // loading global variables (defines not include)
    printf(".text\n");

    Function *currentFunction = program->functionsList;
    while (currentFunction != NULL) {
        for (int i = 0; i < 10; i++) freeRegister(0, i);
        for (int i = 0; i < 8; i++) freeRegister(1, i);
        HashNode *funcNode = getIdentifierNode(program->hashTable, currentFunction->name);
        printFunctions(currentFunction->name);
        if (strcmp(currentFunction->name, "main")) {  // if not in main save context
            tRegsAlive = calloc(10, sizeof(int));
            storeTRegisters(tRegsAlive);
            storeInStack();
        } else {
            printGlobalVarAssign();
        }
        // printf("Function: %s (%d) %p has hash %p\n", currentFunction->name, funcNode->qntdParams, currentFunction, currentFunction->hashTable);
        printFunctionParams(currentFunction->name, funcNode->qntdParams);
        lookForNodeInHashWithExpr(program->hashTable, currentFunction->hashTable, program);
        // Percorra os comandos na função
        Command *command = currentFunction->commandList;
        while (command != NULL) {
            traverseASTCommand(command, program->hashTable, currentFunction->hashTable, program, currentFunction);
            command = command->next;
        }
        if (strcmp(currentFunction->name, "main")) {  // does not print jr $ra return for main
            loadFromStack();
            loadTRegisters(tRegsAlive);
            free(tRegsAlive);
            printReturn();
        }
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
                free(cmd->condition);
            }
            if (cmd->init) {
                free(cmd->init);
            }
            if (cmd->increment) {
                free(cmd->increment);
            }
            if (cmd->auxPrint) {
                free(cmd->auxPrint);
            }
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