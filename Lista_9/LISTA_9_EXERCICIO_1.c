#include "LISTA_9_EXERCICIO_1.h"

bool errorFlag = false;

int main() {
    char reads[SIGMA] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'i', 'f', 'e', 'l', 's', 'n', 'd', 't', 'h', 'b',
                         'g', 'p', 'r', '+', '-', '=', ';'};
    int edges[][SIGMA] = {
        // 0  1  2  3  4  5  6  7  8  9  i  f  e  l  s  n  d  t  h  b  g  p  r  +  -  =  ;
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0, 22, 0, 0, 0, 0, 8, 0, 12, 0, 17, 0, 4, 4, 3, 2},  // state 1
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 2 ;
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 3 =
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 4
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 5 num
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 7 if
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0},     // state 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 11 then
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0},    // state 13
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 14
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 15
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 16 begin
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0},    // state 17
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 18
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 19
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 20
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 21 print
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   // state 22
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 23
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 24
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 25 else
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // state 26
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 27 end
    };

    int finalStates[] = {2, 3, 5, 7, 11, 16, 21, 25, 27};

    bool textBefore = false;
    char input[131072];
    bool firstLine = true;
    while (fgets(input, 131072, stdin) != NULL) {
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
            processSyntax(cadeia, &textBefore);
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
                        // printResult("ERRO LEXICO", &textBefore);
                        resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                        continue;
                    }

                    resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
                    if (input[index - 1] == 10 || input[index - 1] == 32) continue;
                    // printResult("ERRO LEXICO", &textBefore);
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
                // printResult("ERRO LEXICO", &textBefore);
                continue;
            }

            // if the char is in the alphabet, the next state is calculated
            int nextState = edges[currentState - 1][currentCharIndex];

            // if the transition is not valid
            if (nextState == 0) {
                if (end == -1) {  // the transition doesnt exist and no state in the token is final
                    // printResult("ERRO LEXICO", &textBefore);
                    resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
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
            // printResult("ERRO LEXICO", &textBefore);
            resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
        }

        processSyntax(cadeia, &textBefore);
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

// -----------> Syntax Analyzer <-----------

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
    if (tokenAnalisado == *tokenGlobal) {  // means that the token was accepted
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
        case IF:
            eatToken(cadeia, IF, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            E(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;
            eatToken(cadeia, THEN, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return; 

            S(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;
            eatToken(cadeia, ELSE, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            S(cadeia, tokenGlobal, textBefore);

            break;

        case BEGIN:
            eatToken(cadeia, BEGIN, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            S(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;
            L(cadeia, tokenGlobal, textBefore);

            break;

        case PRINT:
            eatToken(cadeia, PRINT, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            E(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, "if, begin, print");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void L(void *cadeia, int *tokenGlobal, bool *textBefore) {
    switch (*tokenGlobal) {
        case END:
            eatToken(cadeia, END, tokenGlobal, textBefore);
            if (errorFlag) return;

            break;

        case SEMICOLON:
            eatToken(cadeia, SEMICOLON, tokenGlobal, textBefore);
            incompleteString(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;

            S(cadeia, tokenGlobal, textBefore);
            if (errorFlag) return;
            L(cadeia, tokenGlobal, textBefore);

            break;

        default:
            if (!errorFlag) {
                char *text = defineErro(*tokenGlobal, -1);
                strcat(text, "end, ;");
                printResult(text, textBefore);
                free(text);
                errorFlag = true;
            }
            break;
    }
}

void E(void *cadeia, int *tokenGlobal, bool *textBefore) {
    eatToken(cadeia, NUM, tokenGlobal, textBefore);
    incompleteString(cadeia, tokenGlobal, textBefore);
    if (errorFlag) return;

    eatToken(cadeia, EQUAL, tokenGlobal, textBefore);
    incompleteString(cadeia, tokenGlobal, textBefore);
    if (errorFlag) return;

    eatToken(cadeia, NUM, tokenGlobal, textBefore);
    if (errorFlag) return;
}

void printResult(char *result, bool *textBefore) {
    if (!result) return;
    if (*textBefore) printf("\n");
    printf("%s", result);
    *textBefore = true;
}

char *defineErro(int tokenGlobal, int tokenAnalisado) {
    if (tokenGlobal == -1) return NULL;
    char *text = calloc(200, sizeof(char));
    strcat(text, "ERRO SINTATICO EM: ");
    switchTokens(text, tokenGlobal);
    strcat(text, " ESPERADO: ");
    if (tokenAnalisado != -1) {
        switchTokens(text, tokenAnalisado);
    }
    return text;
}

void incompleteString(void *cadeia, int *tokenGlobal, bool *textBefore) {
    if (getNode(cadeia) == -1) {
        printResult("ERRO SINTATICO: CADEIA INCOMPLETA", textBefore);
        errorFlag = true;
    }
}

void switchTokens(char *text, int token) {
    switch (token) {
        case SEMICOLON:
            strcat(text, ";");
            break;
        case EQUAL:
            strcat(text, "=");
            break;
        case NUM:
            strcat(text, "num");
            break;
        case IF:
            strcat(text, "if");
            break;
        case THEN:
            strcat(text, "then");
            break;
        case BEGIN:
            strcat(text, "begin");
            break;
        case PRINT:
            strcat(text, "print");
            break;
        case ELSE:
            strcat(text, "else");
            break;
        case END:
            strcat(text, "end");
            break;
        default:
            break;
    }
}