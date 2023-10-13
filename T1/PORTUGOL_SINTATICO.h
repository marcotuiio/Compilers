// Author: Marco Túlio Alves de Barros

#ifndef _PORTUGOL_SINTATICO_H
#define _PORTUGOL_SINTATICO_H

#include "PORTUGOL_LEXICO.h"

// ENUM of Final States to be processed by syntax analyzer
// Como todos os outros tokens (excluindo 1, 167 e 169)
// são considerados ID, então por padrão, ID = 2

#define ID 2
#define NUM_INT 3
#define NUM_REAL 4
#define PONTO_VIRGULA 5
#define VIRGULA 6
#define DOIS_PONTOS 7
#define PONTO 8
#define ABRE_COLCHETE 9
#define FECHA_COLCHETE 10
#define ABRE_PARENTESES 11
#define FECHA_PARENTESES 12
#define IGUAL 13
#define MAIOR 14
#define MENOR 15
#define MAIS 16
#define MENOS 17
#define VEZES 18
#define DIVISAO 19
#define ALGORITMO 28
#define ATE 30
#define DIFERENTE 31
#define MAIOR_IGUAL 32
#define MENOR_IGUAL 33
#define ATRIBUICAO 34
#define INICIO 40
#define IMPRIMA 46
#define FIM 49
#define FUNCAO 54
#define FACA 57
#define FALSO 60
#define VARIAVEIS 69
#define VETOR 73
#define VERDADEIRO 81
#define INTEIRO 86
#define REAL 90
#define REPITA 94
#define SE 96
#define SENAO 99
#define AND 100  // E
#define ENTAO 104
#define ENQUANTO 110
#define DE 112
#define DIV 114
#define OU 116
#define NAO 119
#define TIPO 123
#define LEIA 127
#define LOGICO 132
#define MATRIZ 138
#define CARACTERE 147
#define PARA 151
#define PASSO 154
#define PROCEDIMENTO 165
#define COMENT_LINHA 166
#define STRING 168
#define COMENT_BLOCO 170
#define EOF_TOKEN 666

/*
    -----------> Syntax Analyzer via Recursive Descent <-----------

START -> PROG $

PROG -> algoritmo id ; BV PF BC .

PF -> DPROC PF
PF -> DF PF
PF -> ''

DPROC -> procedimento id PARAM ; DPARAM BV BC ;
DF -> funcao id PARAM : TB ; DPARAM BV BC ;

PARAM -> ( DI )
PARAM -> ''

DPARAM -> DS
DPARAM -> ''

BV -> variaveis DS
BV -> ''

DS -> DV DS_PRIME
DS -> DT DS_PRIME

DS_PRIME -> DS
DS_PRIME -> ''

DT -> tipo id = VM [ DIMEN ] TB ;

DV -> TB : DI ;

DI -> id DI_PRIME
DI_PRIME -> , DI
DI_PRIME -> ''

VM -> vetor
VM -> matriz

DIMEN -> num_int : num_int DIMEN_PRIME
DIMEN_PRIME -> , DIMEN
DIMEN_PRIME -> ''

TB -> inteiro
TB -> real
TB -> caractere
TB -> logico
TB -> id

BC -> inicio LC fim

LC -> C ; LC_PRIME
LC_PRIME -> LC
LC_PRIME -> ''

C -> id C_PRIME1
C_PRIME1 -> ( EI )
C_PRIME1 -> <- E
C_PRIME1 -> [ EI ] <- E
C_PRIME1 -> ''

C -> se E entao LC C_PRIME2
C_PRIME2 -> fim se
C_PRIME2 -> senao LC fim se

C -> enquanto E faca LC fim enquanto

C -> para id de E ate E C_PRIME3
C_PRIME3 -> faca LC fim para
C_PRIME3 -> passo E faca LC fim para

C -> repita LC ate E
C -> leia ( V )
C -> imprima ( EI )

E -> ES E_PRIME
E_PRIME -> OpR ES E_PRIME
E_PRIME -> ''

ES -> T ES_PRIME
ES -> OpB T ES_PRIME
ES_PRIME -> OpB T ES_PRIME
ES_PRIME -> ou T ES_PRIME
ES_PRIME -> ''

OpR -> =
OpR -> <>
OpR -> <
OpR -> >
OpR -> >=
OpR -> <=

OpB -> +
OpB -> -

T -> F T_PRIME
T_PRIME -> * F T_PRIME
T_PRIME -> / F T_PRIME
T_PRIME -> div F T_PRIME
T_PRIME -> e F T_PRIME
T_PRIME -> ''

F -> ( E )
F -> nao F
F -> num_int
F -> num_real
F -> verdadeiro
F -> falso
F -> string

F -> id F_PRIME
F_PRIME -> ( EI )
F_PRIME -> [ EI ]
F_PRIME -> ''

V -> id V_PRIME
V_PRIME -> [ EI ]
V_PRIME -> ''

EI -> E EI_PRIME
EI_PRIME -> , EI
EI_PRIME -> ''

*/

// Receives the list of all tokens of the sentece, and starts to processes it
void processSyntax(void *cadeia, bool *textBefore, char *input);

// Receives the current token and expected token
// If current and expected are the same, then removes it from the list and gets the next token to be processed
// If they are different, then prints an error message
void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore, char *input);

// Prints syntax error message
void printResult(char *result, bool *textBefore);

// Returns the error message to be printed, analyzing the current token and the expected token
void handleError(void *cadeia);

// Following prototypes consist of the productions for every non terminal in the defined grammar
// Checks and process current token within the productions
void Start(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);        // Start
void Prog(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);         // Programa
void PF(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // ProcedimentoFuncao
void DProc(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);        // DeclaraProcedimento
void DF(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // DeclaraFuncao
void Param(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);        // Parametros
void DParam(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);       // DeclaraParametros
void BV(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // BlocoVariaveis
void DS(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // Declaracoes
void DS_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // Declaracoes'
void DT(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // DeclaraTipo
void DV(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // DeclaraVariaveis
void DI(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // DeclaraIdentificador
void DI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // DeclaraIdentificador'
void VM(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // VetorMatriz
void Dimen(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);        // Dimensoes
void Dimen_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);  // Dimensoes'
void TB(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // TipoBasico
void BC(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // BlocoComandos
void LC(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // ListaComandos
void LC_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // ListaComandos'
void C(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);            // Comandos
void C_Prime1(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // Comandos1'
void C_Prime2(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // Comandos2'
void C_Prime3(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // Comandos3'
void E(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);            // Expressao
void E_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);      // Expressao'
void ES(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // ExpressaoSimples
void ES_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // ExpressaoSimples'
void OPRel(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);        // OperadorRelacional
void OPBin(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);        // OperadorBinario
void T(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);            // Termo
void T_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);      // Termo'
void F(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);            // Fator
void F_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);      // Fator'
void V(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);            // Variavel
void V_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);      // Variavel'
void EI(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);           // ExprIter
void EI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input);     // ExprIter'

// Checks if current token is a valid ID and padronizes it to ID enum
void defineID(int *tokenGlobal);

#endif