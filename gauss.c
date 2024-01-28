#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_SIZE 3

float matrix[MATRIX_SIZE][MATRIX_SIZE] = {
    {10, 2, 1},
    {1, 5, 1},
    {2, 3, 10}};

void swap(float *a, float *b) {
    float aux = *a;
    *a = *b;
    *b = aux;
}

void printMatrix(float **m, int line, int column) {
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

int main() {
    float det = gaussDeterminant(matrix);
    printf("Determinant: %.2f\n", det);
    return 0;
}