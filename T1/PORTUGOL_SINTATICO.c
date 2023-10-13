// Author: Marco Túlio Alves de Barros

#include "PORTUGOL_SINTATICO.h"

void processSyntax(void *cadeia, bool *textBefore, char *input) {
    int tokenGlobal = getNode(cadeia);
    if (tokenGlobal == -1) {
        printResult("ERRO LISTA VAZIA", textBefore);  // this shouldnt appear
        exit(0);
    }
    defineID(&tokenGlobal);
    Start(cadeia, &tokenGlobal, textBefore, input);  // S is the initial symbol
}

void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore, char *input) {
    if (tokenAnalisado == *tokenGlobal) {  // means that the token was accepted and can be removed from the list
        removeNode(cadeia);
        *tokenGlobal = getNode(cadeia);
        defineID(tokenGlobal);

    } else {
        int column = getColumn(cadeia) - strlen(getTokenContent(cadeia)) + 1;
        printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLine(cadeia), column, getTokenContent(cadeia));
        freeList(cadeia);
        free(input);
        exit(-2);
    }
}

void handleError(void *cadeia) {
    int column = getColumn(cadeia) - strlen(getTokenContent(cadeia)) + 1;
    printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLine(cadeia), column, getTokenContent(cadeia));
}

void printResult(char *result, bool *textBefore) {
    if (!result) return;
    if (*textBefore) printf("\n");
    printf("%s", result);
    *textBefore = true;
}

void Start(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ALGORITMO:
            Prog(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, EOF_TOKEN, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void Prog(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ALGORITMO:
            eatToken(cadeia, ALGORITMO, tokenGlobal, textBefore, input);

            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            BV(cadeia, tokenGlobal, textBefore, input);

            PF(cadeia, tokenGlobal, textBefore, input);

            BC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO, tokenGlobal, textBefore, input);

            break;

        case EOF_TOKEN:
            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void PF(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PROCEDIMENTO:
            DProc(cadeia, tokenGlobal, textBefore, input);

            PF(cadeia, tokenGlobal, textBefore, input);

            break;

        case FUNCAO:
            DF(cadeia, tokenGlobal, textBefore, input);

            PF(cadeia, tokenGlobal, textBefore, input);

            break;

        case INICIO:
            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DProc(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PROCEDIMENTO:
            eatToken(cadeia, PROCEDIMENTO, tokenGlobal, textBefore, input);

            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            Param(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            DParam(cadeia, tokenGlobal, textBefore, input);

            BV(cadeia, tokenGlobal, textBefore, input);

            BC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DF(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case FUNCAO:
            eatToken(cadeia, FUNCAO, tokenGlobal, textBefore, input);

            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            Param(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, DOIS_PONTOS, tokenGlobal, textBefore, input);

            TB(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            DParam(cadeia, tokenGlobal, textBefore, input);

            BV(cadeia, tokenGlobal, textBefore, input);

            BC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void Param(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
        case DOIS_PONTOS:
            break;

        case ABRE_PARENTESES:
            eatToken(cadeia, ABRE_PARENTESES, tokenGlobal, textBefore, input);

            DI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_PARENTESES, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DParam(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case TIPO:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            DS(cadeia, tokenGlobal, textBefore, input);

            break;

        case PROCEDIMENTO:
        case FUNCAO:
        case VARIAVEIS:
        case INICIO:
            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void BV(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PROCEDIMENTO:
        case FUNCAO:
        case INICIO:
        case EOF_TOKEN:
            break;

        case VARIAVEIS:
            eatToken(cadeia, VARIAVEIS, tokenGlobal, textBefore, input);

            DS(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DS(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            DV(cadeia, tokenGlobal, textBefore, input);

            DS_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case TIPO:
            DT(cadeia, tokenGlobal, textBefore, input);

            DS_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DS_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case TIPO:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            DS(cadeia, tokenGlobal, textBefore, input);

            break;

        case PROCEDIMENTO:
        case FUNCAO:
        case VARIAVEIS:
        case INICIO:
        case EOF_TOKEN:
            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DT(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case TIPO:
            eatToken(cadeia, TIPO, tokenGlobal, textBefore, input);

            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            eatToken(cadeia, IGUAL, tokenGlobal, textBefore, input);

            VM(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, ABRE_COLCHETE, tokenGlobal, textBefore, input);

            Dimen(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_COLCHETE, tokenGlobal, textBefore, input);

            TB(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DV(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
            TB(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, DOIS_PONTOS, tokenGlobal, textBefore, input);

            DI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DI(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            DI_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void DI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
        case FECHA_PARENTESES:
            break;

        case VIRGULA:
            eatToken(cadeia, VIRGULA, tokenGlobal, textBefore, input);

            DI(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void VM(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case VETOR:
            eatToken(cadeia, VETOR, tokenGlobal, textBefore, input);

            break;

        case MATRIZ:
            eatToken(cadeia, MATRIZ, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void Dimen(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case NUM_INT:
            eatToken(cadeia, NUM_INT, tokenGlobal, textBefore, input);

            eatToken(cadeia, DOIS_PONTOS, tokenGlobal, textBefore, input);

            eatToken(cadeia, NUM_INT, tokenGlobal, textBefore, input);

            Dimen_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void Dimen_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case FECHA_COLCHETE:
            break;

        case VIRGULA:
            eatToken(cadeia, VIRGULA, tokenGlobal, textBefore, input);

            Dimen(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void TB(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            break;

        case INTEIRO:
            eatToken(cadeia, INTEIRO, tokenGlobal, textBefore, input);

            break;

        case REAL:
            eatToken(cadeia, REAL, tokenGlobal, textBefore, input);

            break;

        case CARACTERE:
            eatToken(cadeia, CARACTERE, tokenGlobal, textBefore, input);

            break;

        case LOGICO:
            eatToken(cadeia, LOGICO, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void BC(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case INICIO:
            eatToken(cadeia, INICIO, tokenGlobal, textBefore, input);

            LC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FIM, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void LC(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            C(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore, input);

            LC_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void LC_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            LC(cadeia, tokenGlobal, textBefore, input);

            break;

        case FIM:
        case SENAO:
        case ATE:
            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void C(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            C_Prime1(cadeia, tokenGlobal, textBefore, input);

            break;

        case SE:
            eatToken(cadeia, SE, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, ENTAO, tokenGlobal, textBefore, input);

            LC(cadeia, tokenGlobal, textBefore, input);

            C_Prime2(cadeia, tokenGlobal, textBefore, input);

            break;

        case ENQUANTO:
            eatToken(cadeia, ENQUANTO, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FACA, tokenGlobal, textBefore, input);

            LC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FIM, tokenGlobal, textBefore, input);

            eatToken(cadeia, ENQUANTO, tokenGlobal, textBefore, input);

            break;

        case PARA:
            eatToken(cadeia, PARA, tokenGlobal, textBefore, input);

            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            eatToken(cadeia, DE, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, ATE, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            C_Prime3(cadeia, tokenGlobal, textBefore, input);

            break;

        case REPITA:
            eatToken(cadeia, REPITA, tokenGlobal, textBefore, input);

            LC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, ATE, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            break;

        case LEIA:
            eatToken(cadeia, LEIA, tokenGlobal, textBefore, input);

            eatToken(cadeia, ABRE_PARENTESES, tokenGlobal, textBefore, input);

            V(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_PARENTESES, tokenGlobal, textBefore, input);

            break;

        case IMPRIMA:
            eatToken(cadeia, IMPRIMA, tokenGlobal, textBefore, input);

            eatToken(cadeia, ABRE_PARENTESES, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_PARENTESES, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void C_Prime1(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
            // case ID:
            //     V(cadeia, tokenGlobal, textBefore, input);

            //     eatToken(cadeia, ATRIBUICAO, tokenGlobal, textBefore, input);

            //     E(cadeia, tokenGlobal, textBefore, input);

            //     break;

        case PONTO_VIRGULA:
            break;

        case ABRE_PARENTESES:
            eatToken(cadeia, ABRE_PARENTESES, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_PARENTESES, tokenGlobal, textBefore, input);

            break;

        case ABRE_COLCHETE:
            eatToken(cadeia, ABRE_COLCHETE, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_COLCHETE, tokenGlobal, textBefore, input);

            eatToken(cadeia, ATRIBUICAO, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            break;

        case ATRIBUICAO:
            eatToken(cadeia, ATRIBUICAO, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void C_Prime2(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case FIM:
            eatToken(cadeia, FIM, tokenGlobal, textBefore, input);

            eatToken(cadeia, SE, tokenGlobal, textBefore, input);

            break;

        case SENAO:
            eatToken(cadeia, SENAO, tokenGlobal, textBefore, input);

            LC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FIM, tokenGlobal, textBefore, input);

            eatToken(cadeia, SE, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void C_Prime3(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case FACA:
            eatToken(cadeia, FACA, tokenGlobal, textBefore, input);

            LC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FIM, tokenGlobal, textBefore, input);

            eatToken(cadeia, PARA, tokenGlobal, textBefore, input);

            break;

        case PASSO:
            eatToken(cadeia, PASSO, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FACA, tokenGlobal, textBefore, input);

            LC(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FIM, tokenGlobal, textBefore, input);

            eatToken(cadeia, PARA, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void E(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case NUM_INT:
        case NUM_REAL:
        case NAO:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case ABRE_PARENTESES:
        case MAIS:
        case MENOS:
            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void E_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
        case FECHA_PARENTESES:
        case FECHA_COLCHETE:
        case VIRGULA:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
            break;

        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR:
        case MAIOR_IGUAL:
            OPRel(cadeia, tokenGlobal, textBefore, input);

            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void ES(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case NUM_INT:
        case NUM_REAL:
        case NAO:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case ABRE_PARENTESES:
            T(cadeia, tokenGlobal, textBefore, input);

            ES_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case MAIS:
        case MENOS:
            OPBin(cadeia, tokenGlobal, textBefore, input);

            T(cadeia, tokenGlobal, textBefore, input);

            ES_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void ES_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
        case FECHA_PARENTESES:
        case FECHA_COLCHETE:
        case VIRGULA:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR:
        case MAIOR_IGUAL:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
            break;

        case MAIS:
        case MENOS:
            OPBin(cadeia, tokenGlobal, textBefore, input);

            T(cadeia, tokenGlobal, textBefore, input);

            ES_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case OU:
            eatToken(cadeia, OU, tokenGlobal, textBefore, input);

            T(cadeia, tokenGlobal, textBefore, input);

            ES_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void OPRel(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case IGUAL:
            eatToken(cadeia, IGUAL, tokenGlobal, textBefore, input);

            break;

        case DIFERENTE:
            eatToken(cadeia, DIFERENTE, tokenGlobal, textBefore, input);

            break;

        case MAIOR:
            eatToken(cadeia, MAIOR, tokenGlobal, textBefore, input);

            break;

        case MAIOR_IGUAL:
            eatToken(cadeia, MAIOR_IGUAL, tokenGlobal, textBefore, input);

            break;

        case MENOR:
            eatToken(cadeia, MENOR, tokenGlobal, textBefore, input);

            break;

        case MENOR_IGUAL:
            eatToken(cadeia, MENOR_IGUAL, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void OPBin(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case MAIS:
            eatToken(cadeia, MAIS, tokenGlobal, textBefore, input);

            break;

        case MENOS:
            eatToken(cadeia, MENOS, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void T(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case NUM_INT:
        case NUM_REAL:
        case NAO:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case ABRE_PARENTESES:
            F(cadeia, tokenGlobal, textBefore, input);

            T_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void T_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
        case FECHA_PARENTESES:
        case FECHA_COLCHETE:
        case VIRGULA:
        case IGUAL:
        case DIFERENTE:
        case MAIOR:
        case MAIOR_IGUAL:
        case MENOR:
        case MENOR_IGUAL:
        case MAIS:
        case MENOS:
        case OU:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
            break;

        case VEZES:
            eatToken(cadeia, VEZES, tokenGlobal, textBefore, input);

            F(cadeia, tokenGlobal, textBefore, input);

            T_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case DIVISAO:
            eatToken(cadeia, DIVISAO, tokenGlobal, textBefore, input);

            F(cadeia, tokenGlobal, textBefore, input);

            T_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case DIV:
            eatToken(cadeia, DIV, tokenGlobal, textBefore, input);

            F(cadeia, tokenGlobal, textBefore, input);

            T_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case AND:
            eatToken(cadeia, AND, tokenGlobal, textBefore, input);

            F(cadeia, tokenGlobal, textBefore, input);

            T_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void F(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            F_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case NUM_INT:
            eatToken(cadeia, NUM_INT, tokenGlobal, textBefore, input);

            break;

        case NUM_REAL:
            eatToken(cadeia, NUM_REAL, tokenGlobal, textBefore, input);

            break;

        case VERDADEIRO:
            eatToken(cadeia, VERDADEIRO, tokenGlobal, textBefore, input);

            break;

        case FALSO:
            eatToken(cadeia, FALSO, tokenGlobal, textBefore, input);

            break;

        case STRING:
            eatToken(cadeia, STRING, tokenGlobal, textBefore, input);

            break;

        case NAO:
            eatToken(cadeia, NAO, tokenGlobal, textBefore, input);

            F(cadeia, tokenGlobal, textBefore, input);

            break;

        case ABRE_PARENTESES:
            eatToken(cadeia, ABRE_PARENTESES, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_PARENTESES, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void F_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
        case FECHA_PARENTESES:
        case FECHA_COLCHETE:
        case VIRGULA:
        case IGUAL:
        case DIFERENTE:
        case MAIOR:
        case MAIOR_IGUAL:
        case MENOR:
        case MENOR_IGUAL:
        case MAIS:
        case MENOS:
        case OU:
        case VEZES:
        case DIVISAO:
        case DIV:
        case AND:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
            break;

        case ABRE_PARENTESES:
            eatToken(cadeia, ABRE_PARENTESES, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_PARENTESES, tokenGlobal, textBefore, input);

            break;

        case ABRE_COLCHETE:
            eatToken(cadeia, ABRE_COLCHETE, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_COLCHETE, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void V(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore, input);

            V_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void V_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case FECHA_PARENTESES:
            // case ATRIBUICAO:
            break;

        case ABRE_COLCHETE:
            eatToken(cadeia, ABRE_COLCHETE, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_COLCHETE, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void EI(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
        case NUM_INT:
        case NUM_REAL:
        case NAO:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case MAIS:
        case MENOS:
        case ABRE_PARENTESES:
            E(cadeia, tokenGlobal, textBefore, input);

            EI_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void EI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case FECHA_PARENTESES:
        case FECHA_COLCHETE:
            break;

        case VIRGULA:
            eatToken(cadeia, VIRGULA, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void defineID(int *tokenGlobal) {
    if (*tokenGlobal != -1 && *tokenGlobal != 1 && *tokenGlobal != EOF_TOKEN) {
        if (*tokenGlobal >= NUM_INT && *tokenGlobal <= DIVISAO) return;            // reservados
        if (*tokenGlobal >= DIFERENTE && *tokenGlobal <= ATRIBUICAO) return;       // reservados
        if (*tokenGlobal >= PROCEDIMENTO && *tokenGlobal <= COMENT_BLOCO) return;  // reservados

        if (*tokenGlobal == ALGORITMO || *tokenGlobal == ATE || *tokenGlobal == INICIO || *tokenGlobal == IMPRIMA ||
            *tokenGlobal == FIM || *tokenGlobal == FUNCAO || *tokenGlobal == FACA || *tokenGlobal == FALSO ||
            *tokenGlobal == VARIAVEIS || *tokenGlobal == VETOR) return;

        if (*tokenGlobal == VERDADEIRO || *tokenGlobal == INTEIRO || *tokenGlobal == REAL || *tokenGlobal == REPITA ||
            *tokenGlobal == SE || *tokenGlobal == SENAO || *tokenGlobal == AND || *tokenGlobal == ENTAO ||
            *tokenGlobal == ENQUANTO || *tokenGlobal == DE || *tokenGlobal == DIV) return;

        if (*tokenGlobal == OU || *tokenGlobal == NAO || *tokenGlobal == TIPO || *tokenGlobal == LEIA ||
            *tokenGlobal == LOGICO || *tokenGlobal == MATRIZ || *tokenGlobal == CARACTERE || *tokenGlobal == PARA ||
            *tokenGlobal == PASSO || *tokenGlobal == PROCEDIMENTO) return;

        *tokenGlobal = ID;  // se passou por todas as palavras e tokens resevados, entao eh um identificador
    }
}
