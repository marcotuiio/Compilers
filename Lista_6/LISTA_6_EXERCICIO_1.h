#ifndef _LISTA_6_EXERCICIO_1_H
#define _LISTA_6_EXERCICIO_1_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGMA 20
#define QNTD_FINAL 12
#define QNTD_SPECIAL 11

int getChar(char *reads, char input);
bool isFinal(int *finals, int current);
bool isSpecialTransition(int *states, char *transitions, int st, char in);
void printSession(char *output, int size);
void clearOutput(char *output, int size);

#endif