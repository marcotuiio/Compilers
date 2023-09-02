#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getChar(char *reads, char input);
bool isFinal(int *finals, int current);
bool isSpecialTransition(int *states, char *transitions, int st, char in);
void printSession(char *output, int size);
void clearOutput(char *output, int size);

#define SIGMA 20
#define QNTD_FINAL 12
#define QNTD_SPECIAL 11

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

    char specialTransitions[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 's'};  // what is read so a intermediate non final goes to a final state
    int specialTransitionStates[] = {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 10};         // after reading special char in index i of specialTransitions goes to state in index i of this array

    int finalStates[] = {3, 6, 8, 10, 13, 14, 15, 16, 17, 18, 19, 22};
    char *tokens[] = {"nda", "nda", "ELE", "nda", "nda", "ELA", "nda", "DELE", "nda", "DELA",
                      "nda", "nda", "GATO", "CARRO", "GATOS", "CARROS", "MAIS", "MENOS", "INTEIRO", "nda", "nda", "REAL"};

    bool textBefore = false;
    char input[200];
    char output[200];
    int outputIndex = 0;
    int printIndex = 0;
    while (fgets(input, 200, stdin) != NULL) {
        int currentState = 1;         // initial state
        int index = 0;                // index of the char in the input
        int backupIndex = 0;          // index to handle non terminal states
        bool acceptedAsFinal = true;  // if the current state is a final state
        int end = -1;                 // end state

        while (input[index] != '\0') {
            int currentCharIndex = getChar(reads, input[index]);  // gets the index of the char in the array
            // printf("(0index: %d)", index);
            // printf("|%d %c %d %d| ", currentState, input[index], backupIndex, edges[currentState - 1][currentCharIndex]);
            // special block only to handle errors and other symbols not in the array
            if (currentCharIndex == -1) {
                if (end == -1) {
                    // printf("pre (%d %d %c) ", index, backupIndex, input[index]);
                    index = backupIndex + 1;
                    backupIndex = index;
                    end = -1;
                    currentState = 1;
                    if (input[index - 1] == 10 || input[index - 1] == 32) continue;
                    if (textBefore) {
                        printf("\n");
                    }
                    clearOutput(output, strlen(output));
                    outputIndex = 0;
                    printf("ERRO");
                    textBefore = true;
                    // printf(" after (%d %d)", index, backupIndex);
                    continue;
                }
                // printf("(1- %d %d %d)\n", index, backupIndex, currentState);
                if (end != currentState) {
                    // printf("<aqui pfv %d %d %c %d>", end, currentState, input[index - 1], backupIndex);
                    index = backupIndex;
                    backupIndex = index;
                }

                if (end != -1) {  // if the end state is not -1, token is printed
                    printf("%s", tokens[end - 1]);
                    if (end == 22 || end == 19) {
                        printSession(output, printIndex);
                    }
                    textBefore = true;
                }

                // update variables to start again
                end = -1;
                currentState = 1;
                clearOutput(output, strlen(output));
                outputIndex = 0;
                index++;
                backupIndex = index;
                // printf("(1.5 %d)\n", index);
                if (input[index - 1] == 10 || input[index - 1] == 32) continue;

                if (textBefore) {
                    printf("\n");
                }
                printf("ERRO");
                textBefore = true;
                // printf("2\n");
                continue;  // goes to the next iteration
            }

            int nextState = edges[currentState - 1][currentCharIndex];  // gets the next state, given a current state and a char read
            // printf("3 index %d\n", index);
            // if the transition is not valid
            if (nextState == 0) {
                if (end == -1) {
                    if (textBefore) {
                        printf("\n");
                    }
                    printf("ERRO");
                    clearOutput(output, strlen(output));
                    outputIndex = 0;
                    index = backupIndex + 1;
                    backupIndex = index;
                    textBefore = true;
                    end = -1;
                    currentState = 1;
                    continue;
                }

                // printf("<%d %d %d>", currentState, end, backupIndex);

                if (end != -1) {
                    printf("%s", tokens[end - 1]);
                    backupIndex = index;
                }
                if (currentState == end) {
                    if (end == 22 || end == 19) {
                        printSession(output, printIndex);
                    }
                } else {
                    // printf("(sla %d %d %d)", currentState, end, index);
                    // printf("<aqui pfv %d %d %c %d>", end, currentState, input[index - 1], backupIndex);
                    index = backupIndex - 1;
                    backupIndex = index;
                }
                clearOutput(output, strlen(output));
                outputIndex = 0;
                textBefore = true;
                end = -1;
                currentState = 1;
                // printf("4\n");
                continue;
            }

            currentState = nextState;                              // updates the current state
            acceptedAsFinal = isFinal(finalStates, currentState);  // checks if the current state is a final state
            // printf("(5 index %d)\n", index);
            // if the current state is a final state, the end state is updated
            if (acceptedAsFinal) {
                end = currentState;
                printIndex = outputIndex + 1;
            }

            if (input[index] != 10 && input[index] != 32) {
                if (textBefore) {
                    printf("\n");
                    textBefore = false;
                }
                output[outputIndex] = input[index];
                outputIndex++;
            }
            // printf("{6 index %d %d}\n", index, backupIndex);
            index++;
            // printf("6 \n");
            // getting to a final state after leaving a intermediate non final state wont update the backupIndex
            // the intention is to save the index of what was the final state before going in the non final one
            if (acceptedAsFinal && !isSpecialTransition(specialTransitionStates, specialTransitions, currentState, input[index - 1])) {
                backupIndex = index;
            } 

            // cleaning buffer
            if (input[index] == '\n') {
                input[strcspn(input, "\n")] = 0;
            }
            // printf("6,5 %d %d\n", index, backupIndex);
        }
        // printf("7 printIndex %d\n", printIndex);
        // Check classification for the last token
        // printf("(%d %d %d)", currentState, backupIndex, index);
        if (end == currentState) {
            backupIndex = index;
            printf("%s", tokens[end - 1]);
            if (end == 22 || end == 19) {
                printSession(output, printIndex);
            }
            clearOutput(output, strlen(output));
            outputIndex = 0;
            textBefore = true;
        
        } else {
            if (textBefore) {
                printf("\n");
            }
            printf("ERRO");
            textBefore = true;
            index = backupIndex + 1;
            backupIndex = index;
        }
    }
    return 0;
}

// Function that returns the index of the char in the array so we can know what symbols was read in the input
int getChar(char *reads, char input) {
    for (int i = 0; i < SIGMA; i++) {
        if (reads[i] == input) {
            return i;
        }
    }
    return -1;  // error
}

// Function that returns the final state if the current state is a final state or the end state if it is not
bool isFinal(int *finals, int current) {
    for (int i = 0; i < QNTD_FINAL; i++) {
        if (finals[i] == current) {
            return true;
        }
    }
    return false;
}

// Function to check if a input in can make a intermediate non final state go to the final state st
bool isSpecialTransition(int *states, char *transitions, int st, char in) {
    for (int i = 0; i < QNTD_SPECIAL; i++) {
        if (transitions[i] == in && states[i] == st) {
            return true;
        }
    }
    return false;
}

void printSession(char *output, int size) {
    printf(" ");
    int i = 0;
    for (int i = 0; i < size; i++) {
        printf("%c", output[i]);  // prints the chars that were read
    }
}

void clearOutput(char *output, int size) {
    for (int i = 0; i < size; i++) {
        output[i] = '\0';  // clears the output buffer
    }
}