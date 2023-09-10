#ifndef _LISTA_5_EXERCICIO_2_H_
#define _LISTA_5_EXERCICIO_2_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getChar(char *reads, char input);
bool isFinal(int *finals, int current);
bool isSpecialTransition(int *states, char *transitions, int st, char in);

#define SIGMA 40
#define QNTD_FINAL 11
#define QNTD_SPECIAL 1

#endif