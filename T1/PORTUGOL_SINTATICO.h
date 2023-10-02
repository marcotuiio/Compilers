#ifndef _PORTUGOL_SINTATICO_H
#define _PORTUGOL_SINTATICO_H

#include "PORTUGOL_LEXICO.h"

// ENUM of Final States to be processed by syntax analyzer]
    // Todos os outros tokens 
    // (excluindo 1, 167 e 169)
    // são considerados ID

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
*/

// Receives the list of all tokens of the sentece, and starts to processes it
void processSyntax(void *cadeia, bool *textBefore);

// Receives the current token and expected token
// If current and expected are the same, then removes it from the list and gets the next token to be processed
// If they are different, then prints an error message
void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore);

// Following prototypes consist of the productions for every non terminal in the defined grammar
// Checks and process current token within the productions
void Start(void *cadeia, int *tokenGlobal, bool *textBefore); // Start
void Prog(void *cadeia, int *tokenGlobal, bool *textBefore);  // Programa
void PF(void *cadeia, int *tokenGlobal, bool *textBefore);  // ProcedimentoFuncao
void DProc(void *cadeia, int *tokenGlobal, bool *textBefore);  // DeclaraProcedimento
void DF(void *cadeia, int *tokenGlobal, bool *textBefore);  // DeclaraFuncao
void Param(void *cadeia, int *tokenGlobal, bool *textBefore);  // Parametros
void DParam(void *cadeia, int *tokenGlobal, bool *textBefore);  // DeclaraParametros
void BV(void *cadeia, int *tokenGlobal, bool *textBefore);  // BlocoVariaveis
void DS(void *cadeia, int *tokenGlobal, bool *textBefore);  // Declaracoes
void DS_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // Declaracoes'
void DT(void *cadeia, int *tokenGlobal, bool *textBefore);  // DeclaraTipo
void DV(void *cadeia, int *tokenGlobal, bool *textBefore);  // DeclaraVariaveis
void DI(void *cadeia, int *tokenGlobal, bool *textBefore);  // DeclaraIdentificador
void DI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // DeclaraIdentificador'
void VM(void *cadeia, int *tokenGlobal, bool *textBefore);  // VetorMatriz
void Dimen(void *cadeia, int *tokenGlobal, bool *textBefore);  // Dimensoes
void Dimen_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // Dimensoes'
void TB(void *cadeia, int *tokenGlobal, bool *textBefore);  // TipoBasico
void BC(void *cadeia, int *tokenGlobal, bool *textBefore);  // BlocoComandos
void LC(void *cadeia, int *tokenGlobal, bool *textBefore);  // ListaComandos
void LC_Prime(void *cadeia, int *tokenGlobal, bool *textBefore); // ListaComandos'
void C(void *cadeia, int *tokenGlobal, bool *textBefore);  // Comandos
void C_Prime1(void *cadeia, int *tokenGlobal, bool *textBefore);  // Comandos1'
void C_Prime2(void *cadeia, int *tokenGlobal, bool *textBefore);  // Comandos2'
void C_Prime3(void *cadeia, int *tokenGlobal, bool *textBefore);  // Comandos3'
void E(void *cadeia, int *tokenGlobal, bool *textBefore);  // Expressao
void E_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // Expressao'
void ES(void *cadeia, int *tokenGlobal, bool *textBefore);  // ExpressaoSimples
void ES_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // ExpressaoSimples'
void T(void *cadeia, int *tokenGlobal, bool *textBefore);  // Termo
void T_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // Termo'
void F(void *cadeia, int *tokenGlobal, bool *textBefore);  // Fator
void V(void *cadeia, int *tokenGlobal, bool *textBefore);  // Variavel
void V_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // Variavel'
void EI(void *cadeia, int *tokenGlobal, bool *textBefore);  // ExprIter
void EI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore);  // ExprIter'

// Prints syntax error message
void printResult(char *result, bool *textBefore);

// Returns the error message to be printed, analyzing the current token and the expected token
char *defineErro(int tokenGlobal, int tokenAnalisado);

// Checks if string is over when it shouldn't be
void incompleteString(void *cadeia, int *tokenGlobal, bool *textBefore, bool couldBeOver);

// Checks if current token is a valid ID and padronizes it to ID enum
void defineID(int *tokenGlobal);

// See what token its receiving and writes it to a string
void switchTokens(char *text, int token);

#endif