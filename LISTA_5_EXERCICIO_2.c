#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getChar(char *reads, char input);
bool isFinal(int *finals, int current);
bool isLetter(char input);
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
        int currentState = 1;  // initial state
        int index = 0;         // index of the char in the input
        bool accepted = true;  // if the current state is a final state
        int end = -1;          // end state

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

            currentState = edges[currentState - 1][currentCharIndex];  // gets the next state, given a current state and a char read
            accepted = isFinal(finalStates, currentState);             // checks if the current state is a final state
            index++;

            // printf(" |%d| ", currentState);

            if (accepted) {  // if the current state is a final state, the end state is updated ans goes to the next iteration
                end = currentState;
                if (input[index - 1] == 10) continue;
                printf("%c", input[index - 1]);

            } else {  // else the current state is not a final state so the end state is updated to print the token

                // special block only to handle comments
                if (currentState == 10 && end == 9) {                             // if the current state is 10 and the end state is 9,
                    printf("%c", input[index - 1]);                               // the char is printed
                    if (!isLetter(input[index]) && isLetter(input[index - 1])) {  // if the next char is not a letter, the comment is finished
                        end = 11;                                                 // and the end state is updated to print token and then start again
                        printf(" %s\n", tokens[end - 1]);
                        end = -1;
                        currentState = 1;
                        continue;
                    }
                    continue;
                }

                if (end != -1) {  // if the end state is not -1, token is printed
                    printf(" %s\n", tokens[end - 1]);
                }

                // update variables to start again
                // the index needs to be decremented because the current char is not a final state but its the start of a new token
                currentState = 1;
                index--;
                end = -1;
            }

            // cleaning buffer
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

bool isLetter(char input) {
    if (input >= 97 && input <= 122) {  // a-z
        return true;
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
