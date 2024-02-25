#ifndef _ASH_H
#define _ASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *createAsmFile(char *fileName);

// Arithmetic operations
int printConstant(FILE *mips, int value);
int printAddition(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printSubtraction(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printMultiplication(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printDivision(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printRemainder(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);

// Assigns
int printAssignment(FILE *mips, int rightType, int rightReg);
void printAssignmentToReg(FILE *mips, int rightType, int rightReg, int leftReg);

// Relational expressions
int printGreaterThan(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printGreaterEqual(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printLessThan(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printLessEqual(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printEquals(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printNotEquals(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);

// Control structures
int printLogicalAnd(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID);
int printLogicalOr(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID);
void printIf(FILE *mips, int conditionType, int conditionReg, int label);

// Labels and jumps
void printJump(FILE *mips, char *label, int labelID);
void printLabel(FILE *mips, char *label, int labelID);

// Global variables
void printGlobalVariable(FILE *mips, char *name, int value);

// Output print
void printInteger(FILE *mips, int regType, int RegNumber);
void printString(FILE *mips, char *value, int stringID);

// Input scan
void printScanInt(FILE *mips);

// Function call
void printCallFunction(FILE *mips, char *name);
void printReturn(FILE *mips);

// Stack
void printStart(FILE *mips);
void printEnd(FILE *mips);

#endif