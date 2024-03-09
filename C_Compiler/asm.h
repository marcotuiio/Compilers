#ifndef _ASM_H
#define _ASM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *createAsmFile(char *fileName);
void deleteMipsFileOnError(FILE *mipsFile, char *mipsPath);

// Arithmetic operations
int printConstant(FILE *mips, int value);
int printArithmeticsOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op);
int printDivisionOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op);
int printPreIncrements(FILE *mips, int leftType, int leftReg, char *op);
int printPostIncrements(FILE *mips, int leftType, int leftReg, char *op);

// Assigns
int printAssignment(FILE *mips, int rightType, int rightReg);
void printAssignmentToReg(FILE *mips, int rightType, int rightReg, int leftReg);
int printDeclareString(FILE *mips, char *name, char *value);
int printAssignAddress(FILE *mips, int leftType, int leftReg, char *name);
void printStoreInAddress(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);

// Unary operations (+, -, ~) + logical not (!) + bitwise ops (&, |, ^) + shifts (<<, >>)
int printUnaryPlusMinus(FILE *mips, int leftType, int leftReg, char *op);
int printBitwiseNot(FILE *mips, int leftType, int leftReg);
int printBitwiseOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op);
int printLogicalNot(FILE *mips, int leftType, int leftReg);

// Relational expressions
int printRelationalOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op);

// Control structures
int printLogicalAnd(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID);
int printLogicalOr(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID);
void printIf(FILE *mips, int conditionType, int conditionReg, int labelID);
void printWhile(FILE *mips, int conditionType, int conditionReg, int labelID);
void printFor(FILE *mips, int conditionType, int conditionReg, int labelID);
void printTernary(FILE *mips, int conditionType, int conditionReg, int labelID);

// Labels and jumps
void printJump(FILE *mips, char *label, int labelID);
void printLabel(FILE *mips, char *label, int labelID);
void printFunctions(FILE *mips, char *name);

// Global variables and declarations
void printGlobalVariableInMemory(FILE *mipsFile, int size, char *name);
void setDefineIntVariable(char *name, int value, int type, int regToFree);
void printDefines(FILE *mips);
// void printGlobalCharVariable(FILE *mips, char *name, char value);
void setGlobalVarAssign(char *name, int value);
void printGlobalVarAssign(FILE *mips);
int printLoadIntGlobal(FILE *mips, char *name);
void printStoreIntGlobal(FILE *mips, int type, int reg, char *name);

// Arrays
int printDeclareArray(FILE *mips, char *name, int size, int isGlobal);
int printAccessIndexArray(FILE *mips, int arrayType, int arrayReg, char *name, int indexType, int indexReg, int isGlobal);
void printStoreIntoArray(FILE *mips, int posic, int rightType, int rightReg);
int printLoadFromArray(FILE *mips, int posic);
int printLoadByte(FILE *mips, int type, int reg);

// Output print
void printInteger(FILE *mips, int regType, int RegNumber);
void printCharacter(FILE *mips, int regType, int RegNumber);
void printStringVar(FILE *mips, int type, int value);
void printString(FILE *mips, char *value, int stringID1);

// Input scan
int printScanInt(FILE *mips, int sReg, char *name, int isGlobal);

// Function call
void printCallFunction(FILE *mips, char *name);
void printSetParamInRegister(FILE *mips, int aReg, int rightType, int rightReg, char *var);
void printFunctionParams(FILE *mips, char *name, int params);
void printReturn(FILE *mips);
void printReturnToV0(FILE *mips, int type, int reg);
int printLoadReturnFromV0(FILE *mips);

// Stack
void storeGlobalsInStack(FILE *mips, int *globals);
// void loadGlobalsFromStack(FILE *mips, int *globals);
void storeInStack(FILE *mips);
void loadFromStack(FILE *mips);
void storeTRegisters(FILE *mips, int *regs);
void loadTRegisters(FILE *mips, int *regs);
void freeRegister(int type, int number);
void printStart(FILE *mips);
void printExit(FILE *mips);
void printEnd(FILE *mips);

#endif