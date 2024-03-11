#ifndef _ASM_H
#define _ASM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStart();

// Arithmetic operations
int printConstant(int value);
int printArithmeticsOps(int leftType, int leftReg, int rightType, int rightReg, char *op);
int printDivisionOps(int leftType, int leftReg, int rightType, int rightReg, char *op);
int printPreIncrements(int leftType, int leftReg, char *op);
int printPostIncrements(int leftType, int leftReg, char *op);

// Assigns
int printAssignment(int rightType, int rightReg);
void printAssignmentToReg(int rightType, int rightReg, int leftReg);
int printDeclareString(char *name, char *value);
int printAssignAddress(int leftType, int leftReg, char *name);
void printStoreInAddress(int leftType, int leftReg, int rightType, int rightReg);

// Unary operations (+, -, ~) + logical not (!) + bitwise ops (&, |, ^) + shifts (<<, >>)
int printUnaryPlusMinus(int leftType, int leftReg, char *op);
int printBitwiseNot(int leftType, int leftReg);
int printBitwiseOps(int leftType, int leftReg, int rightType, int rightReg, char *op);
int printLogicalNot(int leftType, int leftReg);

// Relational expressions
int printRelationalOps(int leftType, int leftReg, int rightType, int rightReg, char *op);

// Control structures
int printLogicalAnd(int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID);
int printLogicalOr(int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID);
void printIf(int conditionType, int conditionReg, int labelID);
void printWhile(int conditionType, int conditionReg, int labelID);
void printFor(int conditionType, int conditionReg, int labelID);
void printTernary(int conditionType, int conditionReg, int labelID);

// Labels and jumps
void printJump(char *label, int labelID);
void printLabel(char *label, int labelID);
void printFunctions(char *name);

// Global variables and declarations
void printGlobalVariableInMemory(int size, char *name);
void setDefineIntVariable(char *name, int value, int type, int regToFree);
void printDefines();
// void printGlobalCharVariable(char *name, char value);
void setGlobalVarAssign(char *name, int value);
void printGlobalVarAssign();
int printLoadIntGlobal(char *name);
void printStoreIntGlobal(int type, int reg, char *name);

// Arrays
int printDeclareArray(char *name, int size, int isGlobal);
int printAccessIndexArray(int arrayType, int arrayReg, char *name, int indexType, int indexReg, int isGlobal);
void printStoreIntoArray(int posic, int rightType, int rightReg);
int printLoadFromArray(int posic);
int printLoadByte(int type, int reg);

// Output print
void printInteger(int regType, int RegNumber);
void printCharacter(int regType, int RegNumber);
void printStringVar(int type, int value);
void printString(char *value, int stringID1);

// Input scan
int printScanInt(int sReg, char *name, int isGlobal);

// Function call
void printCallFunction(char *name);
void printSetParamInRegister(int aReg, int rightType, int rightReg, char *var);
void printFunctionParams(char *name, int params);
void printReturn();
void printReturnToV0(int type, int reg);
int printLoadReturnFromV0();

// Stack
void storeGlobalsInStack(int *globals);
// void loadGlobalsFromStack(int *globals);
void storeInStack();
void loadFromStack();
void storeTRegisters(int *regs);
void loadTRegisters(int *regs);
void freeRegister(int type, int number);
void printStart();
void printExit();
void printEnd();

#endif