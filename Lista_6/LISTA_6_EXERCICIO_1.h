#ifndef _LISTA_6_EXERCICIO_1_H
#define _LISTA_6_EXERCICIO_1_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGMA 20
#define QNTD_FINAL 12
#define QNTD_SPECIAL 11

// Returns the index of the char in the array, or -1 if it's not in the array
// Basicaally gets the column of the matrix (the state it goes to) that corresponds to the char read
int getChar(char *reads, char input);

// Return true if the current state is a final state, false otherwise
bool isFinal(int *finals, int current);

// Prints the token, and if there was text before it, prints a new line before printing the token
void printToken(bool *textBefore, char *toPrint);

// Prints the session, which is the chars that were read
void printSession(char *output, int size);

// Clears the output buffer and resets the output index
void clearOutput(char *output, int size, int *outputIndex);

// Resets the variables that are used in the main loop, so the automata can start reading the next token
void resetVariables(int *index, int indexToSet, int *backupIndex, int *end, int *currentState);

#endif