#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_SIZE 2

// float detMatrix[MATRIX_SIZE][MATRIX_SIZE] = {
//     {10, 2, 1},
//     {1, 5, 1},
//     {2, 3, 10}};

// float systemMatrix[MATRIX_SIZE][MATRIX_SIZE + 1] = {
//     {10, 2, 1, 7},
//     {1, 5, 1, -8},
//     {2, 3, 10, 6}};

float manySolutionMatrix[MATRIX_SIZE][MATRIX_SIZE + 1] = {
    {1, 1, 8},
    {2, 2, 16}};

float noSolutionMatrix[MATRIX_SIZE][MATRIX_SIZE + 1] = {
    {3, 2, 6},
    {3, 2, 12}};

void swap(float *a, float *b) {
    float aux = *a;
    *a = *b;
    *b = aux;
}

void printMatrix(float m[MATRIX_SIZE][MATRIX_SIZE + 1], int line, int column) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++)
            printf("%.2f ", m[i][j]);
        printf("\n");
    }
}

float gaussDeterminant(float a[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, j1, j2;
    float det = 1;
    float temp[MATRIX_SIZE][MATRIX_SIZE];

    // copy matrix
    for (i = 0; i < MATRIX_SIZE; i++)
        for (j = 0; j < MATRIX_SIZE; j++)
            temp[i][j] = a[i][j];

    // pivoting
    for (j = 0; j < MATRIX_SIZE; j++) {
        if (temp[j][j] == 0) {  // if pivot is zero

            // basically trying to turn it into a upper triangular matrix
            for (i = j + 1; i < MATRIX_SIZE; i++)  // find non-zero element in the same column below and swaps the rows
                if (temp[i][j] != 0)
                    break;

            if (i == MATRIX_SIZE)  // if no non-zero element is found, determinant is zero
                return 0;

            for (j1 = j; j1 < MATRIX_SIZE; j1++)
                swap(&temp[j][j1], &temp[i][j1]);
            det *= -1;  // if row was swapped, multiply determinant by -1
        }

        det *= temp[j][j];

        // subtracting multiples of the pivot row from all the rows below it to create zeros below the diagonal
        for (i = j + 1; i < MATRIX_SIZE; i++) {
            for (j1 = MATRIX_SIZE - 1; j1 >= j; j1--)
                temp[i][j1] -= temp[j][j1] * temp[i][j] / temp[j][j];
        }
    }
    return det;
}

float *gaussLinearSystem(float a[MATRIX_SIZE][MATRIX_SIZE + 1], int line) {
    // triangularization

    for (int i = 0; i < line - 1; i++) {
        for (int j = i + 1; j < line; j++) {
            // pivoting

            if (a[i][i] == 0) {
                for (int k = i + 1; k < line; k++) {
                    if (a[k][i] != 0) {
                        for (int l = i; l < line; l++) {
                            swap(&a[i][l], &a[k][l]);
                        }
                        break;
                    }
                }
            }

            float pivot = a[i][i];
            float m = a[j][i] / pivot;
            for (int k = 0; k < line + 1; k++) {
                a[j][k] = a[j][k] - m * a[i][k];
            }
        }
    }
    // retrosubstitution

    // After Gaussian elimination
    for (int i = 0; i < line; i++) {
        int j;
        for (j = 0; j < line; j++) {
            if (a[i][j] != 0)
                break;
        }
        if (j == line && a[i][line] != 0) {
            printf("The system has no solution.\n");
            return NULL;
        } else if (j == line) {
            printf("The system has infinitely many solutions.\n");
            return NULL;
        }
    }

    float *x = calloc(line, sizeof(float));
    for (int i = line - 1; i >= 0; i--) {
        x[i] = a[i][line];
        for (int j = i + 1; j < line; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    printMatrix(a, line, line + 1);
    return x;
}

int main() {
    // float det = gaussDeterminant(detMatrix);
    // printf("Determinant: %.2f\n", det);
    float *x = gaussLinearSystem(manySolutionMatrix, MATRIX_SIZE);
    if (!x)
        return 0;
    printf("Solution:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }
    return 0;
}
