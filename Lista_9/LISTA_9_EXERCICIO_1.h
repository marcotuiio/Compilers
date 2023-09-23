#ifndef _LISTA_9_EXERCICIO_1_H
#define _LISTA_9_EXERCICIO_1_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#define SIGMA 27
#define QNTD_FINAL 9
#define MAX_INPUT 131072

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

// -----------> Syntax Analyzer <-----------

// Receives the list of all tokens of the sentece, and starts to processes it
void processSyntax(void *cadeia, bool *textBefore);

// Receives the current token and expected token
// If current and expected are the same, then removes it from the list and gets the next token to be processed
// If they are different, then prints an error message
void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore);

// Productions of non terminal S in the defined grammar
// Checks and process current token within the productions
void S(void *cadeia, int *tokenGlobal, bool *textBefore);

// Productions of non terminal L in the defined grammar
// Checks and process current token within the productions
void L(void *cadeia, int *tokenGlobal, bool *textBefore);

// Productions of non terminal E in the defined grammar
// Checks and process current token within the productions
void E(void *cadeia, int *tokenGlobal, bool *textBefore);

// Prints syntax error message
void printResult(char *result, bool *textBefore);

// Returns the error message to be printed, analyzing the current token and the expected token
char *defineErro(int tokenGlobal, int tokenAnalisado);

// Checks if string is over when it shouldn't be
void incompleteString(void *cadeia, int *tokenGlobal, bool *textBefore);

// See what token its receiving and writes it to a string
void switchTokens(char *text, int token);

#endif