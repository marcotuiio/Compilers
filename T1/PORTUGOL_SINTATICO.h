#ifndef _PORTUGOL_SINTATICO_H
#define _PORTUGOL_SINTATICO_H

#include "PORTUGOL_LEXICO.h"

// ENUM of Final States to be processed by syntax analyzer]
#define ID 2
#define NUM_INT 3
#define NUM_REAL 4
#define SEMICOLON 5
#define COMMA 6
#define COLON 7
#define DOT 8
#define L_SBRACKET 9 
#define R_SBRACKET 10
#define L_PAREN 11
#define R_PAREN 12
#define EQUAL 13
#define GREATER 14
#define LESS 15
#define PLUS 16
#define MINUS 17
#define TIMES 18
#define DIV 19
#define ALGORITMO 28
#define ATE 30
#define DIFFERENT 31
#define GREATER_EQUAL 32
#define LESS_EQUAL 33
#define ATRIB 34

/*
    -----------> Syntax Analyzer <-----------
    S -> E$
    E -> TE'
    E' -> +TE'
    E' ->
    T -> FT'
    T' -> *FT'
    T' ->
    F -> (E)
    F -> id
*/

// Receives the list of all tokens of the sentece, and starts to processes it
void processSyntax(void *cadeia, bool *textBefore);

// Receives the current token and expected token
// If current and expected are the same, then removes it from the list and gets the next token to be processed
// If they are different, then prints an error message
void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore);

// Productions of non terminal S in the defined grammar
// Checks and process current token within the productions
void S(void *cadeia, int *tokenGlobal, bool *textBefore);

// Productions of non terminal E in the defined grammar
// Checks and process current token within the productions
void E(void *cadeia, int *tokenGlobal, bool *textBefore);

// Productions of non terminal E' in the defined grammar
// Checks and process current token within the productions
void E_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);

// Productions of non terminal T in the defined grammar
// Checks and process current token within the productions
void T(void *cadeia, int *tokenGlobal, bool *textBefore);

// Productions of non terminal T' in the defined grammar
// Checks and process current token within the productions
void T_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);

// Productions of non terminal F in the defined grammar
// Checks and process current token within the productions
void F(void *cadeia, int *tokenGlobal, bool *textBefore);

// Prints syntax error message
void printResult(char *result, bool *textBefore);

// Returns the error message to be printed, analyzing the current token and the expected token
char *defineErro(int tokenGlobal, int tokenAnalisado);

// Checks if string is over when it shouldn't be
void incompleteString(void *cadeia, int *tokenGlobal, bool *textBefore, bool couldBeOver);

// See what token its receiving and writes it to a string
void switchTokens(char *text, int token);

#endif