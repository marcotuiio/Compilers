#ifndef _ASH_H
#define _ASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *createAsmFile(char *fileName);

int printConstant(FILE *mips, int value);

int printAddition(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printSubtraction(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printMultiplication(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printDivision(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);
int printRemainder(FILE *mips, int leftType, int leftReg, int rightType, int rightReg);

int printAssignment(FILE *mips, int rightType, int rightReg);
void printAssignmentToReg(FILE *mips, int rightType, int rightReg, int leftReg);

void printGlobalVariable(FILE *mips, char *name, int value);

void printFunction(FILE *mips, char *name);
void printInteger(FILE *mips, int regType, int RegNumber);

void printString(FILE *mips, char *value);
void printScanInt(FILE *mips);

void printCallFunction(FILE *mips, char *name);
void printReturn(FILE *mips);

void printStart(FILE *mips);
void printEnd(FILE *mips);

#endif