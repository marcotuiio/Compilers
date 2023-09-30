#ifndef _PORTUGOL_LEXICO_H
#define _PORTUGOL_LEXICO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#define SIGMA 78
#define QNTD_FINAL 6
#define MAX_INPUT 131072

// Returns the index of the char in the array, or -1 if it's not in the array
// Basically gets the column of the matrix (the state it goes to) that corresponds to the char read
int getChar(char *reads, char input);

// Return true if the current state is a final state, false otherwise
bool isFinal(int *finals, int current);

// Resets the variables that are used in the main loop, so the automata can start reading the next token
void resetVariables(int *index, int indexToSet, int *backupIndex, int *end, int *currentState);

// Prints the char that caused the error (first occurrence in the line)
void printErroLexico(char errado, bool *textBefore, bool *flagLexico);

#endif