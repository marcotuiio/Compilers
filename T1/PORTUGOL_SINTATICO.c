#include "PORTUGOL_SINTATICO.h"

// bool errorFlag = false;

void processSyntax(void *cadeia, bool *textBefore, char *input) {
    int tokenGlobal = getNode(cadeia);
    if (tokenGlobal == -1) {
        printResult("ERRO LISTA VAZIA", textBefore);  // this shouldnt appear
        exit(0);
    }
    defineID(&tokenGlobal);
    // errorFlag = false;
    Start(cadeia, &tokenGlobal, textBefore, input);  // S is the initial symbol
}

void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore, char *input) {
    if (tokenAnalisado == *tokenGlobal) {  // means that the token was accepted and can be removed from the list
        removeNode(cadeia);
        *tokenGlobal = getNode(cadeia);
        defineID(tokenGlobal);

    } else {
        // if (getLine(cadeia) == -1 || getColumn(cadeia) == -1) return;
        int column =  getColumn(cadeia) - strlen(getTokenContent(cadeia)) + 1;
        printf("ERRO DE SINTAXE. Linha: %d Coluna %d -> '%s'", getLine(cadeia), column, getTokenContent(cadeia));
        freeList(cadeia);
        free(input);
        exit(-2);
    }
}

void Start(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ALGORITMO:
            Prog(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, EOF_TOKEN, tokenGlobal, textBefore, input);

            break;

        default:
            printf("Default case START: %d\n", *tokenGlobal);
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
            printf("Default case PROG: %d\n", *tokenGlobal);
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
            printf("Default case PF: %d\n", *tokenGlobal);
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
            printf("Default case DPROC: %d\n", *tokenGlobal);
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
            printf("Default case DF: %d\n", *tokenGlobal);
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
            printf("Default case PARAM: %d\n", *tokenGlobal);
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
            printf("Default case DPARAM: %d\n", *tokenGlobal);
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
            printf("Default case BV: %d\n", *tokenGlobal);
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
            printf("Default case DS: %d\n", *tokenGlobal);
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
            printf("Default case DSPRIME: %d\n", *tokenGlobal);
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
            printf("Default case DT: %d\n", *tokenGlobal);
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
            printf("Default case DV: %d\n", *tokenGlobal);
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
            printf("Default case DI: %d\n", *tokenGlobal);
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
            printf("Default case DIPRIME: %d\n", *tokenGlobal);
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
            printf("Default case VM: %d\n", *tokenGlobal);
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
            printf("Default case DIMEN: %d\n", *tokenGlobal);
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
            printf("Default case DIMENPRIME: %d\n", *tokenGlobal);
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
            printf("Default case TB: %d\n", *tokenGlobal);
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
            printf("Default case BC: %d\n", *tokenGlobal);
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
            printf("Default case LC: %d\n", *tokenGlobal);
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
            printf("Default case LCPRIME: %d\n", *tokenGlobal);
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
            printf("Default case C: %d\n", *tokenGlobal);
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void C_Prime1(void *cadeia, int *tokenGlobal, bool *textBefore, char *input) {
    switch (*tokenGlobal) {
        case ID:
            V(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, ATRIBUICAO, tokenGlobal, textBefore, input);

            E(cadeia, tokenGlobal, textBefore, input);

            break;

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
            printf("Default case CPRIME1: %d\n", *tokenGlobal);
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
            printf("Default case CPRIME2: %d\n", *tokenGlobal);
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
            printf("Default case CPRIME3: %d\n", *tokenGlobal);
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
            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            printf("Default case E: %d\n", *tokenGlobal);
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
            eatToken(cadeia, IGUAL, tokenGlobal, textBefore, input);

            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case DIFERENTE:
            eatToken(cadeia, DIFERENTE, tokenGlobal, textBefore, input);

            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case MENOR:
            eatToken(cadeia, MENOR, tokenGlobal, textBefore, input);

            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case MAIOR:
            eatToken(cadeia, MAIOR, tokenGlobal, textBefore, input);

            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case MENOR_IGUAL:
            eatToken(cadeia, MENOR_IGUAL, tokenGlobal, textBefore, input);

            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case MAIOR_IGUAL:
            eatToken(cadeia, MAIOR_IGUAL, tokenGlobal, textBefore, input);

            ES(cadeia, tokenGlobal, textBefore, input);

            E_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            printf("Default case EPRIME: %d\n", *tokenGlobal);
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

        default:
            printf("Default case ES: %d\n", *tokenGlobal);
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
            eatToken(cadeia, MAIS, tokenGlobal, textBefore, input);

            T(cadeia, tokenGlobal, textBefore, input);

            ES_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case MENOS:
            eatToken(cadeia, MENOS, tokenGlobal, textBefore, input);

            T(cadeia, tokenGlobal, textBefore, input);

            ES_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        case OU:
            eatToken(cadeia, OU, tokenGlobal, textBefore, input);

            T(cadeia, tokenGlobal, textBefore, input);

            ES_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            printf("Default case ESPRIME: %d\n", *tokenGlobal);
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
            printf("Default case T: %d\n", *tokenGlobal);
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
            printf("Default case TPRIME: %d\n", *tokenGlobal);
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
            printf("Default case F: %d\n", *tokenGlobal);
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
            printf("Default case FPRIME: %d\n", *tokenGlobal);
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
            printf("Default case V: %d\n", *tokenGlobal);
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
        case ATRIBUICAO:
            break;

        case ABRE_COLCHETE:
            eatToken(cadeia, ABRE_COLCHETE, tokenGlobal, textBefore, input);

            EI(cadeia, tokenGlobal, textBefore, input);

            eatToken(cadeia, FECHA_COLCHETE, tokenGlobal, textBefore, input);

            break;

        default:
            printf("Default case VPRIME: %d\n", *tokenGlobal);
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
        case ABRE_PARENTESES:
            E(cadeia, tokenGlobal, textBefore, input);

            EI_Prime(cadeia, tokenGlobal, textBefore, input);

            break;

        default:
            printf("Default case EI: %d\n", *tokenGlobal);
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
            printf("Default case EIPRIME: %d\n", *tokenGlobal);
            handleError(cadeia);
            freeList(cadeia);
            free(input);
            exit(-2);
            break;
    }
}

void printResult(char *result, bool *textBefore) {
    if (!result) return;
    if (*textBefore) printf("\n");
    printf("%s", result);
    *textBefore = true;
}

void handleError(void *cadeia) {
    int column = getColumn(cadeia) - strlen(getTokenContent(cadeia)) + 1;
    printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLine(cadeia), column, getTokenContent(cadeia));
}

void incompleteString(void *cadeia, int *tokenGlobal, bool *textBefore, bool couldBeOver) {
    if (getNode(cadeia) == -1 && couldBeOver) {
        printResult("ERRO SINTATICO: CADEIA INCOMPLETA", textBefore);  // dont think this is possible
        // errorFlag = true;
        freeList(cadeia);
        exit(-2);
    }
}

void defineID(int *tokenGlobal) {
    // printf("\nDEFININDO TOKEN %d -> ", *tokenGlobal);
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
        // printf(" %d\n", *tokenGlobal);
    }
}

void switchTokens(char *text, int token) {
    switch (token) {
        case -1:
            break;
        case ID:
            strcat(text, " id");
            break;
        case NUM_INT:
            strcat(text, " num_int");
            break;
        case NUM_REAL:
            strcat(text, " numero_real");
            break;
        case PONTO_VIRGULA:
            strcat(text, " ;");
            break;
        case VIRGULA:
            strcat(text, " ,");
            break;
        case DOIS_PONTOS:
            strcat(text, " :");
            break;
        case PONTO:
            strcat(text, " .");
            break;
        case ABRE_COLCHETE:
            strcat(text, " [");
            break;
        case FECHA_COLCHETE:
            strcat(text, " ]");
            break;
        case ABRE_PARENTESES:
            strcat(text, " (");
            break;
        case FECHA_PARENTESES:
            strcat(text, " )");
            break;
        case IGUAL:
            strcat(text, " =");
            break;
        case MAIOR:
            strcat(text, " >");
            break;
        case MENOR:
            strcat(text, " <");
            break;
        case MAIS:
            strcat(text, " +");
            break;
        case MENOS:
            strcat(text, " -");
            break;
        case VEZES:
            strcat(text, " *");
            break;
        case DIVISAO:
            strcat(text, " /");
            break;
        case ALGORITMO:
            strcat(text, " algoritmo");
            break;
        case ATE:
            strcat(text, " ate");
            break;
        case DIFERENTE:
            strcat(text, " <>");
            break;
        case MAIOR_IGUAL:
            strcat(text, " >=");
            break;
        case MENOR_IGUAL:
            strcat(text, " <=");
            break;
        case ATRIBUICAO:
            strcat(text, " <-");
            break;
        case INICIO:
            strcat(text, " inicio");
            break;
        case IMPRIMA:
            strcat(text, " imprima");
            break;
        case FIM:
            strcat(text, " fim");
            break;
        case FUNCAO:
            strcat(text, " funcao");
            break;
        case FACA:
            strcat(text, " faca");
            break;
        case FALSO:
            strcat(text, " falso");
            break;
        case VARIAVEIS:
            strcat(text, " variaveis");
            break;
        case VETOR:
            strcat(text, " vetor");
            break;
        case VERDADEIRO:
            strcat(text, " verdadeiro");
            break;
        case INTEIRO:
            strcat(text, " inteiro");
            break;
        case REAL:
            strcat(text, " real");
            break;
        case REPITA:
            strcat(text, " repita");
            break;
        case SE:
            strcat(text, " se");
            break;
        case SENAO:
            strcat(text, " senao");
            break;
        case AND:
            strcat(text, " e");
            break;
        case ENTAO:
            strcat(text, " entao");
            break;
        case ENQUANTO:
            strcat(text, " enquanto");
            break;
        case DE:
            strcat(text, " de");
            break;
        case DIV:
            strcat(text, " div");
            break;
        case OU:
            strcat(text, " ou");
            break;
        case NAO:
            strcat(text, " nao");
            break;
        case TIPO:
            strcat(text, " tipo");
            break;
        case LEIA:
            strcat(text, " leia");
            break;
        case LOGICO:
            strcat(text, " logico");
            break;
        case MATRIZ:
            strcat(text, " matriz");
            break;
        case CARACTERE:
            strcat(text, " caractere");
            break;
        case PARA:
            strcat(text, " para");
            break;
        case PASSO:
            strcat(text, " passo");
            break;
        case PROCEDIMENTO:
            strcat(text, " procedimento");
            break;
        case COMENT_LINHA:
            strcat(text, " comentario de linha");  // this token sholdnt appear in syntax analysis
            break;
        case STRING:
            strcat(text, " string");
            break;
        case COMENT_BLOCO:
            strcat(text, " comentario de bloco");  // this token sholdnt appear in syntax analysis
            break;
        case EOF_TOKEN:
            strcat(text, " $");
            break;
        default:
            strcat(text, " nao identificado");  // this token sholdnt appear in syntax analysis
            break;
    }
}