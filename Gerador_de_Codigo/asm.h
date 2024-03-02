#ifndef _ASH_H
#define _ASH_H

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
void setGlobalIntVariable(char *name, int value, int type, int regToFree);
void printGlobals(FILE *mips);
// void printGlobalCharVariable(FILE *mips, char *name, char value);
int printLoadIntGlobal(FILE *mips, char *name);

// Arrays
int printDeclareArray(FILE *mips, char *name, int size);
int printAccessIndexArray(FILE *mips, int arrayType, int arrayReg, int indexType, int indexReg);
void printStoreIntoArray(FILE *mips, int posic, int rightType, int rightReg);
int printLoadFromArray(FILE *mips, int posic);

// Output print
void printInteger(FILE *mips, int regType, int RegNumber);
void printString(FILE *mips, char *value, int stringID1);

// Input scan
int printScanInt(FILE *mips, int sReg);

// Function call
void printCallFunction(FILE *mips, char *name);
void printSetParamInRegister(FILE *mips, int aReg, int rightType, int rightReg, char *var);
void printFunctionParams(FILE *mips, char *name, int params);
void printReturn(FILE *mips);
void printReturnToV0(FILE *mips, int type, int reg);
int printLoadReturnFromV0(FILE *mips);

// Stack
void storeInStack(FILE *mips);
void loadFromStack(FILE *mips);
void storeTRegisters(FILE *mips, int *regs);
void loadTRegisters(FILE *mips, int *regs);
void freeRegister(int type, int number);
void printStart(FILE *mips);
void printEnd(FILE *mips);

#endif