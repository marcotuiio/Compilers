#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getChar(char *reads, char input);
bool isFinal(int *finals, int current);
void printTokens(char *tokens[], int *finalStates);

#define SIGMA 40
#define QNTD_FINAL 11

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

    int finalStates[] = {2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13};
    char *tokens[] = {"nda", "ID", "IF", "ID", "ERROR", "REAL", "NUM", "REAL", "ERROR", "nda", "COMMENT", "WHITE SPACE", "ERROR"};
    // printTokens(tokens, finalStates);

    char input[100];
    while (fgets(input, 100, stdin) != NULL) {
        int currentState = 1;
        int index = 0;
        bool accepted = true;
        int end = -1;

        while (input[index] != '\0') {
            int currentCharIndex = getChar(reads, input[index]);  // gets the index of the char in the array

            if (currentCharIndex == -1) {  // if the char is not in the array, ERROR is printed
                if (end != -1) {           // if the end state is not -1, it is printed the token
                    printf(" %s\n", tokens[end - 1]);
                }
                end = -1;  // the end state is updated to start again
                currentState = 1;
                index++;
                printf("%c", input[index - 1]);  // prints the char that is not in the array
                printf(" %s\n", tokens[12]);     // prints the ERROR token
                continue;                        // goes to the next iteration
            }
            currentState = edges[currentState - 1][currentCharIndex];  // gets the next state, given a current state and a char read
            accepted = isFinal(finalStates, currentState);             // checks if the current state is a final state
            index++;

            // printf(" |%d| ", currentState);
            if (end == 9 && currentState == 10) {  // special block only to handle comments
                printf("%c", input[index - 1]);
                continue;
            }

            if (accepted) {  // if the current state is a final state, the end state is updated
                end = currentState;
                if (input[index - 1] != 10) {
                    printf("%c", input[index - 1]);
                }

            } else {  // if the current state is not a final state, the end state is printed and the current state is updated so we can start again
                currentState = 1;
                index--;          // the index is decremented so we can read the char again
                if (end != -1) {  // if the end state is not -1, it is printed
                    printf(" %s\n", tokens[end - 1]);
                }
                end = -1;  // the end state is updated to start again
            }

            if (input[index] == '\n' && end != 11) {
                input[strcspn(input, "\n")] = 0;
            }
        }

        // Check classification for the last token
        if (end != -1 && currentState != 1) {
            printf(" %s\n", tokens[end - 1]);
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

void printTokens(char *tokens[], int *finalStates) {
    printf("TOKENS:\n");
    for (int i = 0; i < QNTD_FINAL; i++) {
        printf("%d\t%s\n", finalStates[i], tokens[finalStates[i] - 1]);
    }
    printf("\n");
}
