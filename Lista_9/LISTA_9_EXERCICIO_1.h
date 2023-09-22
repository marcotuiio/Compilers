#ifndef _LISTA_9_EXERCICIO_1_H
#define _LISTA_9_EXERCICIO_1_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#define SIGMA 27
#define QNTD_FINAL 9

// ENUM of Final States to be processed by syntax analyzer
#define SEMICOLON 2
#define EQUAL 3
#define NUM 5
#define IF 7
#define THEN 11
#define BEGIN 16
#define PRINT 21
#define ELSE 25
#define END 27

// Returns the index of the char in the array, or -1 if it's not in the array
// Basicaally gets the column of the matrix (the state it goes to) that corresponds to the char read
int getChar(char *reads, char input);

// Return true if the current state is a final state, false otherwise
bool isFinal(int *finals, int current);

// Prints the token, and if there was text before it, prints a new line before printing the token
void printToken(bool *textBefore, char *toPrint);


// Resets the variables that are used in the main loop, so the automata can start reading the next token
void resetVariables(int *index, int indexToSet, int *backupIndex, int *end, int *currentState);

#endif