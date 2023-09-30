#include "PORTUGOL_SINTATICO.h"

bool errorFlag = false;

void processSyntax(void *cadeia, bool *textBefore) {
    int tokenGlobal = getNode(cadeia);
    if (tokenGlobal == -1) {
        printResult("ERRO LISTA VAZIA", textBefore);
        exit(0);
    }
    errorFlag = false;
    S(cadeia, &tokenGlobal, textBefore);  // S is the initial symbol

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
        case PLUS:
            strcat(text, " +");
            break;
        case TIMES:
            strcat(text, " *");
            break;
        case L_PAREN:
            strcat(text, " (");
            break;
        case R_PAREN:
            strcat(text, " )");
            break;
        default:
            break;
    }
}