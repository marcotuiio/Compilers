#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getChar(char *reads, char input);
bool isFinal(int *finals, int current);
bool isLetter(char input);
bool isSpecialTransition(char *transitions, char at);

#define SIGMA 40
#define QNTD_FINAL 11
#define QNTD_SPECIAL 1

int main() {
    char reads[SIGMA] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                         'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                         'u', 'v', 'w', 'x', 'y', 'z', '.', '-', 32, 10};
    int edges[][SIGMA] = {
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 9, 12, 0},                            // state 1
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},                             // state 2
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},                             // state 3
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},                             // state 4
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                             // state 5
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                             // state 6
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0},                             // state 7
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                             // state 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},                            // state 9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 11},  // state 10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                             // state 11
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0},                            // state 12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                             // state 13
    };

    char specialTransitions[QNTD_SPECIAL] = {'\n'}; // what is read so a intermediate non final goes to a final state
    int finalStates[QNTD_FINAL] = {2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13};
    char *tokens[] = {"nda", "ID", "IF", "ID", "ERROR", "REAL", "NUM", "REAL", "ERROR", "nda", "COMMENT", "WHITE SPACE", "ERROR"};

    char input[100];
    int limitIndex;
    while (fgets(input, 100, stdin) != NULL) {
        int currentState = 1;         // initial state
        int index = 0;                // index of the char in the input
        int backupIndex = 0;          // index to handle non terminal states
        bool allowPrint = true;       // if the current state is a final state
        bool acceptedAsFinal = true;  // if the current state is a final state
        int end = -1;                 // end state

        while (input[index] != '\0') {
            int currentCharIndex = getChar(reads, input[index]);  // gets the index of the char in the array

            // special block only to handle errors and other symbols not in the array
            if (currentCharIndex == -1) {
                if (end != -1) {  // if the end state is not -1, token is printed
                    printf(" %s\n", tokens[end - 1]);
                }
                // update variables to start again
                end = -1;
                currentState = 1;
                index++;

                if (input[index - 1] == 10) continue;
                printf("%c", input[index - 1]);  // prints the char that is not in the array
                printf(" %s\n", tokens[12]);     // prints the ERROR token
                continue;                        // goes to the next iteration
            }

            int nextState = edges[currentState - 1][currentCharIndex];  // gets the next state, given a current state and a char read

            // if the transition is not valid
            if (nextState == 0) {
                if (currentState == end) {  // in case the latest string read reached a final state its the biggest token possible
                    for (int i = backupIndex; i < limitIndex; i++) {
                        printf("%c", input[i]);  // prints the chars that were read
                    }
                    allowPrint = true;
                } else {
                    index = backupIndex;  // if the current state is not the end state, the index is updated to find the next token
                }

                printf(" %s\n", tokens[end - 1]);
                end = -1;
                currentState = 1;
                continue;
            }

            currentState = nextState;  // updates the current state

            acceptedAsFinal = isFinal(finalStates, currentState);  // checks if the current state is a final state

            // if the current state is a final state, the end state is updated
            if (acceptedAsFinal) {
                end = currentState;
                allowPrint = true;
            } else {
                allowPrint = false;  // if the current isnt a final state, disable print to check biggest token
            }

            if (input[index] != 10 && allowPrint)
                printf("%c", input[index]);
            index++;
            limitIndex = index;

            // getting to a final state after leaving a intermediate non final state wont update the backupIndex
            // the intention is to save the index of what was the final state before going in the non final one
            if (acceptedAsFinal && !isSpecialTransition(specialTransitions, input[index - 1])) {
                backupIndex = index;
            }
            // printf("  <%d %d %d %d %d>  ", currentState, end, backupIndex, limitIndex, index);

            // cleaning buffer
            if (input[index] == '\n' && currentState != 10) {
                input[strcspn(input, "\n")] = 0;
            }
        }

        // Check classification for the last token
        if (end == currentState) {
            for (int i = backupIndex; i < limitIndex; i++) {
                if (input[i] != 10)
                    printf("%c", input[i]);  // prints the chars that were read
            }
            printf(" %s\n", tokens[end - 1]);
        }
    }
    return 0;
}

// Function that returns the index of the char in the array so we can know what symbols was read in the input
int getChar(char *reads, char input) {
    for (int i = 0; i < SIGMA; i++) {
        if (reads[i] == input) {
            // printf("%c - %d \n", input, input);
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

// Function to check if a input can make a intermediate non final state go to a final state
bool isSpecialTransition(char *transitions, char at) {
    for (int i = 0; i < QNTD_SPECIAL; i++) {
        if (transitions[i] == at) {
            return true;
        }
    }
    return false;
}
