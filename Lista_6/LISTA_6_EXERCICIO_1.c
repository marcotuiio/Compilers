#include "LISTA_6_EXERCICIO_1.h"

int main() {
    char reads[SIGMA] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'h', 'e', 'r', 's', 'i', 'c', 'a', 't', '+', '-'};
    int edges[][SIGMA] = {
        {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 2, 0, 0, 4, 0, 11, 0, 0, 17, 18},  // state 1
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 7, 0, 0, 0, 0, 0},               // state 2
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0},               // state 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0},               // state 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0},               // state 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0},              // state 9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0},              // state 11
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 13, 0, 0},             // state 12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0},              // state 13
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0},              // state 14
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 15
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 16
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 17
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               // state 18
        {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},    // state 19
        {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0, 0, 0, 0, 0, 0, 21, 21},   // state 20
        {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 21
        {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // state 22
    };

    int finalStates[] = {3, 6, 8, 10, 13, 14, 15, 16, 17, 18, 19, 22};
    char *tokens[] = {"nda", "nda", "ELE", "nda", "nda", "ELA", "nda", "DELE", "nda", "DELA",
                      "nda", "nda", "GATO", "CARRO", "GATOS", "CARROS", "MAIS", "MENOS", "INTEIRO", "nda", "nda", "REAL"};

    bool textBefore = false;
    char input[4096];
    char output[4096];
    int outputIndex = 0;
    int printIndex = 0;
    while (fgets(input, 4096, stdin) != NULL) {
        int currentState = 1;         // initial state
        int index = 0;                // index of the char in the input
        int backupIndex = 0;          // index to handle non terminal states
        bool acceptedAsFinal = true;  // if the current state is a final state
        int end = -1;                 // end state

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
                        printToken(&textBefore, "ERRO");
                        resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                        continue;
                    }

                    resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
                    if (input[index - 1] == 10 || input[index - 1] == 32) continue;
                    printToken(&textBefore, "ERRO");
                    clearOutput(output, strlen(output), &outputIndex);
                    continue;
                }

                if (end != currentState) {  // current char isnt on alphabet and the current state is not a final state
                    index = backupIndex;
                    backupIndex = index;
                }

                if (end != -1) {  // if the end state is not -1, token is printed because at some point it went to a final state
                    printf("%s", tokens[end - 1]);
                    if (end == 22 || end == 19) {  // print numbers
                        printSession(output, printIndex);
                    }
                    textBefore = true;
                }

                // update variables to start again
                clearOutput(output, strlen(output), &outputIndex);
                resetVariables(&index, (index + 1), &backupIndex, &end, &currentState);
                if (input[index - 1] == 10 || input[index - 1] == 32) continue;  // skiping spaces and new lines
                printToken(&textBefore, "ERRO");
                continue;
            }

            // if the char is in the alphabet, the next state is calculated
            int nextState = edges[currentState - 1][currentCharIndex];

            // if the transition is not valid
            if (nextState == 0) {
                if (end == -1) {  // the transition doesnt exist and no state in the token is final
                    printToken(&textBefore, "ERRO");
                    clearOutput(output, strlen(output), &outputIndex);
                    resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
                    continue;
                }

                if (end != -1) {  // the transition doesnt exist and there is a final state, end of token
                    printf("%s", tokens[end - 1]);
                    backupIndex = index;
                }
                if (currentState == end) {  // if the current state is a final state, it means that the token is valid
                    if (end == 22 || end == 19) {
                        printSession(output, printIndex);
                    }
                } else {  // transition invalid, current state isnt final, need to go back to the last final state
                    index = backupIndex - 1;
                    backupIndex = index;
                }
                clearOutput(output, strlen(output), &outputIndex);
                textBefore = true;
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
                printIndex = outputIndex + 1;
            }

            if (input[index] != 10 && input[index] != 32) {  // skiping spaces and new lines
                if (textBefore) {
                    printf("\n");
                    textBefore = false;
                }
                output[outputIndex] = input[index];
                outputIndex++;
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
            printf("%s", tokens[end - 1]);
            if (end == 22 || end == 19) {
                printSession(output, printIndex);
            }
            textBefore = true;

        } else {  // this is the last token of the line, and its and error
            if (input[backupIndex] == 10 || input[backupIndex] == 32 || input[backupIndex] == 0) continue;
            printToken(&textBefore, "ERRO");
            resetVariables(&index, (backupIndex + 1), &backupIndex, &end, &currentState);
        }
        clearOutput(output, strlen(output), &outputIndex);
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

void printToken(bool *textBefore, char *toPrint) {
    if (*textBefore) {
        printf("\n");
    }
    printf("%s", toPrint);
    *textBefore = true;
}

void printSession(char *output, int size) {
    printf(" ");
    for (int i = 0; i < size; i++) {
        printf("%c", output[i]);  // prints the chars that were read
    }
}

void clearOutput(char *output, int size, int *outputIndex) {
    for (int i = 0; i < size; i++) {
        output[i] = '\0';  // clears the output buffer
    }
    *outputIndex = 0;
}

void resetVariables(int *index, int indexToSet, int *backupIndex, int *end, int *currentState) {
    *index = indexToSet;
    *backupIndex = *index;
    *end = -1;
    *currentState = 1;
}