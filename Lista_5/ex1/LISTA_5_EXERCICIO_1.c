#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getChar(char *reads, char input);
bool isFinal(int *finals, int current);

#define SIGMA 38
#define QNTD_FINAL 5

int main() {
    char reads[SIGMA] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                         'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                         'u', 'v', 'w', 'x', 'y', 'z', '+', '-'};
    int edges[][SIGMA] = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4},  // state 1
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},  // state 2
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 4
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 5
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7},  // state 6
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 7
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // state 8
    };

    int finalStates[] = {2, 3, 4, 5, 8};
    bool textBefore = false;
    char input[200];
    while (fgets(input, 200, stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;  // removes the \n from the input

        int currentState = 1;
        int index = 0;
        bool accepted = true;
        int end = -1;

        while (input[index] != '\0') {
            int currentCharIndex = getChar(reads, input[index]);  // gets the index of the char in the array

            if (currentCharIndex == -1) {  // if the char is not in the array, ERROR is printed
                if (end != -1) {
                    textBefore = true;
                }
                end = -1;
                currentState = 1;
                index++;
                printf("\nERROR");
                continue;  // goes to the next iteration
            }

            currentState = edges[currentState - 1][currentCharIndex];  // gets the next state, given a current state and a char read
            accepted = isFinal(finalStates, currentState);             // checks if the current state is a final state
            index++;

            if (accepted) {  // if the current state is a final state, the end state is updated
                end = currentState;
                if (textBefore) {
                    printf("\n");
                    textBefore = false;
                }
                printf("%c", input[index - 1]);

            } else {  // if the current state is not a final state, the end state is printed and the current state is updated so we can start again
                currentState = 1;
                index--;          // the index is decremented so we can read the char again
                if (end != -1) {  // if the end state is not -1, it is printed
                    textBefore = true;
                }
                end = -1;  // the end state is updated to start again
            }
            if (input[index] == '\n') {
                input[strcspn(input, "\n")] = 0;
            }
        }
        if (end != -1) {
            textBefore = true;
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
