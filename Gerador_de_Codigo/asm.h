#ifndef _ASH_H
#define _ASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *createAsmFile(char *fileName);

// Arithmetic operations
int printConstant(FILE *mips, int value);
int printArithmeticsOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op);
int printDivisionOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op);
int printAutoIncrements(FILE *mips, int leftType, int leftReg, char *op);

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

// Labels and jumps
void printJump(FILE *mips, char *label, int labelID);
void printLabel(FILE *mips, char *label, int labelID);

// Global variables
void printGlobalVariable(FILE *mips, char *name, int value);

// Output print
void printInteger(FILE *mips, int regType, int RegNumber);
void printString(FILE *mips, char *value, int stringID);

// Input scan
int printScanInt(FILE *mips, int sReg);

// Function call
void printCallFunction(FILE *mips, char *name);
void printReturn(FILE *mips);

// Stack
void printStart(FILE *mips);
void printEnd(FILE *mips);

void failedToGenerateMips(FILE *mips, char *path);

#endif