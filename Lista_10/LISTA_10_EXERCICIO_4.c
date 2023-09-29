#include "LISTA_10_EXERCICIO_4.h"

bool errorFlag = false;

int main() {
    char reads[SIGMA] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                         'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                         'u', 'v', 'w', 'x', 'y', 'z', '+', '*', '(', ')', '$'};
    int edges[][SIGMA] = {
        //   0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  +  *  (  )  $
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 3, 4, 5, 6},  // state 1
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 2 +
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 3 *
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 4 (
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 5 )
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 6 $
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0},  // state 7 id
    };

    int finalStates[] = {2, 3, 4, 5, 6, 7};

    bool textBefore = false;
    char input[MAX_INPUT];
    bool firstLine = true;
    // char erroLexico[15] = "ERRO LEXICO:  ";
    bool flagLexico = false;
    while (fgets(input, MAX_INPUT, stdin) != NULL) {
        int currentState = 1;         // initial state
        int index = 0;                // index of the char in the input
        int backupIndex = 0;          // index to handle non terminal states
        bool acceptedAsFinal = true;  // if the current state is a final state
        int end = -1;                 // end state

        void *cadeia;
        if (firstLine) {
            cadeia = createList();
            firstLine = false;
        } else {
            if (!flagLexico) {
                processSyntax(cadeia, &textBefore);
            }
            flagLexico = false;
            freeList(cadeia);
            cadeia = createList();
        }

        while (input[index] != '\0') {
            int currentCharIndex = getChar(reads, input[index]);  // gets the index of the char in the array

            // special block only to handle cases when the char read is not in the alphabet
            if (currentCharIndex == -1) {
                if (end == -1) {
                    if (index == 0) {
                        if (input[index] == 10 || input[index] == 32) {
                            resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                            continue;
                        }
                        // erroLexico[14] = input[index-1];
                        // printResult(erroLexico, &textBefore);
                        resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                        while (input[index] != '\n' && input[index] != '\0') index++;
                        flagLexico = true;
                        continue;
                    }

                    resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
                    if (input[index - 1] == 10 || input[index - 1] == 32) continue;
                    // erroLexico[14] = input[index-1];
                    // printResult(erroLexico, &textBefore);
                    while (input[index] != '\n' && input[index] != '\0') index++;
                    flagLexico = true;
                    continue;
                }

                if (end != currentState) {  // current char isnt on alphabet and the current state is not a final state
                    index = backupIndex;
                    backupIndex = index;
                }

                if (end != -1) {  // if the end state is not -1, token is printed because at some point it went to a final state
                    insertNode(cadeia, end);
                }

                // update variables to start again
                resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                if (input[index - 1] == 10 || input[index - 1] == 32) continue;  // skiping spaces and new lines
                // erroLexico[14] = input[index-1];
                // printResult(erroLexico, &textBefore);
                while (input[index] != '\n' && input[index] != '\0') index++;
                flagLexico = true;
                continue;
            }

            // if the char is in the alphabet, the next state is calculated
            int nextState = edges[currentState - 1][currentCharIndex];

            // if the transition is not valid
            if (nextState == 0) {
                if (end == -1) {  // the transition doesnt exist and no state in the token is final
                    // erroLexico[14] = input[index-1];
                    // printResult(erroLexico, &textBefore);
                    resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
                    while (input[index] != '\n' && input[index] != '\0') index++;
                    flagLexico = true;
                    continue;
                }

                if (end != -1) {  // the transition doesnt exist and there is a final state, end of token
                    insertNode(cadeia, end);
                    backupIndex = index;
                }

                if (currentState != end) {  // transition invalid, current state isnt final, need to go back to the last final state
                    index = backupIndex - 1;
                    backupIndex = index;
                }
                end = -1;
                currentState = 1;
                continue;
            }

            // the transition is valid
            currentState = nextState;                              // updates the current state
            acceptedAsFinal = isFinal(finalStates, currentState);  // checks if the current state is a final state

            // if the current state is a final state, the end state is updated
            if (acceptedAsFinal) {
                end = currentState;
            }
            index++;

            // getting to a final state after leaving a intermediate non final state wont update the backupIndex
            // the intention is to save the index of what was the final state before going in the non final one
            if (acceptedAsFinal) {
                backupIndex = index;
            }
        }

        // Check classification for the last token
        if (end == currentState) {
            backupIndex = index;
            insertNode(cadeia, end);

        } else {  // this is the last token of the line, and its and error
            if (input[backupIndex] == 10 || input[backupIndex] == 32 || input[backupIndex] == 0) continue;
            // erroLexico[14] = input[backupIndex];
            // printResult(erroLexico, &textBefore);
            resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
            while (input[index] != '\n' && input[index] != '\0') index++;
            flagLexico = true;
        }
        if (!flagLexico) {
            processSyntax(cadeia, &textBefore);
        }
        flagLexico = false;
        freeList(cadeia);
    }
    return 0;
}

int getChar(char *reads, char input) {
    for (int i = 0; i < SIGMA; i++) {
        if (reads[i] == input) {
            return i;
        }
    }
    return -1;  // error
}

bool isFinal(int *finals, int current) {
    for (int i = 0; i < QNTD_FINAL; i++) {
        if (finals[i] == current) {
            return true;
        }
    }
    return false;
}

void resetVariables(int *index, int indexToSet, int *backupIndex, int *end, int *currentState) {
    *index = indexToSet;
    *backupIndex = *index;
    *end = -1;
    *currentState = 1;
}

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

void S(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case L_PAREN:
            E(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, EOL, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void E(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case L_PAREN:
            T(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            E_Prime(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void E_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case PLUS:
            eatToken(cadeia, PLUS, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            T(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            E_Prime(cadeia, tokenGlobal, textBefore);

            break;

        case R_PAREN:
        case EOL:
            // so tira E'

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " +, ), $");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void T(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
        case L_PAREN:
            F(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            T_Prime(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void T_Prime(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case PLUS:
        case R_PAREN:
        case EOL:
            // so remove T'

            break;

        case TIMES:
            eatToken(cadeia, TIMES, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            F(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            T_Prime(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " +, *, ), $");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void F(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case ID:
            eatToken(cadeia, ID, tokenGlobal, textBefore);

            break;

        case L_PAREN:
            eatToken(cadeia, L_PAREN, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore, false);
            if (errorFlag) return;

            E(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            eatToken(cadeia, R_PAREN, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, " id, (");
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
        case EOL:
            strcat(text, " $");
            break;
        case ID:
            strcat(text, " id");
            break;
        default:
            break;
    }
}