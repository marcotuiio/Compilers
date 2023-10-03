#include "PORTUGOL_SINTATICO.h"

bool errorFlag = false;

void processSyntax(void *cadeia, bool *textBefore) {
    int tokenGlobal = getNode(cadeia);
    if (tokenGlobal == -1) {
        printResult("ERRO LISTA VAZIA", textBefore);
        exit(0);
    }
    defineID(&tokenGlobal);
    errorFlag = false;
    Start(cadeia, &tokenGlobal, textBefore);  // S is the initial symbol

    if (!errorFlag && getNode(cadeia) == -1) {
        printResult("CADEIA ACEITA", textBefore);
    }
}

void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore) {
    if (tokenAnalisado == *tokenGlobal) {  // means that the token was accepted and can be removed from the list
        removeNode(cadeia);
        *tokenGlobal = getNode(cadeia);
        defineID(tokenGlobal);
    } else {
        char *text = defineErro(*tokenGlobal, tokenAnalisado);
        printResult(text, textBefore);
        free(text);
        errorFlag = true;
    }
}

void Start(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case ABRE_PARENTESES:
        case NUM_INT:
        case NUM_REAL:
        case MAIS:
        case MENOS:
        case NAO:
        case VERDADEIRO:
        case FALSO:
        case STRING:
            E(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, EOF_TOKEN, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (, numero inteiro, numero real, +, -, nao, verdadeiro, falso, string");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void Prog(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ALGORITMO:
            eatToken(cadeia, ALGORITMO, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, ID, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            BV(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            PF(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            BC(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, FIM, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " algoritmo");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void PF(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case PROCEDIMENTO:
            DProc(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            PF(cadeia, tokenGlobal, textBefore);
            
            break;

        case FUNCAO:
            DF(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            PF(cadeia, tokenGlobal, textBefore);
            
            break;
        
        case INICIO:
            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " procedimento, funcao, inicio");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DProc(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case PROCEDIMENTO:
            eatToken(cadeia, PROCEDIMENTO, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, ID, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            Param(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            DParam(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            BV(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            BC(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " procedimento");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DF(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case FUNCAO:
            eatToken(cadeia, FUNCAO, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, ID, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, DOIS_PONTOS, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            TB(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            DParam(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            BV(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            BC(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " funcao");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void Param(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
            break;
        
        case ABRE_PARENTESES:
            eatToken(cadeia, ABRE_PARENTESES, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            DI(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, FECHA_PARENTESES, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " ;, abre parenteses");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DParam(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case TIPO:
        case INTEIRO:
        case REAL:
        case LOGICO:
            DS(cadeia, tokenGlobal, textBefore);

            break;

        case PROCEDIMENTO:
        case FUNCAO:
        case VARIAVEIS:
        case INICIO:
            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " identficador, tipo, inteiro, real, logico, procedimento, funcao, variaveis, inicio");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void BV(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case PROCEDIMENTO:
        case FUNCAO:
        case INICIO:
            break;
        
        case VARIAVEIS:
            eatToken(cadeia, VARIAVEIS, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            DS(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " procedimento, funcao, inicio, variaveis");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DS(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case INTEIRO:
        case REAL:
        case LOGICO:
            DV(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            DS_Prime(cadeia, tokenGlobal, textBefore);

            break;

        case TIPO:
            DT(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            DS_Prime(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " identificador, inteiro, real, logico, tipo");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DS_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case TIPO:
        case INTEIRO:
        case REAL:
        case LOGICO:
            DS(cadeia, tokenGlobal, textBefore);

            break;

        case PROCEDIMENTO:
        case FUNCAO:
        case VARIAVEIS:
        case INICIO:
            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " identificador, tipo, inteiro, real, logico, procedimento, funcao, variaveis, inicio");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DT(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case TIPO:
            eatToken(cadeia, TIPO, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, ID, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, IGUAL, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            VM(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, ABRE_COLCHETE, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            Dimen(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, FECHA_COLCHETE, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            TB(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " tipo");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DV(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case INTEIRO:
        case REAL:
        case LOGICO:
            TB(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, DOIS_PONTOS, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            DI(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);
            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " identificador, inteiro, real, logico");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DI(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            DI_Prime(cadeia, tokenGlobal, textBefore);
            
            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " identificador");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void DI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case PONTO_VIRGULA:
        case FECHA_PARENTESES:    
            break;
        
        case VIRGULA:
            eatToken(cadeia, VIRGULA, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            DI(cadeia, tokenGlobal, textBefore);
            
            break; 
        
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " ponto virgula, fecha parenteses, virgula");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void VM(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case VETOR:
            eatToken(cadeia, VETOR, tokenGlobal, textBefore);

            break;

        case MATRIZ:
            eatToken(cadeia, MATRIZ, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " vetor, matriz");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void Dimen(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case FECHA_COLCHETE:
            break;

        case NUM_INT:
            eatToken(cadeia, NUM_INT, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            eatToken(cadeia, DOIS_PONTOS, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, true);
            if (errorFlag) return;

            Dimen_Prime(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " fecha colchete, numero inteiro");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void Dimen_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case VIRGULA:
            eatToken(cadeia, VIRGULA, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            Dimen(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " virgula");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void TB(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore);
            break;
        
        case INTEIRO:
            eatToken(cadeia, INTEIRO, tokenGlobal, textBefore);
            break;

        case REAL:
            eatToken(cadeia, REAL, tokenGlobal, textBefore);
            break;

        case LOGICO:
            eatToken(cadeia, LOGICO, tokenGlobal, textBefore);
            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " identificador, inteiro, real, logico");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void BC(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case INICIO:
            eatToken(cadeia, INICIO, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            LC(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, FIM, tokenGlobal, textBefore);
            
            break;
        
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " inicio");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void LC(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            C(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, PONTO_VIRGULA, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, true);

            LC_Prime(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " identificador, se, enquanto, para, repita, leia, imprima");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void LC_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            LC(cadeia, tokenGlobal, textBefore);
            break;

        case FIM:
        case SENAO:
        case ATE:
            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void C(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void C_Prime1(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void C_Prime2(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void C_Prime3(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void E(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void E_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void ES(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void ES_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void T(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void T_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void F(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void V(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void V_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void EI(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void EI_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");  // nao esquecer de mudar
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void printResult(char *result, bool *textBefore) {
    if (!result) return;
    if (*textBefore) printf("\n");
    printf("%s", result);
    *textBefore = true;
}

char *defineErro(int tokenGlobal, int tokenAnalisado) {
    char *text = calloc(200, sizeof(char));
    strcat(text, "ERRO SINTATICO EM:");
    switchTokens(text, tokenGlobal);
    strcat(text, " ESPERADO:");
    if (tokenAnalisado != -1) {
        switchTokens(text, tokenAnalisado);
    }
    return text;
}

void incompleteString(void *cadeia, int *tokenGlobal, bool *textBefore, bool couldBeOver) {
    if (getNode(cadeia) == -1 && couldBeOver) {
        printResult("ERRO SINTATICO: CADEIA INCOMPLETA", textBefore);
        errorFlag = true;
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
            *tokenGlobal == SE || *tokenGlobal == SENAO || *tokenGlobal == ENTAO || *tokenGlobal == ENQUANTO ||
            *tokenGlobal == DE || *tokenGlobal == DIV) return;

        if (*tokenGlobal == OU || *tokenGlobal == NAO || *tokenGlobal == TIPO || *tokenGlobal == LEIA ||
            *tokenGlobal == LOGICO || *tokenGlobal == MATRIZ || *tokenGlobal == CARACTERE || *tokenGlobal == PARA ||
            *tokenGlobal == PASSO || *tokenGlobal == PROCEDIMENTO) return;

        *tokenGlobal = ID;  // se passou por todas as palavras e tokens resevados, entao eh um identificador
    }
}

void switchTokens(char *text, int token) {
    switch (token) {
        case -1:
            // strcat(text, "");
            break;
        case ID:
            strcat(text, " identificador");
            break;
        case NUM_INT:
            strcat(text, " numero inteiro");
            break;
        case NUM_REAL:
            strcat(text, " numero real");
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
            strcat(text, " comentario de linha");
            break;
        case STRING:
            strcat(text, " string");
            break;
        case COMENT_BLOCO:
            strcat(text, " comentario de bloco");
            break;
        case EOF_TOKEN:
            strcat(text, " fim de arquivo");
            break;
        default:
            strcat(text, " nao identificado");
            break;
    }
}