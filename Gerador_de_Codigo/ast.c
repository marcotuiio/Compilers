#include "ast.h"

#include <stdint.h>

// #include "asm.h"
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

// ExpParam *createExpParam(Expression *exp, ExpParam *next) {
//     ExpParam *newExpParam = calloc(1, sizeof(ExpParam));
//     newExpParam->exp = exp;
//     newExpParam->next = next;
//     return newExpParam;
// }

Expression *createExpression(int type, int operator, void *left, void *right) {
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

// int countDimension(void *d) {
//     Dimension *dimen = d;
//     if (!dimen) return 0;
//     int count = 1;
//     Dimension *aux = dimen;
//     while (aux->next) {
//         count++;
//         aux = aux->next;
//     }
//     return count;
// }


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

// ResultExpression *createResultExpression(int type, int pointer, int value) {
//     ResultExpression *newResult = calloc(1, sizeof(ResultExpression));
//     newResult->typeVar = type;
//     newResult->pointer = pointer;
//     newResult->assign = value;
//     newResult->registerType = -1;
//     newResult->registerNumber = -1;
//     return newResult;
// }

// // ResultExpression *evalExpression(Expression *expr, void **globalHash, void **localHash, Program *program) {
// //     if (!expr) return NULL;

// //     ResultExpression *left = NULL;
// //     ResultExpression *right = NULL;
// //     ResultExpression *result = NULL;

// //     HashNode *hashNode = NULL;

// //     int auxLeftPointer, auxRightPointer;
// //     int auxLeftType, auxRightType;
// //     int auxLeftValor, auxRightValor;

// //     int leftType, rightType;
// //     int leftReg, rightReg;

// //     // printf("evalExpression %p %d %d %d\n", expr, expr->type, expr->operator, expr->value->type);

// //     if (expr->isHeadOfList == LISTA_EXP) {
// //         expr->isHeadOfList = 0;
// //         while (expr) {
// //             evalExpression(expr, globalHash, localHash, program);
// //             expr = expr->nextExpr;
// //         }
// //         return NULL;
// //     }

// //     switch (expr->type) {
// //         case NUMEROS:
// //             // printf("<<<< expr %p type %d \n", expr, expr->value->type);
// //             if (expr->value->type == NUM_INT) {
// //                 result = createResultExpression(expr->value->type, expr->value->pointer, atoi(expr->value->valor));
// //                 int regT = printConstant(mipsFile, result->assign);
// //                 result->registerType = 0;
// //                 result->registerNumber = regT;
// //                 return result;
// //             }
// //             printf("Numero que nao e int\n");
// //             break;

// //         case PRIMARIA:
// //             if (expr->operator== ID) {
// //                 hashNode = getIdentifierNode(localHash, expr->value->valor);
// //                 if (!hashNode) hashNode = getIdentifierNode(globalHash, expr->value->valor);
// //                 if (!hashNode) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: '%s' undeclared", expr->value->line, expr->value->column, expr->value->valor);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }

// //                 if (!hashNode->isConstant && (defineAux || dimensionAux)) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: '%s' initializer element is not constant", expr->value->line, expr->value->column, expr->value->valor);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }
// //                 // printf("Achei %p %s %d %d (kind = %d) = %d | const %d\n", hashNode, hashNode->varId, hashNode->typeVar, hashNode->pointer, hashNode->kind, hashNode->assign, hashNode->isConstant);

// //                 if (hashNode->typeVar == VOID) {
// //                     result = createResultExpression(VOID, hashNode->pointer, hashNode->assign);
// //                     if (hashNode->kind == VECTOR) result->pointer = 1;
// //                     result->auxIdNode = hashNode;
// //                     if (hashNode->isConstant || hashNode->isGlobal) {
// //                         if (!inAtrib) {
// //                             result->registerNumber = printLoadIntGlobal(mipsFile, hashNode->varId);
// //                             result->registerType = 0;
// //                         }
// //                     } else {
// //                         if (hashNode->pointer > 0) {
// //                             result->registerType = 1;
// //                             result->registerNumber = hashNode->sRegister;
// //                         }
// //                     }
// //                     return result;

// //                 } else if (hashNode->typeVar == NUM_INT || hashNode->typeVar == INT) {
// //                     result = createResultExpression(hashNode->typeVar, hashNode->pointer, hashNode->assign);
// //                     if (hashNode->kind == VECTOR) {
// //                         result->pointer = 1;
// //                     }
// //                     // printf("AAAAA id %s reg %d = fake %d\n", hashNode->varId, hashNode->sRegister, hashNode->assign);
// //                     result->auxIdNode = hashNode;
// //                     if (hashNode->isConstant || hashNode->isGlobal) {
// //                         if (!inAtrib) {
// //                             result->registerNumber = printLoadIntGlobal(mipsFile, hashNode->varId);
// //                             result->registerType = 0;
// //                         }
// //                     } else {
// //                         result->registerType = 1;
// //                         result->registerNumber = hashNode->sRegister;
// //                     }
// //                     return result;

// //                 } else if (hashNode->typeVar == CHARACTER || hashNode->typeVar == CHAR) {
// //                     result = createResultExpression(hashNode->typeVar, hashNode->pointer, hashNode->assign);
// //                     if (hashNode->kind == VECTOR) result->pointer = 1;
// //                     result->auxIdNode = hashNode;
// //                     if (hashNode->isConstant || hashNode->isGlobal) {
// //                         if (!inAtrib) {
// //                             result->registerNumber = printLoadIntGlobal(mipsFile, hashNode->varId);
// //                             result->registerType = 0;
// //                         }
// //                     } else {
// //                         result->registerType = 1;
// //                         result->registerNumber = hashNode->sRegister;
// //                     }
// //                     return result;

// //                 } else if (hashNode->typeVar == STRING) {
// //                     result = createResultExpression(CHAR, 1, 0);
// //                     strcpy(result->str, expr->value->valor);
// //                     result->auxIdNode = hashNode;
// //                     return result;
// //                 }

// //             } else if (expr->operator== CHARACTER) {
// //                 result = createResultExpression(expr->value->type, expr->value->pointer, expr->value->valor[0]);
// //                 int regT = printConstant(mipsFile, result->assign);
// //                 result->registerType = 0;
// //                 result->registerNumber = regT;
// //                 return result;

// //             } else if (expr->operator== STRING) {
// //                 result = createResultExpression(STRING, 0, 0);
// //                 strcpy(result->str, expr->value->valor);
// //                 // printf("1. string na ast %s \n", result->str);
// //                 return result;
// //             }
// //             break;

// //         case ATRIBUICAO:
// //             inAtrib = 1;
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             inAtrib = 0;
// //             right = evalExpression(expr->right, globalHash, localHash, program);
// //             // printf("[assign left %p %d %d %s \nright %p %d %d %d]\n", left, left->typeVar, left->pointer, ((HashNode*)left->auxIdNode)->varId, right, right->typeVar, right->pointer, right->assign);

// //             if ((left->typeVar == VOID && left->pointer == 0) || (right->typeVar == VOID && right->pointer == 0)) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             // atribuindo para constante
// //             if (left->typeVar == STRING || left->typeVar == CHARACTER) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: assignment of read-only location %s", expr->value->line, expr->value->column, expr->left->value->valor);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             // atribuindo sem ser id
// //             int auxForId = expr->left->value->type;
// //             if ((HashNode *)left->auxIdNode) {
// //                 int kindAux = ((HashNode *)left->auxIdNode)->kind;
// //                 if (kindAux == VAR || kindAux == VECTOR)
// //                     auxForId = ID;
// //             }
// //             if (auxForId != ID) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: lvalue required as left operand of assignment", expr->value->line, expr->value->column);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             padronizeTypesAndPointers(expr, left, right, &auxLeftType, &auxLeftPointer, &auxLeftValor, &auxRightType, &auxRightPointer, &auxRightValor);

// //             if (expr->operator== ASSIGN) {
// //                 if (right) {
// //                     if (auxLeftPointer != 0 || auxRightPointer != 0) {  // existem pointers envolvidos
// //                         // se forem de tipo diferente ou ponteiro diferente
// //                         if (auxLeftType != auxRightType || auxLeftPointer != auxRightPointer) {
// //                             if (textBefore) printf("\n");
// //                             char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                             char *type2 = getExactType(auxRightType, auxRightPointer);
// //                             printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
// //                             free(type1);
// //                             free(type2);
// //                             printLineError(expr->value->line, expr->value->column);
// //                             freeAST(program);
// //                             deleteMipsFileOnError(mipsFile, mipsPath);
// //                             deleteAuxFile();
// //                             exit(0);
// //                         }
// //                     }

// //                 } else {
// //                     if (auxLeftPointer != 0 || auxRightPointer != 0) {  // existem pointers envolvidos
// //                         // se forem de tipo diferente ou ponteiro diferente
// //                         if (auxLeftType != auxRightType || auxLeftPointer != auxRightPointer) {
// //                             if (textBefore) printf("\n");
// //                             char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                             char *type2 = getExactType(auxRightType, auxRightPointer);
// //                             printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
// //                             free(type1);
// //                             free(type2);
// //                             printLineError(expr->value->line, expr->value->column);
// //                             freeAST(program);
// //                             deleteMipsFileOnError(mipsFile, mipsPath);
// //                             deleteAuxFile();
// //                             exit(0);
// //                         }
// //                     }
// //                 }
// //                 // fprintf(mipsFile, "\t# assignment na ast %s %d %d\n", ((HashNode*)left->auxIdNode)->varId, left->registerNumber, left->registerType);
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxRightValor);
// //                 int regS = -1;
// //                 // fprintf(mipsFile, "\t # leftReg %s %d %d %d\n", ((HashNode *)left->auxIdNode)->varId, left->registerType, left->registerNumber, expr->left->type);

// //                 int rightType = right->registerType;
// //                 int rightReg = right->registerNumber;

// //                 if ((auxLeftType == INT || auxLeftType == VOID) && auxLeftPointer == 1 && auxRightPointer == 1) {
// //                     // printf("error:minhacabecafritou:\n");
// //                     int s = printAssignAddress(mipsFile, left->registerType, left->registerNumber, ((HashNode *)left->auxIdNode)->varId);
// //                     setSRegisterInHash(((HashNode *)left->auxIdNode), s);
// //                     result->registerType = 1;
// //                     result->registerNumber = s;
// //                     return result;
// //                 }

// //                 if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
// //                     // if (auxRightPointer == 0) {
// //                     rightReg = printLoadFromArray(mipsFile, right->registerNumber);
// //                     rightType = 0;

// //                     // } else {
// //                     //     int i = printConstant(mipsFile, 0);
// //                     //     int posic = printAccessIndexArray(mipsFile, right->registerType, right->registerNumber, ((HashNode *)right->auxIdNode)->varId, 0, i, ((HashNode *)right->auxIdNode)->isGlobal);
// //                     //     rightReg = printLoadFromArray(mipsFile, posic);
// //                     //     rightType = 0;
// //                     // }
// //                 }

// //                 if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                     // printf("VECTOR ASSIGN $ t %d \n", left->registerNumber);
// //                     printStoreIntoArray(mipsFile, left->registerNumber, rightType, rightReg);
// //                     result->registerType = 0;
// //                     regS = left->registerNumber;

// //                 } else if (left->auxIdNode && ((HashNode *)left->auxIdNode)->isGlobal) {
// //                     // printf("STORING INTO GLOBAL VARIABLE = \n");
// //                     freeRegister(left->registerType, left->registerNumber);
// //                     printStoreIntGlobal(mipsFile, rightType, rightReg, ((HashNode *)left->auxIdNode)->varId);
// //                     result->registerType = 0;

// //                 } else {
// //                     if (((HashNode *)left->auxIdNode)->sRegister == -1) {
// //                         // printf("%s sem sRegister\n", ((HashNode *)left->auxIdNode)->varId);
// //                         if (auxLeftType == CHAR && auxLeftPointer == 1) {
// //                             right->str[strlen(right->str) - 1] = '\0';
// //                             strcpy(right->str, right->str + 1);
// //                             regS = printDeclareString(mipsFile, ((HashNode *)left->auxIdNode)->varId, right->str);
// //                             result->registerType = 1;
// //                             result->registerNumber = regS;
// //                             ((HashNode *)left->auxIdNode)->sRegister = regS;
// //                             strcpy(((HashNode *)left->auxIdNode)->string, right->str);

// //                         } else {
// //                             if (expr->left->type == UNARIA) {
// //                                 printStoreInAddress(mipsFile, left->registerType, left->registerNumber, rightType, rightReg);

// //                             } else {
// //                                 regS = printAssignment(mipsFile, rightType, rightReg);
// //                                 ((HashNode *)left->auxIdNode)->sRegister = regS;
// //                             }
// //                         }

// //                     } else {
// //                         if (auxLeftType == CHAR && auxLeftPointer == 1) {
// //                             right->str[strlen(right->str) - 1] = '\0';
// //                             strcpy(right->str, right->str + 1);
// //                             regS = printDeclareString(mipsFile, ((HashNode *)left->auxIdNode)->varId, right->str);
// //                             result->registerType = 1;
// //                             result->registerNumber = regS;
// //                             strcpy(((HashNode *)left->auxIdNode)->string, right->str);

// //                         } else {
// //                             if (expr->left->type == UNARIA) {
// //                                 printStoreInAddress(mipsFile, left->registerType, left->registerNumber, rightType, rightReg);

// //                             } else {
// //                                 regS = left->registerNumber;
// //                                 printAssignmentToReg(mipsFile, rightType, rightReg, regS);
// //                             }
// //                         }
// //                     }
// //                     result->registerType = 1;
// //                 }

// //                 result->registerNumber = regS;

// //             } else if (expr->operator== ADD_ASSIGN || expr->operator== MINUS_ASSIGN) {
// //                 if (right) {
// //                     if (auxLeftPointer != 0) {
// //                         if (auxRightType != INT || auxRightType != CHAR) {
// //                             if (textBefore) printf("\n");
// //                             char *type1 = getExactType(left->typeVar, left->pointer);
// //                             char *type2 = getExactType(right->typeVar, right->pointer);
// //                             printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
// //                             free(type1);
// //                             free(type2);
// //                             printLineError(expr->value->line, expr->value->column);
// //                             freeAST(program);
// //                             deleteMipsFileOnError(mipsFile, mipsPath);
// //                             deleteAuxFile();
// //                             exit(0);
// //                         }
// //                     }
// //                 } else {
// //                     if (auxLeftPointer != 0) {
// //                         if (auxRightType != INT || auxRightType != CHAR) {
// //                             if (textBefore) printf("\n");
// //                             char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                             char *type2 = getExactType(auxRightType, auxRightPointer);
// //                             printf("error:semantic:%d:%d: incompatible types when assigning to type '%s' from type '%s'", expr->value->line, expr->value->column, type1, type2);
// //                             free(type1);
// //                             free(type2);
// //                             printLineError(expr->value->line, expr->value->column);
// //                             freeAST(program);
// //                             deleteMipsFileOnError(mipsFile, mipsPath);
// //                             deleteAuxFile();
// //                             exit(0);
// //                         }
// //                     }
// //                 }

// //                 // CONSIDERAR POSSIBILIDADE DE USAR COMO LEFT UM VALOR QUE SEJA INDICE DE VETOR???
// //                 // PQ TERIA UM LOAD SEGUIDO DE STORE NI ARRAY PREGUIÇA NE

// //                 if (expr->operator== ADD_ASSIGN) {
// //                     result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
// //                     int tReg = printArithmeticsOps(mipsFile, left->registerType, left->registerNumber, right->registerType, right->registerNumber, "add");

// //                     if (left->auxIdNode && ((HashNode *)left->auxIdNode)->isGlobal) {
// //                         // printf("STORING INTO GLOBAL VARIABLE += \n");
// //                         freeRegister(left->registerType, left->registerNumber);
// //                         printStoreIntGlobal(mipsFile, 0, tReg, ((HashNode *)left->auxIdNode)->varId);
// //                         result->registerType = 0;
// //                         result->registerNumber = left->registerNumber;

// //                     } else {
// //                         printAssignmentToReg(mipsFile, 0, tReg, left->registerNumber);
// //                         result->registerNumber = left->registerNumber;
// //                         result->registerType = left->registerType;
// //                     }

// //                 } else if (expr->operator== MINUS_ASSIGN) {
// //                     result = createResultExpression(left->typeVar, left->pointer, auxLeftValor - auxRightValor);
// //                     int tReg = printArithmeticsOps(mipsFile, left->registerType, left->registerNumber, right->registerType, right->registerNumber, "sub");

// //                     if (left->auxIdNode && ((HashNode *)left->auxIdNode)->isGlobal) {
// //                         // printf("STORING INTO GLOBAL VARIABLE -= \n");
// //                         freeRegister(left->registerType, left->registerNumber);
// //                         printStoreIntGlobal(mipsFile, 0, tReg, ((HashNode *)left->auxIdNode)->varId);
// //                         result->registerType = 0;
// //                         result->registerNumber = left->registerNumber;

// //                     } else {
// //                         printAssignmentToReg(mipsFile, 0, tReg, left->registerNumber);
// //                         result->registerNumber = left->registerNumber;
// //                         result->registerType = left->registerType;
// //                     }
// //                 }
// //             }
// //             HashNode *hashNodeTemp = getIdentifierNode(localHash, expr->left->value->valor);
// //             if (!hashNodeTemp) hashNodeTemp = getIdentifierNode(globalHash, expr->left->value->valor);
// //             if (hashNodeTemp) setAssign(hashNodeTemp, result->assign);
// //             hashNodeTemp = NULL;

// //             result->auxLine = expr->value->line;
// //             result->auxColumn = expr->value->column;
// //             return result;
// //             break;

// //         case TERNARY:
// //             ResultExpression *condition = evalExpression(expr->ternary, globalHash, localHash, program);
// //             printTernary(mipsFile, condition->registerType, condition->registerNumber, ((AuxToken *)expr->value)->line);
// //             printLabel(mipsFile, "true_ternary_", ((AuxToken *)expr->value)->line);
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             printJump(mipsFile, "end_ternary_", ((AuxToken *)expr->value)->line);
// //             printLabel(mipsFile, "false_ternary_", ((AuxToken *)expr->value)->line);
// //             right = evalExpression(expr->right, globalHash, localHash, program);
// //             printLabel(mipsFile, "end_ternary_", ((AuxToken *)expr->value)->line);

// //             // printf("teste de ternario true %d false %d\n", left->assign, right->assign);
// //             padronizeTypesAndPointers(expr, left, right, &auxLeftType, &auxLeftPointer, &auxLeftValor, &auxRightType, &auxRightPointer, &auxRightValor);

// //             if (auxLeftType != auxRightType || auxLeftPointer != auxRightPointer) {
// //                 if (textBefore) printf("\n");
// //                 char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                 char *type2 = getExactType(auxRightType, auxRightPointer);
// //                 printf("warning:%d:%d: '%s'/'%s' type mismatch in conditional expression", expr->value->line, expr->value->column, type1, type2);
// //                 free(type1);
// //                 free(type2);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 textBefore = 1;
// //             }

// //             leftType = left->registerType;
// //             leftReg = left->registerNumber;
// //             rightType = right->registerType;
// //             rightReg = right->registerNumber;

// //             if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                 leftReg = printLoadFromArray(mipsFile, left->registerNumber);
// //                 leftType = 0;
// //             }
// //             if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
// //                 rightReg = printLoadFromArray(mipsFile, right->registerNumber);
// //                 rightType = 0;
// //             }
// //             // printf("left reg %d %d right reg %d %d\n", leftType, leftReg, rightType, rightReg);
// //             if (condition->assign) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, left->assign);
// //                 result->registerNumber = left->registerNumber;
// //                 result->registerType = left->registerType;
// //                 if (rightType == 0) freeRegister(rightType, rightReg);

// //             } else {
// //                 result = createResultExpression(auxRightType, auxRightPointer, right->assign);
// //                 result->registerNumber = right->registerNumber;
// //                 result->registerType = right->registerType;
// //                 if (leftType == 0) freeRegister(leftType, leftReg);
// //             }
// //             result->auxLine = expr->value->line;
// //             result->auxColumn = expr->value->column;
// //             return result;

// //         case OR_LOGICO:
// //         case AND_LOGICO:
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             right = evalExpression(expr->right, globalHash, localHash, program);

// //             padronizeTypesAndPointers(expr, left, right, &auxLeftType, &auxLeftPointer, &auxLeftValor, &auxRightType, &auxRightPointer, &auxRightValor);

// //             leftType = left->registerType;
// //             leftReg = left->registerNumber;
// //             rightType = right->registerType;
// //             rightReg = right->registerNumber;

// //             if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                 leftReg = printLoadFromArray(mipsFile, left->registerNumber);
// //                 leftType = 0;
// //             }
// //             if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
// //                 rightReg = printLoadFromArray(mipsFile, right->registerNumber);
// //                 rightType = 0;
// //             }

// //             if (expr->type == OR_LOGICO) {
// //                 result = createResultExpression(INT, 0, auxLeftValor || auxRightValor);
// //                 int tReg = printLogicalOr(mipsFile, leftType, leftReg, rightType, rightReg, ((AuxToken *)expr->value)->line, ((AuxToken *)expr->value)->column);
// //                 result->registerNumber = tReg;

// //             } else if (expr->type == AND_LOGICO) {
// //                 result = createResultExpression(INT, 0, auxLeftValor && auxRightValor);
// //                 int tReg = printLogicalAnd(mipsFile, leftType, leftReg, rightType, rightReg, ((AuxToken *)expr->value)->line, ((AuxToken *)expr->value)->column);
// //                 result->registerNumber = tReg;
// //             }
// //             result->registerType = 0;
// //             result->auxLine = expr->value->line;
// //             result->auxColumn = expr->value->column;
// //             return result;

// //         case RELACIONAL:
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             right = evalExpression(expr->right, globalHash, localHash, program);

// //             padronizeTypesAndPointers(expr, left, right, &auxLeftType, &auxLeftPointer, &auxLeftValor, &auxRightType, &auxRightPointer, &auxRightValor);

// //             // ponteiro com int ou char gera warning
// //             // ponteiro com ponteiro diferente gera erro
// //             if ((auxLeftPointer == 0 && auxRightPointer != 0) || (auxLeftPointer != 0 && auxRightPointer == 0)) {
// //                 if (textBefore) printf("\n");
// //                 char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                 char *type2 = getExactType(auxRightType, auxRightPointer);
// //                 printf("warning:%d:%d: comparison between '%s' and '%s' operator '%s'", expr->value->line, expr->value->column, type1, type2, expr->value->valor);
// //                 free(type1);
// //                 free(type2);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 textBefore = 1;

// //                 // comparacao entre ponteiros de tipos diferentes
// //             } else if (auxLeftType != auxRightType) {
// //                 // printf("\nauxLeftType %d  %d auxRightType %d  %d\n", auxLeftType, auxLeftPointer, auxRightType, auxRightPointer);
// //                 // exit(0);
// //                 if (textBefore) printf("\n");
// //                 char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                 char *type2 = getExactType(auxRightType, auxRightPointer);
// //                 printf("error:semantic:%d:%d: comparison between '%s' and '%s' operator '%s'", expr->value->line, expr->value->column, type1, type2, expr->value->valor);
// //                 free(type1);
// //                 free(type2);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             leftType = left->registerType;
// //             leftReg = left->registerNumber;
// //             rightType = right->registerType;
// //             rightReg = right->registerNumber;

// //             if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                 leftReg = printLoadFromArray(mipsFile, left->registerNumber);
// //                 leftType = 0;
// //             }
// //             if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
// //                 rightReg = printLoadFromArray(mipsFile, right->registerNumber);
// //                 rightType = 0;
// //             }

// //             if (expr->operator== LESS_THAN) {
// //                 result = createResultExpression(INT, 0, left->assign < right->assign);
// //                 int reg = printRelationalOps(mipsFile, leftType, leftReg, rightType, rightReg, "slt");
// //                 result->registerNumber = reg;

// //             } else if (expr->operator== GREATER_THAN) {
// //                 result = createResultExpression(INT, 0, left->assign > right->assign);
// //                 int reg = printRelationalOps(mipsFile, leftType, leftReg, rightType, rightReg, "sgt");
// //                 result->registerNumber = reg;

// //             } else if (expr->operator== LESS_EQUAL) {
// //                 result = createResultExpression(INT, 0, left->assign <= right->assign);
// //                 int reg = printRelationalOps(mipsFile, leftType, leftReg, rightType, rightReg, "sle");
// //                 result->registerNumber = reg;

// //             } else if (expr->operator== GREATER_EQUAL) {
// //                 result = createResultExpression(INT, 0, left->assign >= right->assign);
// //                 int reg = printRelationalOps(mipsFile, leftType, leftReg, rightType, rightReg, "sge");
// //                 result->registerNumber = reg;

// //             } else if (expr->operator== EQUAL) {
// //                 result = createResultExpression(INT, 0, left->assign == right->assign);
// //                 int reg = printRelationalOps(mipsFile, leftType, leftReg, rightType, rightReg, "seq");
// //                 result->registerNumber = reg;

// //             } else if (expr->operator== NOT_EQUAL) {
// //                 result = createResultExpression(INT, 0, left->assign != right->assign);
// //                 int reg = printRelationalOps(mipsFile, leftType, leftReg, rightType, rightReg, "sne");
// //                 result->registerNumber = reg;
// //             }

// //             result->registerType = 0;
// //             result->auxLine = expr->value->line;
// //             result->auxColumn = expr->value->column;
// //             return result;

// //         case SHIFT:
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             right = evalExpression(expr->right, globalHash, localHash, program);

// //             if (left->typeVar == VOID || right->typeVar == VOID) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }
// //             int leftBits = 0;

// //             padronizeTypesAndPointers(expr, left, right, &auxLeftType, &auxLeftPointer, &auxLeftValor, &auxRightType, &auxRightPointer, &auxRightValor);
// //             if (auxLeftType == INT) {
// //                 leftBits = 32;
// //             } else if (auxLeftType == CHAR) {
// //                 leftBits = 8;
// //             }
// //             if (auxLeftPointer > 0) leftBits = 32;

// //             if (auxRightPointer != 0) {
// //                 if (textBefore) printf("\n");
// //                 char t[5];
// //                 if (expr->operator== R_SHIFT)
// //                     strcpy(t, ">>");
// //                 else if (expr->operator== L_SHIFT)
// //                     strcpy(t, "<<");
// //                 char *type2 = getExactType(auxRightType, auxRightPointer);
// //                 printf("error:semantic:%d:%d: cannot convert from '%s' to int", expr->value->line, expr->value->column, type2);
// //                 free(type2);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             if (auxRightValor < 0) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: %s shift count is negative", expr->value->line, expr->value->column, expr->operator== R_SHIFT ? "right" : "left");
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             // verificar se o valor da direita é maior que o tamanho do tipo da esquerda
// //             if (auxRightValor >= leftBits) {
// //                 if (textBefore) printf("\n");
// //                 printf("warning:%d:%d: %s shift count >= width of type", expr->value->line, expr->value->column, expr->operator== R_SHIFT ? "right" : "left");
// //                 printLineError(expr->value->line, expr->value->column);
// //                 textBefore = 1;
// //             }

// //             leftType = left->registerType;
// //             leftReg = left->registerNumber;
// //             rightType = right->registerType;
// //             rightReg = right->registerNumber;

// //             if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                 leftReg = printLoadFromArray(mipsFile, left->registerNumber);
// //                 leftType = 0;
// //             }
// //             if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
// //                 rightReg = printLoadFromArray(mipsFile, right->registerNumber);
// //                 rightType = 0;
// //             }

// //             if (expr->operator== R_SHIFT) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor >> auxRightValor);
// //                 int tReg = printBitwiseOps(mipsFile, leftType, leftReg, rightType, rightReg, "srlv");
// //                 result->registerNumber = tReg;

// //             } else if (expr->operator== L_SHIFT) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor << auxRightValor);
// //                 int tReg = printBitwiseOps(mipsFile, leftType, leftReg, rightType, rightReg, "sllv");
// //                 result->registerNumber = tReg;
// //             }
// //             result->registerType = 0;
// //             result->auxLine = expr->value->line;
// //             result->auxColumn = expr->value->column;
// //             return result;

// //         case ADITIVIVA:
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             right = evalExpression(expr->right, globalHash, localHash, program);

// //             padronizeTypesAndPointers(expr, left, right, &auxLeftType, &auxLeftPointer, &auxLeftValor, &auxRightType, &auxRightPointer, &auxRightValor);

// //             // printf("\naditivia left %d %d \naditiva right %d %d\n", auxLeftType, auxLeftPointer, auxRightType, auxRightPointer);
// //             // se sao dois pointers nao pode
// //             if (auxLeftPointer != 0 && auxRightPointer != 0) {  // ALERTA MUDEI
// //                 char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                 char *type2 = getExactType(auxRightType, auxRightPointer);
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator== PLUS ? "+" : "-", type1, type2);
// //                 free(type1);
// //                 free(type2);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             leftType = left->registerType;
// //             leftReg = left->registerNumber;
// //             rightType = right->registerType;
// //             rightReg = right->registerNumber;

// //             if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                 leftReg = printLoadFromArray(mipsFile, left->registerNumber);
// //                 leftType = 0;
// //             }
// //             if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
// //                 rightReg = printLoadFromArray(mipsFile, right->registerNumber);
// //                 rightType = 0;
// //             }

// //             if (expr->operator== PLUS) {
// //                 // pode somar pointer e char ou int
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor + auxRightValor);
// //                 result->auxLine = expr->value->line;
// //                 result->auxColumn = expr->value->column;
// //                 int tReg = printArithmeticsOps(mipsFile, leftType, leftReg, rightType, rightReg, "add");
// //                 result->registerType = 0;
// //                 result->registerNumber = tReg;
// //                 return result;

// //             } else if (expr->operator== MINUS) {
// //                 if (auxRightPointer != 0) {
// //                     char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                     char *type2 = getExactType(auxRightType, auxRightPointer);
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: invalid operands to binary '%s' (have '%s' and '%s')", expr->value->line, expr->value->column, expr->operator== PLUS ? "+" : "-", type1, type2);
// //                     free(type1);
// //                     free(type2);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor - auxRightValor);
// //                 result->auxLine = expr->value->line;
// //                 result->auxColumn = expr->value->column;
// //                 int tReg = printArithmeticsOps(mipsFile, leftType, leftReg, rightType, rightReg, "sub");
// //                 result->registerType = 0;
// //                 result->registerNumber = tReg;
// //                 return result;
// //             }
// //             break;

// //         case MULTIPLICATIVA:
// //         case OR_BIT:
// //         case XOR_BIT:
// //         case AND_BIT:
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             right = evalExpression(expr->right, globalHash, localHash, program);

// //             padronizeTypesAndPointers(expr, left, right, &auxLeftType, &auxLeftPointer, &auxLeftValor, &auxRightType, &auxRightPointer, &auxRightValor);

// //             if (auxLeftPointer == 0 && auxRightPointer == 0 &&
// //                 (auxLeftType == INT || auxLeftType == CHAR) && (auxRightType == INT || auxRightType == CHAR)) {
// //                 // printf("certo!\n");
// //             } else {
// //                 char c;
// //                 if (expr->operator== MULTIPLY)
// //                     c = '*';
// //                 else if (expr->operator== DIVIDE)
// //                     c = '/';
// //                 else if (expr->operator== REMAINDER)
// //                     c = '%';
// //                 else if (expr->operator== BITWISE_OR)
// //                     c = '|';
// //                 else if (expr->operator== BITWISE_XOR)
// //                     c = '^';
// //                 else if (expr->operator== BITWISE_AND)
// //                     c = '&';
// //                 char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                 char *type2 = getExactType(auxRightType, auxRightPointer);
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: invalid operands to binary '%c' (have '%s' and '%s')", expr->value->line, expr->value->column, c, type1, type2);
// //                 free(type1);
// //                 free(type2);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             leftType = left->registerType;
// //             leftReg = left->registerNumber;
// //             rightType = right->registerType;
// //             rightReg = right->registerNumber;

// //             if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                 leftReg = printLoadFromArray(mipsFile, left->registerNumber);
// //                 leftType = 0;
// //             }
// //             if (right->auxIdNode && ((HashNode *)right->auxIdNode)->kind == VECTOR) {
// //                 rightReg = printLoadFromArray(mipsFile, right->registerNumber);
// //                 rightType = 0;
// //             }

// //             if (expr->operator== MULTIPLY) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor * auxRightValor);
// //                 int tReg = printArithmeticsOps(mipsFile, leftType, leftReg, rightType, rightReg, "mul");
// //                 result->registerType = 0;
// //                 result->registerNumber = tReg;

// //             } else if (expr->operator== DIVIDE) {
// //                 if (right->assign == 0 || auxRightValor == 0) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: division by zero", expr->value->line, expr->value->column);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor / auxRightValor);
// //                 int tReg = printDivisionOps(mipsFile, leftType, leftReg, rightType, rightReg, "mflo");
// //                 result->registerNumber = tReg;

// //             } else if (expr->operator== REMAINDER) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor % auxRightValor);
// //                 int tReg = printDivisionOps(mipsFile, leftType, leftReg, rightType, rightReg, "mfhi");
// //                 result->registerNumber = tReg;

// //             } else if (expr->operator== BITWISE_OR) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor | auxRightValor);
// //                 int tReg = printBitwiseOps(mipsFile, leftType, leftReg, rightType, rightReg, "or");
// //                 result->registerNumber = tReg;

// //             } else if (expr->operator== BITWISE_XOR) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor ^ auxRightValor);
// //                 int tReg = printBitwiseOps(mipsFile, leftType, leftReg, rightType, rightReg, "xor");
// //                 result->registerNumber = tReg;

// //             } else if (expr->operator== BITWISE_AND) {
// //                 result = createResultExpression(auxLeftType, auxLeftPointer, auxLeftValor & auxRightValor);
// //                 int tReg = printBitwiseOps(mipsFile, leftType, leftReg, rightType, rightReg, "and");
// //                 result->registerNumber = tReg;
// //             }
// //             result->registerType = 0;
// //             result->auxLine = expr->value->line;
// //             result->auxColumn = expr->value->column;
// //             return result;
// //             break;

// //         case CASTING:
// //             right = evalExpression(expr->right, globalHash, localHash, program);

// //             if (right->typeVar == STRING) {
// //                 right->typeVar = CHAR;
// //                 right->pointer = 1;
// //             }

// //             if (right->typeVar == VOID && expr->value->type != VOID && right->pointer == 0) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: void value not ignored as it ought to be", expr->value->line, expr->value->column);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }

// //             // para serem de tamanhos diferentes deve:
// //             // a) na direita ter um int e na esquerda um char sem ponteiro (8) 32
// //             // b) na direita ter um char* e na esquerda um char sem ponteiro (8) 32
// //             // c) na direita ter um int* e na esquerda um char sem ponteiro (8) 32

// //             auxLeftPointer = expr->value->pointer;
// //             if (expr->value->type == INT || expr->value->type == NUM_INT)
// //                 auxLeftType = INT;
// //             else if (expr->value->type == CHAR || expr->value->type == CHARACTER)
// //                 auxLeftType = CHAR;
// //             else if (expr->value->type == VOID)
// //                 auxLeftType = VOID;
// //             if (right) {
// //                 auxRightPointer = right->pointer;
// //                 if (right->typeVar == INT || right->typeVar == NUM_INT)
// //                     auxRightType = INT;
// //                 else if (right->typeVar == CHAR || right->typeVar == CHARACTER)
// //                     auxRightType = CHAR;
// //                 else if (right->typeVar == VOID)
// //                     auxRightType = VOID;
// //                 HashNode *temp = right->auxIdNode;
// //                 if (temp) {
// //                     if (temp->kind == VECTOR)
// //                         auxRightPointer = 1;
// //                 }
// //             }

// //             int auxLeftSize = 0;
// //             int auxRightSize = 0;

// //             if (auxLeftType == INT)
// //                 auxLeftSize = 32;
// //             else if (auxLeftType == CHAR)
// //                 auxLeftSize = 8;
// //             else if (auxLeftType == VOID)
// //                 auxLeftSize = 8;

// //             if (auxRightType == INT)
// //                 auxRightSize = 32;
// //             else if (auxRightType == CHAR)
// //                 auxRightSize = 8;
// //             else if (auxRightType == VOID)
// //                 auxRightSize = 8;

// //             if (auxLeftPointer != 0) auxLeftSize = 32;
// //             if (auxRightPointer != 0) auxRightSize = 32;

// //             if (auxLeftSize < auxRightSize) {
// //                 // printf("\ncasting %d %d %d %d %d\n", expr->value->line, auxLeftType, auxLeftPointer, auxRightType, auxRightPointer);
// //                 if (textBefore) printf("\n");
// //                 char *type1 = getExactType(auxRightType, auxRightPointer);
// //                 char *type2 = getExactType(auxLeftType, auxLeftPointer);
// //                 printf("warning:%d:%d: cast from '%s' to '%s' of different size", expr->value->line, expr->value->column, type1, type2);
// //                 free(type1);
// //                 free(type2);
// //                 printLineError(expr->value->line, expr->value->column);
// //                 textBefore = 1;
// //             }
// //             result = createResultExpression(auxLeftType, auxLeftPointer, right->assign);
// //             result->auxLine = expr->value->line;
// //             result->auxColumn = expr->value->column;
// //             return result;

// //         case UNARIA:
// //             left = evalExpression(expr->left, globalHash, localHash, program);

// //             if (expr->operator== PLUS || expr->operator== MINUS || expr->operator== BITWISE_NOT) {
// //                 if ((left->typeVar == NUM_INT || left->typeVar != CHARACTER || left->typeVar != INT || left->typeVar != CHAR)) {
// //                     if (left->pointer != 0 && expr->operator!= BITWISE_NOT) {
// //                         if (textBefore) printf("\n");
// //                         printf("error:semantic:%d:%d: wrong type argument to unary %s", expr->value->line, expr->value->column, expr->operator== PLUS ? "plus" : "minus");
// //                         printLineError(expr->value->line, expr->value->column);
// //                         freeAST(program);
// //                         deleteMipsFileOnError(mipsFile, mipsPath);
// //                         deleteAuxFile();
// //                         exit(0);
// //                     }
// //                 }

// //                 if (left->typeVar != NUM_INT && left->typeVar && CHARACTER && left->typeVar != INT && left->typeVar != CHAR && (left->typeVar != VOID && left->pointer == 0)) {
// //                     char c;
// //                     if (expr->operator== PLUS)
// //                         c = '+';
// //                     else if (expr->operator== MINUS)
// //                         c = '-';
// //                     else if (expr->operator== BITWISE_NOT)
// //                         c = '~';
// //                     char *type1 = getExactType(left->typeVar, left->pointer);

// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: invalid type argument of unary '%c' (have '%s')", expr->value->line, expr->value->column, c, type1);
// //                     free(type1);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }

// //                 leftType = left->registerType;
// //                 leftReg = left->registerNumber;

// //                 if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR) {
// //                     leftReg = printLoadFromArray(mipsFile, left->registerNumber);
// //                     leftType = 0;
// //                 }

// //                 if (expr->operator== PLUS) {
// //                     result = createResultExpression(left->typeVar, left->pointer, +left->assign);
// //                     int reg = printUnaryPlusMinus(mipsFile, leftType, leftReg, "add");
// //                     result->registerNumber = reg;
// //                 } else if (expr->operator== MINUS) {
// //                     result = createResultExpression(left->typeVar, left->pointer, -left->assign);
// //                     int reg = printUnaryPlusMinus(mipsFile, leftType, leftReg, "sub");
// //                     result->registerNumber = reg;
// //                 } else if (expr->operator== BITWISE_NOT) {
// //                     result = createResultExpression(left->typeVar, left->pointer, ~left->assign);
// //                     int reg = printBitwiseNot(mipsFile, leftType, leftReg);
// //                     result->registerNumber = reg;
// //                 }
// //                 result->registerType = 0;
// //                 result->auxLine = expr->value->line;
// //                 result->auxColumn = expr->value->column;
// //                 return result;

// //             } else if (expr->operator== MULTIPLY) {
// //                 if (expr->left->value->type != ID) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: lvalue required as unary '%s' operand", expr->value->line, expr->value->column, expr->value->valor);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }
// //                 auxLeftPointer = left->pointer;
// //                 if (left->auxIdNode && ((HashNode *)left->auxIdNode)->kind == VECTOR)
// //                     auxLeftPointer = 1;
// //                 if ((left->typeVar != NUM_INT || left->typeVar != CHARACTER  // alerta
// //                      || left->typeVar != INT || left->typeVar != CHAR) &&
// //                     auxLeftPointer == 0) {
// //                     if (textBefore) printf("\n");
// //                     char *type1 = getExactType(left->typeVar, left->pointer);
// //                     printf("error:semantic:%d:%d: invalid type argument of unary '%c' (have '%s')", expr->value->line, expr->value->column, '*', type1);
// //                     free(type1);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }
// //                 // printf("unary mult %s %d %d %d %s <> %c\n", ((HashNode*)left->auxIdNode)->varId, left->typeVar, left->pointer, left->assign, ((HashNode*)left->auxIdNode)->string, *(((HashNode*)left->auxIdNode)->string));
// //                 // printf("\nunary * %s %d %d\n", ((HashNode*)left->auxIdNode)->varId, left->registerType, left->registerNumber);
// //                 if (left->typeVar == CHAR && left->pointer == 1) {
// //                     result = createResultExpression(CHAR, 0, *(((HashNode *)left->auxIdNode)->string));
// //                     int t = printLoadByte(mipsFile, left->registerType, left->registerNumber);
// //                     result->registerType = 0;
// //                     result->registerNumber = t;

// //                 } else if (left->typeVar == INT && left->pointer == 1) {
// //                     // fprintf(mipsFile, "\t # aqui %s %d %d\n", ((HashNode *)left->auxIdNode)->varId, left->registerType, left->registerNumber);
// //                     result = createResultExpression(INT, 0, 0);
// //                     int i = printConstant(mipsFile, 0);
// //                     if (left->registerNumber == -1) {
// //                         left->registerNumber = printAssignAddress(mipsFile, left->registerType, left->registerNumber, ((HashNode *)left->auxIdNode)->varId);
// //                         setSRegisterInHash(((HashNode *)left->auxIdNode), left->registerNumber);
// //                     }
// //                     int posic = printAccessIndexArray(mipsFile, left->registerType, left->registerNumber, ((HashNode *)left->auxIdNode)->varId, 0, i, ((HashNode *)left->auxIdNode)->isGlobal);
// //                     result->registerType = 0;
// //                     if (inAtrib) {
// //                         result->registerNumber = posic;
// //                     } else {
// //                         result->registerNumber = printLoadFromArray(mipsFile, posic);
// //                     }

// //                 } else {
// //                     result = createResultExpression(left->typeVar, 0, *(&left->assign));
// //                 }
// //                 result->auxLine = expr->value->line;
// //                 result->auxColumn = expr->value->column;
// //                 result->auxIdNode = left->auxIdNode;
// //                 return result;

// //             } else if (expr->operator== BITWISE_AND || expr->operator== NOT || expr->operator== INC || expr->operator== DEC) {
// //                 // printf("unaria expr->left->value->type %d %p %s\n", expr->left->value->type, expr->left, expr->left->value->valor);
// //                 // printf("%d left %p %d %d\n", expr->operator, left, left->typeVar, left->pointer);
// //                 // printf("auxIdNode %d\n", ((HashNode*) left->auxIdNode)->typeVar);
// //                 if (expr->operator!= NOT && left->typeVar != ID && !left->auxIdNode) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: lvalue required as unary '%s' operand", expr->value->line, expr->value->column, expr->value->valor);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }

// //                 auxLeftType = left->typeVar;
// //                 auxLeftPointer = left->pointer;
// //                 auxLeftValor = left->assign;
// //                 if (left->typeVar == ID) {
// //                     auxLeftType = ((HashNode *)left->auxIdNode)->typeVar;
// //                     auxLeftPointer = ((HashNode *)left->auxIdNode)->pointer;
// //                     auxLeftValor = ((HashNode *)left->auxIdNode)->assign;
// //                 }

// //                 if (auxLeftType != NUM_INT && auxLeftType != CHARACTER && auxLeftType != INT && auxLeftType != CHAR && (auxLeftType != VOID && auxLeftPointer == 0)) {
// //                     char t[3];
// //                     if (expr->operator== BITWISE_AND)
// //                         strcpy(t, "&");
// //                     else if (expr->operator== NOT)
// //                         strcpy(t, "!");
// //                     else if (expr->operator== INC)
// //                         strcpy(t, "++");
// //                     else if (expr->operator== DEC)
// //                         strcpy(t, "--");
// //                     char *type1 = getExactType(auxLeftType, auxLeftPointer);
// //                     printf("error:semantic:%d:%d: invalid type argument of unary '%s' (have '%s')", expr->value->line, expr->value->column, t, type1);
// //                     free(type1);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }

// //                 // CONSIDERAR POSSIBILIDADE DE USAR COMO LEFT UM VALOR QUE SEJA INDICE DE VETOR???
// //                 if (expr->operator== BITWISE_AND) {
// //                     result = createResultExpression(auxLeftType, 1, *(&auxLeftValor));  // acesso do valor em memoria

// //                 } else if (expr->operator== NOT) {
// //                     result = createResultExpression(auxLeftType, auxLeftPointer, !(auxLeftValor));
// //                     int reg = printLogicalNot(mipsFile, left->registerType, left->registerNumber);
// //                     result->registerType = 0;
// //                     result->registerNumber = reg;

// //                 } else if (expr->operator== INC) {  // pre incremento
// //                     result = createResultExpression(auxLeftType, auxLeftPointer, ++(auxLeftValor));
// //                     int r = printPreIncrements(mipsFile, left->registerType, left->registerNumber, "addi");
// //                     result->registerType = left->registerType;
// //                     result->registerNumber = r;

// //                 } else if (expr->operator== DEC) {  // pre decremento
// //                     result = createResultExpression(auxLeftType, auxLeftPointer, --(auxLeftValor));
// //                     int r = printPreIncrements(mipsFile, left->registerType, left->registerNumber, "subi");
// //                     result->registerType = left->registerType;
// //                     result->registerNumber = r;
// //                 }
// //                 result->auxLine = expr->value->line;
// //                 result->auxColumn = expr->value->column;
// //                 return result;
// //             }
// //             break;

// //         case POS_FIXA:
// //             // printf("expr->left->type %d\n", expr->left->type);
// //             left = evalExpression(expr->left, globalHash, localHash, program);
// //             // printf(">left %p %d %d %d\n", left, left->typeVar, left->pointer, left->assign);

// //             if (expr->operator== INC || expr->operator== DEC) {
// //                 if (!left->auxIdNode) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: lvalue required as increment operand", expr->value->line, expr->value->column);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }

// //                 // CONSIDERAR POSSIBILIDADE DE USAR COMO LEFT UM VALOR QUE SEJA INDICE DE VETOR???

// //                 if (expr->operator== INC) {  // pos incremento
// //                     int originalValue = left->assign;
// //                     left->assign++;
// //                     result = createResultExpression(left->typeVar, left->pointer, originalValue);
// //                     int r = printPostIncrements(mipsFile, left->registerType, left->registerNumber, "addi");
// //                     result->registerType = 0;  // como o que deve ser retornado é o valor original, nao tem registrador $s
// //                     result->registerNumber = r;

// //                 } else if (expr->operator== DEC) {  // pos decremento
// //                     int originalValue = left->assign;
// //                     left->assign--;
// //                     result = createResultExpression(left->typeVar, left->pointer, originalValue);
// //                     int r = printPostIncrements(mipsFile, left->registerType, left->registerNumber, "subi");
// //                     result->registerType = 0;  // como o que deve ser retornado é o valor original, nao tem registrador $s
// //                     result->registerNumber = r;
// //                 }
// //                 // set assign do id referente ao left
// //                 result->auxLine = expr->value->line;
// //                 result->auxColumn = expr->value->column;
// //                 // printf("pos fixa result %p %d %d = %d\n", result, result->typeVar, result->pointer, result->assign);

// //                 HashNode *hashNodeTemp = getIdentifierNode(localHash, expr->left->value->valor);
// //                 if (!hashNodeTemp) hashNodeTemp = getIdentifierNode(globalHash, expr->left->value->valor);
// //                 if (hashNodeTemp) setAssign(hashNodeTemp, result->assign);
// //                 hashNodeTemp = NULL;
// //                 return result;

// //             } else if (expr->operator== L_SQUARE_BRACKET) {
// //                 HashNode *auxIdNode = left->auxIdNode;
// //                 // printf("pos fixa l square %p %d %d %d %s\n", left, left->typeVar, left->pointer, auxIdNode->kind, ((HashNode*)left->auxIdNode)->varId);
// //                 // vendo se de fato é um array
// //                 int posic = -1;
// //                 // printf("antes %s %d %d %d\n", auxIdNode->varId, left->typeVar, left->pointer, auxIdNode->kind);
// //                 int temErro;
// //                 if (auxIdNode->kind == VECTOR)
// //                     temErro = 0;
// //                 else
// //                     temErro = 1;
// //                 if (left->pointer == 1) temErro = 0;

// //                 if (temErro) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: subscripted value is neither array nor pointer", expr->value->line, expr->value->column);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);

// //                 } else {
// //                     // printf("qntd dimensoes esperadas %d\n", auxIdNode->qntdDimen);
// //                     int qntdDimenRecebidas = 0;
// //                     Dimension *dimenRecebidas = expr->dimension;
// //                     Dimension *dimenEsperada = auxIdNode->dimensions;
// //                     ResultExpression *dimenResult = NULL;
// //                     // percorrer as dimensoes recebidas e verificar se sao inteiros e se a qntd bate

// //                     // PRECISARIA TERMINAR AQUI PARA PERCORRER VETORES DECLARADOS COMO PONTEIROS
// //                     // if (auxIdNode->pointer > 0) auxIdNode->qntdDimen = auxIdNode->pointer;
// //                     // printf("esperadas %d %p\n", auxIdNode->qntdDimen, dimenEsperada);

// //                     while (dimenRecebidas) {
// //                         qntdDimenRecebidas++;
// //                         // printf("\n\nline column dimen %d %d\n\n", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
// //                         // printf("qntd dimensoes recebidas %d\n", qntdDimenRecebidas);
// //                         if (qntdDimenRecebidas != auxIdNode->qntdDimen) {
// //                             if (textBefore) printf("\n");
// //                             printf("error:semantic:%d:%d: subscripted value is neither array nor pointer", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
// //                             printLineError(dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
// //                             freeAST(program);
// //                             deleteMipsFileOnError(mipsFile, mipsPath);
// //                             deleteAuxFile();
// //                             exit(0);
// //                         }

// //                         dimenResult = evalExpression(dimenRecebidas->exp, globalHash, localHash, program);
// //                         if ((dimenResult->typeVar != NUM_INT && dimenResult->typeVar != INT) || dimenResult->pointer != 0) {
// //                             if (textBefore) printf("\n");
// //                             printf("error:semantic:%d:%d: array subscript is not an integer", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
// //                             printLineError(dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
// //                             freeAST(program);
// //                             deleteMipsFileOnError(mipsFile, mipsPath);
// //                             deleteAuxFile();
// //                             exit(0);
// //                         } else {
// //                             // printf("\ndimensao atrib = %d dimensao maxima = %d\n", dimenResult->assign, dimenEsperada->size);
// //                             if (dimenResult->assign >= dimenEsperada->size || dimenResult->assign < 0) {
// //                                 if (textBefore) printf("\n");
// //                                 printf("warning:%d:%d: array index out of bounds", dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
// //                                 printLineError(dimenRecebidas->dimenAuxToken->line, dimenRecebidas->dimenAuxToken->column);
// //                                 textBefore = 1;
// //                             }
// //                         }

// //                         dimenEsperada = dimenEsperada->next;
// //                         dimenRecebidas = dimenRecebidas->next;
// //                         // printf("Array no reg $ s %d\n", ((HashNode*)left->auxIdNode)->sRegister);
// //                         // printf("Indice do vetor %s [%d] || reg $ %c %d\n", ((HashNode*)left->auxIdNode)->varId, dimenResult->assign, dimenResult->registerType == 0 ? 't' : 's', dimenResult->registerNumber);
// //                     }
// //                     HashNode *vec = (HashNode *)left->auxIdNode;
// //                     // printf("posiccc %s %d %d (%d %d)\n", vec->varId, vec->sRegister, vec->isGlobal, dimenResult->registerType, dimenResult->registerNumber);
// //                     posic = printAccessIndexArray(mipsFile, 1, vec->sRegister, vec->varId, dimenResult->registerType, dimenResult->registerNumber, vec->isGlobal);
// //                 }

// //                 result = createResultExpression(auxIdNode->typeVar, 0, 0);
// //                 result->registerType = 0;
// //                 result->registerNumber = posic;
// //                 result->auxIdNode = auxIdNode;
// //                 // printf("pos fixa result ($ t %d) %p %d (%d %d)\n", result->registerNumber, result, result->typeVar, result->pointer, result->assign);
// //                 return result;

// //             } else if (expr->operator== L_PAREN) {
// //                 HashNode *auxIdNode = left->auxIdNode;
// //                 // printf("%p pos fixa func %p %d\n", left, auxIdNode, expr->operator);
// //                 if (auxIdNode->kind != FUNCTION) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: called object '%s' is not a function or function pointer", expr->value->line, expr->value->column, auxIdNode->varId);
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }

// //                 // verificar se a quantidade de parametros bate
// //                 ExpParam *auxParamRecebido = expr->param;
// //                 int qntdParamRecebido = 0;
// //                 while (auxParamRecebido) {
// //                     qntdParamRecebido++;
// //                     auxParamRecebido = auxParamRecebido->next;
// //                 }

// //                 // printf(">>>>>>> qntd esperada (%s) %d\n", auxIdNode->varId, auxIdNode->qntdParams);
// //                 if (qntdParamRecebido != auxIdNode->qntdParams) {
// //                     if (textBefore) printf("\n");
// //                     if (qntdParamRecebido > auxIdNode->qntdParams) {
// //                         printf("error:semantic:%d:%d: too many arguments to function '%s'", expr->value->line, expr->value->column, auxIdNode->varId);
// //                     } else {
// //                         printf("error:semantic:%d:%d: too few arguments to function '%s'", expr->value->line, expr->value->column, auxIdNode->varId);
// //                     }
// //                     printLineError(expr->value->line, expr->value->column);
// //                     freeAST(program);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }
// //                 Param *auxParam = auxIdNode->param;
// //                 auxParamRecebido = expr->param;
// //                 ResultExpression *resultParam = NULL;

// //                 int i = 1;
// //                 int j = qntdParamRecebido - 1;
// //                 while (auxParamRecebido && auxParam) {
// //                     resultParam = evalExpression(auxParamRecebido->exp, globalHash, localHash, program);
// //                     if (resultParam->auxIdNode && ((HashNode *)resultParam->auxIdNode)->kind == VECTOR) {
// //                         // printf("result do param %p %d %d\n", resultParam->auxIdNode, ((HashNode*)resultParam->auxIdNode)->kind, ((HashNode*)resultParam->auxIdNode)->typeVar);
// //                         resultParam->registerNumber = printLoadFromArray(mipsFile, resultParam->registerNumber);
// //                     }
// //                     printSetParamInRegister(mipsFile, j, resultParam->registerType, resultParam->registerNumber, auxParam->identifier);
// //                     // printf("%s param %d %d %d %s ($ %d %d)\n",auxIdNode->varId, j, resultParam->typeVar, resultParam->assign, auxParam->identifier, resultParam->registerType, resultParam->registerNumber);
// //                     j = j - 1;
// //                     auxLeftPointer = auxParam->pointer;
// //                     if (auxParam->type == INT || auxParam->type == NUM_INT)
// //                         auxLeftType = NUM_INT;
// //                     else if (auxParam->type == CHAR || auxParam->type == CHARACTER)
// //                         auxLeftType = CHARACTER;
// //                     else if (auxParam->type == VOID)
// //                         auxLeftType = VOID;

// //                     auxRightPointer = resultParam->pointer;
// //                     if (resultParam->typeVar == VOID)
// //                         auxRightType = VOID;
// //                     else if (resultParam->typeVar == INT || resultParam->typeVar == NUM_INT)
// //                         auxRightType = NUM_INT;
// //                     else if (resultParam->typeVar == CHAR || resultParam->typeVar == CHARACTER)
// //                         auxRightType = CHARACTER;
// //                     else if (resultParam->typeVar == STRING) {
// //                         auxRightType = CHARACTER;
// //                         auxRightPointer = 1;
// //                     }

// //                     // printf("argumentos esperados %s %d %d %d x %d %d = %d\n", auxParam->identifier, auxLeftType, auxLeftPointer, auxParam->kindParam, auxRightType, auxRightPointer, resultParam->assign);
// //                     if (auxParam->kindParam == VECTOR && auxRightType == auxLeftType) {
// //                         // printf("ok\n");
// //                     } else if (auxRightType != auxLeftType) {
// //                         if (textBefore) printf("\n");
// //                         char *type1 = getExactType(auxRightType, auxRightPointer);
// //                         char *type2 = getExactType(auxLeftType, auxLeftPointer);
// //                         printf("error:semantic:%d:%d: incompatible type for argument '%d' of 'foo' expected '%s' but argument is of type '%s'", expr->value->line, expr->value->column, i, type2, type1);
// //                         free(type1);
// //                         free(type2);
// //                         printLineError(expr->value->line, expr->value->column);
// //                         freeAST(program);
// //                         deleteMipsFileOnError(mipsFile, mipsPath);
// //                         deleteAuxFile();
// //                         exit(0);
// //                     }

// //                     auxParam = auxParam->next;
// //                     auxParamRecebido = auxParamRecebido->next;
// //                     i++;
// //                 }
// //                 result = createResultExpression(auxIdNode->typeVar, auxIdNode->pointer, 0);
// //                 result->auxLine = expr->value->line;
// //                 result->auxColumn = expr->value->column;
// //                 // printf("result function call %s %p %d %d = %d\n", auxIdNode->varId, result, result->typeVar, result->pointer, 0);

// //                 printCallFunction(mipsFile, auxIdNode->varId);
// //                 int r = printLoadReturnFromV0(mipsFile);
// //                 result->registerType = 0;
// //                 result->registerNumber = r;
// //                 return result;
// //             }
// //             break;

// //         default:
// //             printf("Tipo de expressão não suportado %p\n", expr);
// //             deleteMipsFileOnError(mipsFile, mipsPath);
// //             deleteAuxFile();
// //             exit(0);
// //     }
// //     return 0;
// // }

// // void traverseASTCommand(Command *command, void **globalHash, void **localHash, Program *program, Function *currentFunction) {
// //     // printf(">> AST Comando %d %p %d\n", command ? command->type : -1, command, command->visited);
// //     if (!command || command->visited) return;
// //     command->visited = 1;

// //     // printf("traverseASTCommand %d %p %p\n",command->type, command, command->next);
// //     // Para cada comando percorrer seus blocos de comandos e expressoes relacionadas recursivamente
// //     // Atencao as expressoes condicionais das estruturas, qua NAO PODEM ter expressoes de retorno tipo void
// //     if (command->type == LISTA_EXP_COMANDO) {
// //         evalExpression(command->condition, globalHash, localHash, program);
// //         traverseASTCommand(command->next, globalHash, localHash, program, currentFunction);
// //     }

// //     if (command->type == IF || command->type == ELSE) {
// //         ResultExpression *ifResult = NULL;
// //         ifResult = evalExpression(command->condition, globalHash, localHash, program);
// //         // printf("ifs %p\n", command);

// //         if (ifResult->typeVar == VOID && ifResult->pointer == 0) {
// //             if (textBefore) printf("\n");
// //             printf("error:semantic:%d:%d: void value not ignored as it ought to be", ifResult->auxLine, ifResult->auxColumn);
// //             printLineError(ifResult->auxLine, ifResult->auxColumn);
// //             freeAST(program);
// //             deleteMipsFileOnError(mipsFile, mipsPath);
// //             deleteAuxFile();
// //             exit(0);
// //         }

// //         int ifLine = abs((int)((intptr_t)command->then));
// //         int elseLine = -1;
// //         if (command->elseStatement) {
// //             elseLine = abs((int)((intptr_t)command->elseStatement));
// //         } else {
// //             elseLine = ifLine;
// //         }
// //         printIf(mipsFile, ifResult->registerType, ifResult->registerNumber, elseLine);
// //         Command *t = command->then;
// //         while (t) {
// //             traverseASTCommand(t, globalHash, localHash, program, currentFunction);
// //             t = t->next;
// //         }
// //         printJump(mipsFile, "exit_if_", ifLine);
// //         printLabel(mipsFile, "else_", elseLine);
// //         Command *t2 = command->elseStatement;
// //         while (t2) {
// //             traverseASTCommand(t2, globalHash, localHash, program, currentFunction);
// //             t2 = t2->next;
// //         }
// //         printLabel(mipsFile, "exit_if_", ifLine);
// //     }

// //     if (command->type == WHILE || command->type == DO) {
// //         int whileLine = command->auxToken->line;
// //         if (command->type == WHILE)
// //             printJump(mipsFile, "while_teste_", whileLine);
// //         printLabel(mipsFile, "while_corpo_", whileLine);
// //         Command *t = command->then;
// //         while (t) {
// //             traverseASTCommand(t, globalHash, localHash, program, currentFunction);
// //             t = t->next;
// //         }
// //         printLabel(mipsFile, "while_teste_", whileLine);
// //         ResultExpression *whileResult = NULL;
// //         whileResult = evalExpression(command->condition, globalHash, localHash, program);
// //         if (whileResult->typeVar == VOID && whileResult->pointer == 0) {
// //             if (textBefore) printf("\n");
// //             printf("error:semantic:%d:%d: void value not ignored as it ought to be", whileResult->auxLine, whileResult->auxColumn);
// //             printLineError(whileResult->auxLine, whileResult->auxColumn);
// //             freeAST(program);
// //             deleteMipsFileOnError(mipsFile, mipsPath);
// //             deleteAuxFile();
// //             exit(0);
// //         }
// //         printWhile(mipsFile, whileResult->registerType, whileResult->registerNumber, whileLine);
// //     }

// //     if (command->type == FOR) {
// //         evalExpression(command->init, globalHash, localHash, program);
// //         printJump(mipsFile, "for_teste_", command->auxToken->line);
// //         printLabel(mipsFile, "for_corpo_", command->auxToken->line);
// //         Command *t = command->then;
// //         while (t) {
// //             traverseASTCommand(t, globalHash, localHash, program, currentFunction);
// //             t = t->next;
// //         }
// //         evalExpression(command->increment, globalHash, localHash, program);
// //         printLabel(mipsFile, "for_teste_", command->auxToken->line);
// //         ResultExpression *forResult = NULL;
// //         forResult = evalExpression(command->condition, globalHash, localHash, program);
// //         if (forResult->typeVar == VOID && forResult->pointer == 0) {
// //             if (textBefore) printf("\n");
// //             printf("error:semantic:%d:%d: void value not ignored as it ought to be", forResult->auxLine, forResult->auxColumn);
// //             printLineError(forResult->auxLine, forResult->auxColumn);
// //             freeAST(program);
// //             deleteMipsFileOnError(mipsFile, mipsPath);
// //             deleteAuxFile();
// //             exit(0);
// //         }
// //         printFor(mipsFile, forResult->registerType, forResult->registerNumber, command->auxToken->line);
// //     }

// //     if (command->type == PRINTF || command->type == SCANF) {
// //         if (command->type == PRINTF) {
// //             if (command->auxPrint) {
// //                 Expression *next = command->auxPrint;
// //                 ResultExpression *toPrint = NULL;

// //                 // printf("1.String original: %s\n", command->string);
// //                 char *restOfString = NULL;

// //                 char *stringWithoutFormat = calloc(strlen(command->string) + 1, sizeof(char));
// //                 strcpy(stringWithoutFormat, command->string + 1);  // copy the 7 string without the "
// //                 // while (next) {
// //                 //     printf("expr inprint %p %d\n", next, next->type);
// //                 //     next = next->nextExpr;
// //                 // }
// //                 // exit(0);
// //                 // If we got to this block there is for sure at least one %d in this print
// //                 while (next) {
// //                     toPrint = evalExpression(next, globalHash, localHash, program);
// //                     // printf("Return aux print: reg %d %d value %d var %s %d \n", toPrint->registerType, toPrint->registerNumber, toPrint->assign, ((HashNode*)toPrint->auxIdNode)->varId, ((HashNode*)toPrint->auxIdNode)->kind);
// //                     next = next->nextExpr;
// //                     if (toPrint) {
// //                         if (toPrint->auxIdNode) {
// //                             if (((HashNode *)toPrint->auxIdNode)->kind == VECTOR) {
// //                                 toPrint->registerNumber = printLoadFromArray(mipsFile, toPrint->registerNumber);
// //                                 toPrint->registerType = 0;
// //                             }
// //                         }
// //                     }

// //                     int printing = 0;
// //                     char *formatSpecifier = strstr(stringWithoutFormat, "%d");  // pointer to the first occurrence of %d
// //                     if (formatSpecifier) {
// //                         printing = INT;
// //                     } else {
// //                         formatSpecifier = strstr(stringWithoutFormat, "%s");
// //                         if (formatSpecifier) {
// //                             printing = STRING;
// //                         } else {
// //                             formatSpecifier = strstr(stringWithoutFormat, "%c");
// //                             if (formatSpecifier) {
// //                                 printing = CHAR;
// //                             }
// //                         }
// //                     }
// //                     // printf("before %s\n", stringWithoutFormat);
// //                     // printf("2.formatSpecifier %s\n", formatSpecifier);
// //                     if (restOfString) free(restOfString);
// //                     restOfString = calloc(strlen(formatSpecifier) + 1, sizeof(char));
// //                     strcpy(restOfString, formatSpecifier + 2);
// //                     restOfString[strlen(restOfString)] = '\0';  // remove the " and null terminate
// //                     // printf("3.rest %s\n", restOfString);
// //                     if (formatSpecifier != NULL) *formatSpecifier = '\0';  // Null-terminate the string at the format specifier
// //                     printString(mipsFile, stringWithoutFormat, abs((int)((intptr_t)toPrint)));
// //                     if (printing == INT)
// //                         printInteger(mipsFile, toPrint->registerType, toPrint->registerNumber);
// //                     else if (printing == CHAR)
// //                         printCharacter(mipsFile, toPrint->registerType, toPrint->registerNumber);
// //                     else if (printing == STRING)
// //                         printStringVar(mipsFile, toPrint->registerType, toPrint->registerNumber);

// //                     free(stringWithoutFormat);
// //                     stringWithoutFormat = calloc(strlen(restOfString) + 1, sizeof(char));
// //                     strcpy(stringWithoutFormat, restOfString);
// //                 }
// //                 if (strlen(restOfString) > 0) {
// //                     restOfString[strlen(restOfString) - 1] = '\0';
// //                     // printf("4.rest %s\n", restOfString);
// //                     printString(mipsFile, restOfString, rand() % 1000);
// //                 }
// //                 if (restOfString) free(restOfString);
// //                 if (stringWithoutFormat) free(stringWithoutFormat);

// //             } else {
// //                 // remove the " " from the string
// //                 // printf("2.String original %s\n", command->string);
// //                 char *fixedString = calloc(strlen(command->string) - 1, sizeof(char));
// //                 strncpy(fixedString, command->string + 1, strlen(command->string) - 2);
// //                 fixedString[strlen(command->string) - 2] = '\0';  // Null-terminate the string
// //                 printString(mipsFile, fixedString, command->auxToken->line);
// //                 free(fixedString);
// //             }

// //         } else {
// //             HashNode *node = getIdentifierNode(localHash, command->identifier);
// //             if (!node) node = getIdentifierNode(globalHash, command->identifier);
// //             if (!node) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: '%s' undeclared", command->idLin, command->idCol, command->identifier);
// //                 printLineError(command->idLin, command->idCol);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }
// //             int sReg = printScanInt(mipsFile, node->sRegister, node->varId, node->isGlobal);
// //             node->sRegister = sReg;
// //         }
// //     }

// //     if (command->type == RETURN) {
// //         // printf("\nreturn %p %d\n", command->condition, command->condition->type);
// //         functionWithNoReturn = 1;
// //         if (currentFunction->returnType == VOID && currentFunction->pointer == 0) {
// //             if (command->condition) {
// //                 HashNode *auxFunc = getIdentifierNode(globalHash, currentFunction->name);
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: return with a value, in function returning void", auxFunc->line, auxFunc->column);
// //                 printLineError(auxFunc->line, auxFunc->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }
// //             if (strcmp(currentFunction->name, "main")) {  // doesnot print jr $ra for main
// //                 loadFromStack(mipsFile);
// //                 loadTRegisters(mipsFile, tRegsAlive);
// //                 // free(tRegsAlive);
// //                 printReturn(mipsFile);
// //             }
// //         } else {
// //             if (!command->condition) {
// //                 if (textBefore) printf("\n");
// //                 printf("error:semantic:%d:%d: return with no value, in function returning non-void", command->auxToken->line, command->auxToken->column);
// //                 printLineError(command->auxToken->line, command->auxToken->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }
// //         }
// //         if (command->condition) {
// //             ResultExpression *returnAux = evalExpression(command->condition, globalHash, localHash, program);
// //             int auxReturnType = returnAux->typeVar;
// //             if (returnAux->typeVar == NUM_INT || returnAux->typeVar == INT)
// //                 auxReturnType = INT;
// //             else if (returnAux->typeVar == CHARACTER || returnAux->typeVar == CHAR)
// //                 auxReturnType = CHAR;
// //             if (auxReturnType != currentFunction->returnType) {
// //                 if (textBefore) printf("\n");
// //                 char *type1 = getExactType(returnAux->typeVar, returnAux->pointer);
// //                 char *type2 = getExactType(currentFunction->returnType, currentFunction->pointer);
// //                 printf("error:semantic:%d:%d: incompatible types when returning type '%s' but '%s' was expected", command->auxToken->line, command->auxToken->column, type1, type2);
// //                 free(type1);
// //                 free(type2);
// //                 printLineError(command->auxToken->line, command->auxToken->column);
// //                 freeAST(program);
// //                 deleteMipsFileOnError(mipsFile, mipsPath);
// //                 deleteAuxFile();
// //                 exit(0);
// //             }
// //             // printf("#returning of %s value %d %d %d ($ %d %d)\n", currentFunction->name, returnAux->typeVar, returnAux->pointer, returnAux->assign, returnAux->registerType, returnAux->registerNumber);
// //             if (returnAux->auxIdNode) {
// //                 // printf("\n>>>>> varId %s %d\n", ((HashNode*)returnAux->auxIdNode)->varId, ((HashNode*)returnAux->auxIdNode)->sRegister);
// //                 if (((HashNode *)returnAux->auxIdNode)->sRegister == -1) {
// //                     int null = printConstant(mipsFile, 0);
// //                     int s = printAssignment(mipsFile, 0, null);
// //                     setSRegisterInHash((HashNode *)returnAux->auxIdNode, s);
// //                     returnAux->registerType = 1;
// //                     returnAux->registerNumber = s;
// //                 }
// //             }
// //             printReturnToV0(mipsFile, returnAux->registerType, returnAux->registerNumber);
// //             if (strcmp(currentFunction->name, "main")) {
// //                 loadFromStack(mipsFile);
// //                 loadTRegisters(mipsFile, tRegsAlive);
// //                 // free(tRegsAlive);
// //                 printReturn(mipsFile);
// //             }  // doesnot print jr $ra for main
// //         }
// //     }

// //     if (command->type == EXIT) {
// //         if (command->condition) {
// //             ResultExpression *status = evalExpression(command->condition, globalHash, localHash, program);
// //             fprintf(mipsFile, "\t# exit with status %d", status->assign);
// //             printExit(mipsFile);
// //         }
// //     }
// // }

// // void lookForNodeInHashWithExpr(void **globalHash, void **localHash, Program *program) {
// //     if (!localHash) return;
// //     for (int i = 0; i < HASH_SIZE; i++) {
// //         HashNode *node = (HashNode *)localHash[i];
// //         ResultExpression *atrib = NULL;
// //         while (node) {
// //             // printf("evaluanting hash %s %d %d \n", node->varId, node->kind, node->isGlobal);
// //             if (node->kind == FUNCTION || node->isConstant) {
// //                 node = node->next;
// //                 continue;
// //             }
// //             if (localHash == globalHash) {  // save globals to memory
// //                 node->isGlobal = 1;
// //                 int size = 0;
// //                 if (node->kind == VAR) {
// //                     if (node->typeVar == NUM_INT || node->typeVar == INT || node->typeVar == VOID || node->pointer > 0)
// //                         size = 32;
// //                     else
// //                         size = 8;
// //                     printGlobalVariableInMemory(mipsFile, size, node->varId);
// //                 }
// //             }

// //             if (node->kind == VECTOR) {
// //                 Dimension *d = node->dimensions;
// //                 int size = 0;
// //                 while (d) {
// //                     size = size + d->size;
// //                     d = d->next;
// //                 }
// //                 // printf(">>>| size of %s = %d\n", node->varId, size);
// //                 int s = printDeclareArray(mipsFile, node->varId, size, node->isGlobal);
// //                 setSRegisterInHash(node, s);
// //             }

// //             if (node->hashExpr) {
// //                 // printf(">>>>>>>>>>>>>> this noda has atrib expr %p %s = %p %d\n", node, node->varId, node->hashExpr, ((Expression*)node->hashExpr)->type);
// //                 atrib = evalExpression(node->hashExpr, globalHash, localHash, program);
// //                 // printf("<<<<<<<<<<<<<< retornou %d %d %d %s\n\n", atrib->typeVar, atrib->pointer, atrib->assign, atrib->str);

// //                 int assignType, assignPointer = atrib->pointer;
// //                 // printf("\nassignType %d %d\n", atrib->typeVar, atrib->assign);
// //                 if (atrib->typeVar == CHAR || atrib->typeVar == CHARACTER) {
// //                     assignType = CHAR;
// //                 } else if (atrib->typeVar == INT || atrib->typeVar == NUM_INT) {
// //                     assignType = INT;
// //                 } else if (atrib->typeVar == STRING) {
// //                     assignType = CHAR;
// //                     assignPointer = 1;
// //                 } else {
// //                     assignType = VOID;
// //                 }
// //                 if (atrib->typeVar == VOID && atrib->pointer == 0) {
// //                     if (textBefore) printf("\n");
// //                     printf("error:semantic:%d:%d: void value not ignored as it ought to be", node->lineAssign, node->columnAssign);
// //                     printLineError(node->lineAssign, node->columnAssign);
// //                     if (localHash) freeHash(localHash);
// //                     // if (globalHash) freeHash(globalHash);
// //                     deleteMipsFileOnError(mipsFile, mipsPath);
// //                     deleteAuxFile();
// //                     exit(0);
// //                 }

// //                 if (((node->typeVar == CHAR || node->typeVar == CHARACTER) && assignType == CHAR) || ((node->typeVar == INT || node->typeVar == NUM_INT) && assignType == INT)) {  // tipos iguais mas ponteiros diferentes
// //                     if (node->pointer != assignPointer) {
// //                         if (textBefore) printf("\n");
// //                         char *type1 = getExactType(node->typeVar, node->pointer);
// //                         char *type2 = getExactType(assignType, assignPointer);
// //                         printf("error:semantic:%d:%d: incompatible types in initialization when assigning to type '%s' from type '%s'", node->lineAssign, node->columnAssign, type1, type2);
// //                         printLineError(node->lineAssign, node->columnAssign);
// //                         if (localHash) freeHash(localHash);
// //                         // if (globalHash) freeHash(globalHash);
// //                         deleteMipsFileOnError(mipsFile, mipsPath);
// //                         deleteAuxFile();
// //                         exit(1);
// //                     }
// //                 }

// //                 if (globalHash == localHash) {  // globals must be stored and loaded in and not to $s register
// //                     // printf("nao to sabendo carregar variaveis globais ja inicializas :D %s = %d\n", node->varId, atrib->assign);
// //                     setGlobalVarAssign(node->varId, atrib->assign);

// //                 } else {
// //                     if (assignType == CHAR && assignPointer == 1) {  // string
// //                         atrib->str[strlen(atrib->str) - 1] = '\0';
// //                         strcpy(atrib->str, atrib->str + 1);
// //                         int regS = printDeclareString(mipsFile, node->varId, atrib->str);
// //                         setSRegisterInHash(node, regS);
// //                         strcpy(node->string, atrib->str);

// //                     } else {
// //                         int regS = printAssignment(mipsFile, atrib->registerType, atrib->registerNumber);
// //                         setSRegisterInHash(node, regS);
// //                         setAssign(node, atrib->assign);
// //                     }
// //                 }
// //             }
// //             node = node->next;
// //         }
// //     }
// // }

// // int traverseAST(Program *program) {
// //     if (!program) return -1;

// //     // Percorra as funções na lista de funções
// //     fprintf(mipsFile, "\n.data\n");
// //     printDefines(mipsFile);
// //     lookForNodeInHashWithExpr(program->hashTable, program->hashTable, program);  // loading global variables (defines not include)
// //     fprintf(mipsFile, ".text\n");

// //     Function *currentFunction = program->functionsList;
// //     while (currentFunction != NULL) {
// //         for (int i = 0; i < 10; i++) freeRegister(0, i);
// //         for (int i = 0; i < 8; i++) freeRegister(1, i);
// //         HashNode *funcNode = getIdentifierNode(program->hashTable, currentFunction->name);
// //         printFunctions(mipsFile, currentFunction->name);
// //         if (strcmp(currentFunction->name, "main")) {  // if not in main save context
// //             tRegsAlive = calloc(10, sizeof(int));
// //             storeTRegisters(mipsFile, tRegsAlive);
// //             storeInStack(mipsFile);
// //         } else {
// //             printGlobalVarAssign(mipsFile);
// //         }
// //         // printf("Function: %s (%d) %p has hash %p\n", currentFunction->name, funcNode->qntdParams, currentFunction, currentFunction->hashTable);
// //         printFunctionParams(mipsFile, currentFunction->name, funcNode->qntdParams);
// //         lookForNodeInHashWithExpr(program->hashTable, currentFunction->hashTable, program);
// //         // Percorra os comandos na função
// //         Command *command = currentFunction->commandList;
// //         while (command != NULL) {
// //             traverseASTCommand(command, program->hashTable, currentFunction->hashTable, program, currentFunction);
// //             command = command->next;
// //         }
// //         if (functionWithNoReturn == 0 && currentFunction->returnType != VOID) {
// //             HashNode *funcNode = getIdentifierNode(program->hashTable, currentFunction->name);
// //             if (textBefore) printf("\n");
// //             printf("error:semantic:%d:%d: no return statement in function returning non-void", funcNode->line, funcNode->column);
// //             printLineError(funcNode->line, funcNode->column);
// //             freeAST(program);
// //             exit(0);
// //         }
// //         if (strcmp(currentFunction->name, "main")) {  // does not print jr $ra return for main
// //             loadFromStack(mipsFile);
// //             loadTRegisters(mipsFile, tRegsAlive);
// //             free(tRegsAlive);
// //             printReturn(mipsFile);
// //         }
// //         functionWithNoReturn = 0;
// //         currentFunction = currentFunction->next;
// //     }
// //     return 0;
// // }

// // void freeAST(Program *program) {
// //     if (!program) return;
// //     freeHash(program->hashTable);

// //     Function *functions = program->functionsList;
// //     while (functions) {
// //         Function *functions2 = functions->next;
// //         Command *cmd = functions->commandList;
// //         while (cmd) {
// //             Command *cmd2 = cmd->next;
// //             if (cmd->condition) {
// //                 if (cmd->condition->value) free(cmd->condition->value);
// //                 free(cmd->condition);
// //             }
// //             if (cmd->init) {
// //                 if (cmd->init->value) free(cmd->init->value);
// //                 free(cmd->init);
// //             }
// //             if (cmd->increment) {
// //                 if (cmd->increment->value) free(cmd->increment->value);
// //                 free(cmd->increment);
// //             }
// //             if (cmd->auxPrint) {
// //                 if (cmd->auxPrint->value) free(cmd->auxPrint->value);
// //                 free(cmd->auxPrint);
// //             }
// //             if (cmd->auxToken) free(cmd->auxToken);
// //             free(cmd);
// //             cmd = cmd2;
// //         }
// //         freeHash(functions->hashTable);
// //         if (functions->name) free(functions->name);
// //         free(functions);
// //         functions = functions2;
// //     }
// //     free(program);
// // }