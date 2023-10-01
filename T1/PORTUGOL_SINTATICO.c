#include "PORTUGOL_SINTATICO.h"

bool errorFlag = false;

void processSyntax(void *cadeia, bool *textBefore) {
    int tokenGlobal = getNode(cadeia);
    if (tokenGlobal == -1) {
        printResult("ERRO LISTA VAZIA", textBefore);
        exit(0);
    }
    errorFlag = false;
    // S(cadeia, &tokenGlobal, textBefore);  // S is the initial symbol

    if (!errorFlag && getNode(cadeia) == -1) {
        printResult("CADEIA ACEITA", textBefore);
    }
}

void eatToken(void *cadeia, int tokenAnalisado, int *tokenGlobal, bool *textBefore) {
    if (tokenAnalisado == *tokenGlobal) {  // means that the token was accepted and can be removed from the list
        removeNode(cadeia);
        *tokenGlobal = getNode(cadeia);
    } else {
        char *text = defineErro(*tokenGlobal, tokenAnalisado);
        printResult(text, textBefore);
        free(text);
        errorFlag = true;
    }
}

// void S(void *cadeia, int *tokenGlobal, bool *textBefore) {
//     switch (*tokenGlobal) {
//         case ID:
//         case L_PAREN:
//             E(cadeia, tokenGlobal, textBefore);
//             if (errorFlag) return;

//             eatToken(cadeia, EOL, tokenGlobal, textBefore);

//             break;

//         default:
//             if (!errorFlag) {
//                 char *text = defineErro(*tokenGlobal, -1);
//                 strcat(text, " id, (");
//                 printResult(text, textBefore);
//                 free(text);
//                 errorFlag = true;
//             }
//             break;
//     }
// }

// void E(void *cadeia, int *tokenGlobal, bool *textBefore) {
//     switch (*tokenGlobal) {
//         case ID:
//         case L_PAREN:
//             T(cadeia, tokenGlobal, textBefore);
//             if (errorFlag) return;

//             E_Prime(cadeia, tokenGlobal, textBefore);

//             break;

//         default:
//             if (!errorFlag) {
//                 char *text = defineErro(*tokenGlobal, -1);
//                 strcat(text, " id, (");
//                 printResult(text, textBefore);
//                 free(text);
//                 errorFlag = true;
//             }
//             break;
//     }
// }

// void E_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
//     switch (*tokenGlobal) {
//         case PLUS:
//             eatToken(cadeia, PLUS, tokenGlobal, textBefore);
//             incompleteString(cadeia, tokenGlobal, textBefore, false);
//             if (errorFlag) return;

//             T(cadeia, tokenGlobal, textBefore);
//             if (errorFlag) return;

//             E_Prime(cadeia, tokenGlobal, textBefore);

//             break;

//         case R_PAREN:
//         case EOL:
//             // so tira E'

//             break;

//         default:
//             if (!errorFlag) {
//                 char *text = defineErro(*tokenGlobal, -1);
//                 strcat(text, " +, ), $");
//                 printResult(text, textBefore);
//                 free(text);
//                 errorFlag = true;
//             }
//             break;
//     }
// }

// void T(void *cadeia, int *tokenGlobal, bool *textBefore) {
//     switch (*tokenGlobal) {
//         case ID:
//         case L_PAREN:
//             F(cadeia, tokenGlobal, textBefore);
//             if (errorFlag) return;

//             T_Prime(cadeia, tokenGlobal, textBefore);

//             break;

//         default:
//             if (!errorFlag) {
//                 char *text = defineErro(*tokenGlobal, -1);
//                 strcat(text, " id, (");
//                 printResult(text, textBefore);
//                 free(text);
//                 errorFlag = true;
//             }
//             break;
//     }
// }

// void T_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
//     switch (*tokenGlobal) {
//         case PLUS:
//         case R_PAREN:
//         case EOL:
//             // so remove T'

//             break;

//         case TIMES:
//             eatToken(cadeia, TIMES, tokenGlobal, textBefore);
//             incompleteString(cadeia, tokenGlobal, textBefore, false);
//             if (errorFlag) return;

//             F(cadeia, tokenGlobal, textBefore);
//             if (errorFlag) return;

//             T_Prime(cadeia, tokenGlobal, textBefore);

//             break;

//         default:
//             if (!errorFlag) {
//                 char *text = defineErro(*tokenGlobal, -1);
//                 strcat(text, " +, *, ), $");
//                 printResult(text, textBefore);
//                 free(text);
//                 errorFlag = true;
//             }
//             break;
//     }
// }

// void F(void *cadeia, int *tokenGlobal, bool *textBefore) {
//     switch (*tokenGlobal) {
//         case ID:
//             eatToken(cadeia, ID, tokenGlobal, textBefore);

//             break;

//         case L_PAREN:
//             eatToken(cadeia, L_PAREN, tokenGlobal, textBefore);
//             incompleteString(cadeia, tokenGlobal, textBefore, false);
//             if (errorFlag) return;

//             E(cadeia, tokenGlobal, textBefore);
//             if (errorFlag) return;

//             eatToken(cadeia, R_PAREN, tokenGlobal, textBefore);

//             break;

//         default:
//             if (!errorFlag) {
//                 char *text = defineErro(*tokenGlobal, -1);
//                 strcat(text, " id, (");
//                 printResult(text, textBefore);
//                 free(text);
//                 errorFlag = true;
//             }
//             break;
//     }
// }

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

void switchTokens(char *text, int token) {
    switch (token) {
        case -1:
            // strcat(text, "");
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
            if (token != -1 && token != 1 && token != 167 && token != 169)
                strcat(text, " identificador");
            else 
                strcat(text, " nao identificado");
            break;
    }
}