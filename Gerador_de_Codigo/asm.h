#ifndef _ASH_H
#define _ASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *createAsmFile(char *fileName);
void printAddition(FILE *mips, int left, int right);
void printSubtraction(FILE *mips, int left, int right);
void printMultiplication(FILE *mips, int left, int right);
void printDivision(FILE *mips, int left, int right);
void printRemainder(FILE *mips, int left, int right);
void printAssignment(FILE *mips, int value);
void printGlobalVariable(FILE *mips, char *name, int value);
void printFunction(FILE *mips, char *name);
void printInteger(FILE *mips, int value);
void printString(FILE *mips, char *value);
void printScanInt(FILE *mips);
void printCallFunction(FILE *mips, char *name);
void printReturn(FILE *mips);
void printStart(FILE *mips);
void printEnd(FILE *mips);

#endif