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
    HashNode *hashNodeTemp = NULL;

    int auxLeftPointer, auxRightPointer;
    int auxLeftType, auxRightType;
    int auxLeftValor, auxRightValor;

    int leftType, rightType;
    int leftReg, rightReg;
    int tReg, regS;  // auxiliares

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
            left = evalExpression(expr->left, globalHash, localHash, program);
            right = evalExpression(expr->right, globalHash, localHash, program);

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

            switch (expr->operator) {
                case ASSIGN:
                    if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
                        // printf("VECTOR ASSIGN $ t %d \n", left->registerNumber);
                        printStoreIntoArray(left->registerNumber, rightType, rightReg);
                        result->registerType = 0;
                        regS = left->registerNumber;

                    } else if (left->auxIdNode && ((HashNode *)left->auxIdNode)->isGlobal) {
                        // printf("STORING INTO GLOBAL VARIABLE = \n");
                        freeRegister(left->registerType, left->registerNumber);
                        printStoreIntGlobal(rightType, rightReg, ((HashNode *)left->auxIdNode)->varId);
                        result->registerType = 0;

                    } else {
                        if (((HashNode *)left->auxIdNode)->sRegister == -1) {
                            // printf("%s sem sRegister\n", ((HashNode *)left->auxIdNode)->varId);
                            if (auxLeftType == CHAR && auxLeftPointer == 1) {
                                right->str[strlen(right->str) - 1] = '\0';
                                strcpy(right->str, right->str + 1);
                                regS = printDeclareString(((HashNode *)left->auxIdNode)->varId, right->str);
                                result->registerType = 1;
                                result->registerNumber = regS;
                                ((HashNode *)left->auxIdNode)->sRegister = regS;
                                strcpy(((HashNode *)left->auxIdNode)->string, right->str);

                            } else {
                                if (expr->left->type == UOP) {
                                    printStoreInAddress(left->registerType, left->registerNumber, rightType, rightReg);

                                } else {
                                    regS = printAssignment(rightType, rightReg);
                                    ((HashNode *)left->auxIdNode)->sRegister = regS;
                                }
                            }

                        } else {
                            if (auxLeftType == CHAR && auxLeftPointer == 1) {
                                right->str[strlen(right->str) - 1] = '\0';
                                strcpy(right->str, right->str + 1);
                                regS = printDeclareString(((HashNode *)left->auxIdNode)->varId, right->str);
                                result->registerType = 1;
                                result->registerNumber = regS;
                                strcpy(((HashNode *)left->auxIdNode)->string, right->str);

                            } else {
                                if (expr->left->type == UOP) {
                                    printStoreInAddress(left->registerType, left->registerNumber, rightType, rightReg);

                                } else {
                                    regS = left->registerNumber;
                                    printAssignmentToReg(rightType, rightReg, regS);
                                }
                            }
                        }
                        result->registerType = 1;
                    }
                    result->registerNumber = regS;
                    hashNodeTemp = getIdentifierNode(localHash, expr->identifier);
                    if (!hashNodeTemp) hashNodeTemp = getIdentifierNode(globalHash, expr->identifier);
                    if (hashNodeTemp) setAssign(hashNodeTemp, result->assign);
                    hashNodeTemp = NULL;
                    return result;
                    break;

                case ADD_ASSIGN:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
                    tReg = printArithmeticsOps(left->registerType, left->registerNumber, right->registerType, right->registerNumber, "add");

                    if (left->auxIdNode && ((HashNode *)left->auxIdNode)->isGlobal) {
                        // printf("STORING INTO GLOBAL VARIABLE += \n");
                        freeRegister(left->registerType, left->registerNumber);
                        printStoreIntGlobal(0, tReg, ((HashNode *)left->auxIdNode)->varId);
                        result->registerType = 0;
                        result->registerNumber = left->registerNumber;

                    } else {
                        printAssignmentToReg(0, tReg, left->registerNumber);
                        result->registerNumber = left->registerNumber;
                        result->registerType = left->registerType;
                    }
                    hashNodeTemp = getIdentifierNode(localHash, expr->identifier);
                    if (!hashNodeTemp) hashNodeTemp = getIdentifierNode(globalHash, expr->identifier);
                    if (hashNodeTemp) setAssign(hashNodeTemp, result->assign);
                    hashNodeTemp = NULL;
                    return result;
                    break;

                case MINUS_ASSIGN:
                    result = createResultExpression(left->typeVar, left->pointer, auxLeftValor - auxRightValor);
                    tReg = printArithmeticsOps(left->registerType, left->registerNumber, right->registerType, right->registerNumber, "sub");

                    if (left->auxIdNode && ((HashNode *)left->auxIdNode)->isGlobal) {
                        // printf("STORING INTO GLOBAL VARIABLE -= \n");
                        freeRegister(left->registerType, left->registerNumber);
                        printStoreIntGlobal(0, tReg, ((HashNode *)left->auxIdNode)->varId);
                        result->registerType = 0;
                        result->registerNumber = left->registerNumber;

                    } else {
                        printAssignmentToReg(0, tReg, left->registerNumber);
                        result->registerNumber = left->registerNumber;
                        result->registerType = left->registerType;
                    }
                    hashNodeTemp = getIdentifierNode(localHash, expr->left->identifier);
                    if (!hashNodeTemp) hashNodeTemp = getIdentifierNode(globalHash, expr->left->identifier);
                    if (hashNodeTemp) setAssign(hashNodeTemp, result->assign);
                    hashNodeTemp = NULL;
                    return result;
                    break;

                case MINUS:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor - auxRightValor);
                    int tReg = printArithmeticsOps(leftType, leftReg, rightType, rightReg, "sub");
                    result->registerType = 0;
                    result->registerNumber = tReg;
                    return result;
                    break;

                case PLUS:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
                    tReg = printArithmeticsOps(leftType, leftReg, rightType, rightReg, "add");
                    result->registerType = 0;
                    result->registerNumber = tReg;
                    return result;
                    break;

                case MULTIPLY:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor * auxRightValor);
                    tReg = printArithmeticsOps(leftType, leftReg, rightType, rightReg, "mul");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case DIVIDE:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor / auxRightValor);
                    tReg = printDivisionOps(leftType, leftReg, rightType, rightReg, "mflo");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case REMAINDER:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor % auxRightValor);
                    tReg = printDivisionOps(leftType, leftReg, rightType, rightReg, "mfhi");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case BITWISE_OR:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor | auxRightValor);
                    tReg = printBitwiseOps(leftType, leftReg, rightType, rightReg, "or");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case BITWISE_AND:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor & auxRightValor);
                    tReg = printBitwiseOps(leftType, leftReg, rightType, rightReg, "and");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case BITWISE_XOR:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor ^ auxRightValor);
                    tReg = printBitwiseOps(leftType, leftReg, rightType, rightReg, "xor");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case LOGICAL_AND:
                    result = createResultExpression(INT, 0, auxLeftValor && auxRightValor);
                    tReg = printLogicalAnd(leftType, leftReg, rightType, rightReg, abs((int)((intptr_t)expr)));
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case LOGICAL_OR:
                    result = createResultExpression(INT, 0, auxLeftValor || auxRightValor);
                    tReg = printLogicalOr(leftType, leftReg, rightType, rightReg, abs((int)((intptr_t)expr)));
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case LESS_THAN:
                    result = createResultExpression(INT, 0, left->assign < right->assign);
                    tReg = printRelationalOps(leftType, leftReg, rightType, rightReg, "slt");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case LESS_EQUAL:
                    result = createResultExpression(INT, 0, left->assign <= right->assign);
                    tReg = printRelationalOps(leftType, leftReg, rightType, rightReg, "sle");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case GREATER_THAN:
                    result = createResultExpression(INT, 0, left->assign > right->assign);
                    tReg = printRelationalOps(leftType, leftReg, rightType, rightReg, "sgt");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case GREATER_EQUAL:
                    result = createResultExpression(INT, 0, left->assign >= right->assign);
                    tReg = printRelationalOps(leftType, leftReg, rightType, rightReg, "sge");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case EQUAL:
                    result = createResultExpression(INT, 0, left->assign == right->assign);
                    tReg = printRelationalOps(leftType, leftReg, rightType, rightReg, "seq");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case NOT_EQUAL:
                    result = createResultExpression(INT, 0, left->assign != right->assign);
                    tReg = printRelationalOps(leftType, leftReg, rightType, rightReg, "sne");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case R_SHIFT:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor >> auxRightValor);
                    tReg = printBitwiseOps(leftType, leftReg, rightType, rightReg, "srlv");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
                    break;

                case L_SHIFT:
                    result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor << auxRightValor);
                    tReg = printBitwiseOps(leftType, leftReg, rightType, rightReg, "sllv");
                    result->registerNumber = tReg;
                    result->registerType = 0;
                    return result;
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
    Command *t = NULL;
    switch (command->type) {
        case IF:
            ResultExpression *ifResult = evalExpression(command->condition, globalHash, localHash, program);
            // printf("ifs %p\n", command);

            int ifLine = abs((int)((intptr_t)command->then));
            int elseLine = -1;
            if (command->elseStatement) {
                elseLine = abs((int)((intptr_t)command->elseStatement));
            } else {
                elseLine = ifLine;
            }
            printIf(ifResult->registerType, ifResult->registerNumber, elseLine);
            t = command->then;
            while (t) {
                traverseASTCommand(t, globalHash, localHash, program, currentFunction);
                t = t->next;
            }
            printJump("exit_if_", ifLine);
            printLabel("else_", elseLine);
            Command *t2 = command->elseStatement;
            while (t2) {
                traverseASTCommand(t2, globalHash, localHash, program, currentFunction);
                t2 = t2->next;
            }
            printLabel("exit_if_", ifLine);
            break;

        case DO_WHILE:
        case WHILE:
            int whileLine = abs((int)((intptr_t)command));
            if (command->type == WHILE)
                printJump("while_teste_", whileLine);
            printLabel("while_corpo_", whileLine);
            t = command->then;
            while (t) {
                traverseASTCommand(t, globalHash, localHash, program, currentFunction);
                t = t->next;
            }
            printLabel("while_teste_", whileLine);
            ResultExpression *whileResult = NULL;
            whileResult = evalExpression(command->condition, globalHash, localHash, program);
            printWhile(whileResult->registerType, whileResult->registerNumber, whileLine);
            break;

        case FOR:
            int forLine = abs((int)((intptr_t)command));
            evalExpression(command->init, globalHash, localHash, program);
            printJump("for_teste_", forLine);
            printLabel("for_corpo_", forLine);
            t = command->then;
            while (t) {
                traverseASTCommand(t, globalHash, localHash, program, currentFunction);
                t = t->next;
            }
            evalExpression(command->increment, globalHash, localHash, program);
            printLabel("for_teste_", forLine);
            ResultExpression *forResult = NULL;
            forResult = evalExpression(command->condition, globalHash, localHash, program);
            printFor(forResult->registerType, forResult->registerNumber, forLine);
            break;

        case PRINTF:
            if (command->auxPrint) {
                Expression *next = command->auxPrint;
                ResultExpression *toPrint = NULL;

                // printf("1.String original: %s\n", command->string);
                char *restOfString = NULL;

                char *stringWithoutFormat = calloc(strlen(command->string) + 1, sizeof(char));
                strcpy(stringWithoutFormat, command->string + 1);  // copy the 7 string without the "
                // while (next) {
                //     printf("expr inprint %p %d\n", next, next->type);
                //     next = next->nextExpr;
                // }
                // exit(0);
                // If we got to this block there is for sure at least one %d in this print
                while (next) {
                    toPrint = evalExpression(next, globalHash, localHash, program);
                    // printf("Return aux print: reg %d %d value %d var %s %d \n", toPrint->registerType, toPrint->registerNumber, toPrint->assign, ((HashNode*)toPrint->auxIdNode)->varId, ((HashNode*)toPrint->auxIdNode)->kind);
                    next = next->nextExpr;
                    if (toPrint) {
                        if (toPrint->auxIdNode) {
                            if (((HashNode *)toPrint->auxIdNode)->kind == VECTOR) {
                                toPrint->registerNumber = printLoadFromArray(toPrint->registerNumber);
                                toPrint->registerType = 0;
                            }
                        }
                    }

                    int printing = 0;
                    char *formatSpecifier = strstr(stringWithoutFormat, "%d");  // pointer to the first occurrence of %d
                    if (formatSpecifier) {
                        printing = INT;
                    } else {
                        formatSpecifier = strstr(stringWithoutFormat, "%s");
                        if (formatSpecifier) {
                            printing = STRING;
                        } else {
                            formatSpecifier = strstr(stringWithoutFormat, "%c");
                            if (formatSpecifier) {
                                printing = CHAR;
                            }
                        }
                    }
                    // printf("before %s\n", stringWithoutFormat);
                    // printf("2.formatSpecifier %s\n", formatSpecifier);
                    if (restOfString) free(restOfString);
                    restOfString = calloc(strlen(formatSpecifier) + 1, sizeof(char));
                    strcpy(restOfString, formatSpecifier + 2);
                    restOfString[strlen(restOfString)] = '\0';  // remove the " and null terminate
                    // printf("3.rest %s\n", restOfString);
                    if (formatSpecifier != NULL) *formatSpecifier = '\0';  // Null-terminate the string at the format specifier
                    printString(stringWithoutFormat, abs((int)((intptr_t)toPrint)));
                    if (printing == INT)
                        printInteger(toPrint->registerType, toPrint->registerNumber);
                    else if (printing == CHAR)
                        printCharacter(toPrint->registerType, toPrint->registerNumber);
                    else if (printing == STRING)
                        printStringVar(toPrint->registerType, toPrint->registerNumber);

                    free(stringWithoutFormat);
                    stringWithoutFormat = calloc(strlen(restOfString) + 1, sizeof(char));
                    strcpy(stringWithoutFormat, restOfString);
                }
                if (strlen(restOfString) > 0) {
                    restOfString[strlen(restOfString) - 1] = '\0';
                    // printf("4.rest %s\n", restOfString);
                    printString(restOfString, rand() % 1000);
                }
                if (restOfString) free(restOfString);
                if (stringWithoutFormat) free(stringWithoutFormat);

            } else {
                // remove the " " from the string
                // printf("2.String original %s\n", command->string);
                char *fixedString = calloc(strlen(command->string) - 1, sizeof(char));
                strncpy(fixedString, command->string + 1, strlen(command->string) - 2);
                fixedString[strlen(command->string) - 2] = '\0';  // Null-terminate the string
                printString(fixedString, abs((int)((intptr_t)fixedString)));
                free(fixedString);
            }
            break;

        case SCANF:
            HashNode *node = getIdentifierNode(localHash, command->identifier);
            if (!node) node = getIdentifierNode(globalHash, command->identifier);
            if (!node) printf("Erro: Variável %s não declarada no scanf\n", command->identifier);

            int sReg = printScanInt(node->sRegister, node->varId, node->isGlobal);
            node->sRegister = sReg;
            break;

        case RETURN:
            if (currentFunction->returnType == VOID && currentFunction->pointer == 0) {
                if (command->condition) printf("Erro: Função %s não pode retornar valor\n", currentFunction->name);
                if (strcmp(currentFunction->name, "main")) {  // doesnot print jr $ra for main
                    loadFromStack();
                    loadTRegisters(tRegsAlive);
                    // free(tRegsAlive);
                    printReturn();
                }
            } else {
                if (!command->condition) printf("Erro: Função %s deve retornar valor\n", currentFunction->name);
                ResultExpression *returnAux = evalExpression(command->condition, globalHash, localHash, program);
                if (returnAux->auxIdNode) {
                    // printf("\n>>>>> varId %s %d\n", ((HashNode*)returnAux->auxIdNode)->varId, ((HashNode*)returnAux->auxIdNode)->sRegister);
                    if (((HashNode *)returnAux->auxIdNode)->sRegister == -1) {
                        int null = printConstant(0);
                        int s = printAssignment(0, null);
                        setSRegisterInHash((HashNode *)returnAux->auxIdNode, s);
                        returnAux->registerType = 1;
                        returnAux->registerNumber = s;
                    }
                }
                printReturnToV0(returnAux->registerType, returnAux->registerNumber);
                if (strcmp(currentFunction->name, "main")) {
                    loadFromStack();
                    loadTRegisters(tRegsAlive);
                    // free(tRegsAlive);
                    printReturn();
                }  // doesnot print jr $ra for main
            }
            break;

        case EXIT:
            if (command->condition) {
                ResultExpression *status = evalExpression(command->condition, globalHash, localHash, program);
                printf("\t# exit with status %d", status->assign);
                printExit();
            }
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
