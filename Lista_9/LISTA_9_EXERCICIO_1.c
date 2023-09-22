#include "LISTA_9_EXERCICIO_1.h"

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
    // char *tokens[] = {"nda", ";", "=", "nda", "num", "nda", "if", "nda", "nda", "nda", "then", "nda", "nda", "nda",
    //                   "nda", "begin", "nda", "nda", "nda", "nda", "print", "nda", "nda", "nda", "else", "nda", "end"};

    // bool textBefore = false;
    char input[4096];
    bool firstLine = true;
    while (fgets(input, 4096, stdin) != NULL) {
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
            printList(cadeia);
            freeList(cadeia);
        }
        
        cadeia = createList();

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
                        // printToken(&textBefore, "ERRO LEXICO");
                        resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                        continue;
                    }

                    resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
                    if (input[index - 1] == 10 || input[index - 1] == 32) continue;
                    // printToken(&textBefore, "ERRO LEXICO");
                    continue;
                }

                if (end != currentState) {  // current char isnt on alphabet and the current state is not a final state
                    index = backupIndex;
                    backupIndex = index;
                }

                if (end != -1) {  // if the end state is not -1, token is printed because at some point it went to a final state
                    insertNode(cadeia, end);
                    // textBefore = true;
                }

                // update variables to start again
                resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                if (input[index - 1] == 10 || input[index - 1] == 32) continue;  // skiping spaces and new lines
                // printToken(&textBefore, "ERRO LEXICO");
                continue;
            }

            // if the char is in the alphabet, the next state is calculated
            int nextState = edges[currentState - 1][currentCharIndex];

            // if the transition is not valid
            if (nextState == 0) {
                if (end == -1) {  // the transition doesnt exist and no state in the token is final
                    // printToken(&textBefore, "ERRO LEXICO");
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

            // if (input[index] != 10 && input[index] != 32) {  // skiping spaces and new lines
            //     if (textBefore) {
            //         printf("\n");
            //         textBefore = false;
            //     }
            // }
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
            // printf("%s", tokens[end - 1]);
            insertNode(cadeia, end);
            // textBefore = true;

        } else {  // this is the last token of the line, and its and error
            if (input[backupIndex] == 10 || input[backupIndex] == 32 || input[backupIndex] == 0) continue;
            // printToken(&textBefore, "ERRO LEXICO");
            resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
        }

        printList(cadeia);
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

// void printToken(bool *textBefore, char *toPrint) {
//     if (*textBefore) {
//         printf("\n");
//     }
//     printf("%s", toPrint);
//     *textBefore = true;
// }

void resetVariables(int *index, int indexToSet, int *backupIndex, int *end, int *currentState) {
    *index = indexToSet;
    *backupIndex = *index;
    *end = -1;
    *currentState = 1;
}

// Syntax Analyzer

void processSyntax(void *cadeia) {
    int token = getNode(cadeia);
    S(token);  // S is the initial symbol
}

void eatToken(int token) {
    // void eatToken(int token, void *cadeia, int *currentToken) {
    if (token == -1) {
        printf("ERRO LISTA VAZIA ?\n");
        exit(0);
    }

    // if (token == *currentToken) {
    //     int currentToken = removeNode(cadeia);
    // }
}

void S(int token) {
    switch (token) {
        case IF:
            eatToken(token);
            E(token);
            eatToken(THEN);
            S(token);
            eatToken(ELSE);
            S(token);
            break;

        case BEGIN:
            eatToken(token);
            S(token);
            L(END);
            break;

        case PRINT:
            eatToken(token);
            E(token);
            break;

        default:
            printErro();
            break;
    }
}

void L(int token) {
    switch(token) {
        case END:
            eatToken(token);
            break;

        case SEMICOLON:
            eatToken(token);
            S(token);
            L(token);
            break;

        default:
            printErro();
            break;
    }
}

void E(int token) {
    eatToken(token);
    eatToken(token);
    eatToken(token);
}