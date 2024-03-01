#include "graphs_manager.h"

char axis[Y_AXIS_SIZE][X_AXIS_SIZE + 1] = {0};

void setAxis(float lowV, float highV, float lowH, float highH) {
    for (int i = 0; i < Y_AXIS_SIZE; i++) {
        for (int j = 0; j < X_AXIS_SIZE + 1; j++) {
            axis[i][j] = ' ';
        }
    }
    int indiceXAxis = -1, indiceYAxis = 0;

    float xStep = (highH - lowH) / (float)(X_AXIS_SIZE); 
    float yStep = (highV - lowV) / (float)(Y_AXIS_SIZE);

    float acum = lowH;
    while (acum < 0.0) {
        acum += xStep;
        indiceYAxis++;
    }
    acum = highV;
    while (acum > 0.0) {
        acum -= yStep;
        indiceXAxis++;
    }
    // printf("X: %d Y: %d\n", indiceXAxis, indiceYAxis);
    if (indiceXAxis >= Y_AXIS_SIZE) indiceXAxis = Y_AXIS_SIZE - 1;
    if (indiceXAxis < 0) indiceXAxis = 0;   
    if (indiceYAxis > X_AXIS_SIZE) indiceYAxis = X_AXIS_SIZE;
    if (indiceYAxis < 0) indiceYAxis = 0;
    
    int aux = 0;
    if (lowV <= 0.0 && highV >= 0.0) {
        for (int i = 0; i < X_AXIS_SIZE + 1; i++) {
            if (axis[indiceXAxis][i] == ' ')
                axis[indiceXAxis][i] = '-';
        }
        aux = 1;
    }
    if (lowH <= 0.0 && highH >= 0.0) {
        for (int i = 0; i < Y_AXIS_SIZE; i++) {
            if (axis[i][indiceYAxis] == ' ')
                axis[i][indiceYAxis] = '|';
        }
        aux = 2;
    }
    if (aux == 2) {
        if (axis[indiceXAxis][indiceYAxis] != '*')
            axis[indiceXAxis][indiceYAxis] = '+';
    } else {
        if (axis[indiceXAxis][indiceYAxis] != '*')
            axis[indiceXAxis][indiceYAxis] = ' ';
    }
}

void drawAxis(bool hasAxis) {
    printf("\n");
    for (int i = 0; i < Y_AXIS_SIZE; i++) {
        for (int j = 0; j < X_AXIS_SIZE + 1; j++) {
            if (!hasAxis && (axis[i][j] == '-' || axis[i][j] == '|' || axis[i][j] == '+'))
                printf(" ");
            else
                printf("%c", axis[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void clearAxis(float lowV, float highV, float lowH, float highH) {
    for (int i = 0; i < Y_AXIS_SIZE; i++) {
        for (int j = 0; j < X_AXIS_SIZE + 1; j++) {
            axis[i][j] = ' ';
        }
    }
    setAxis(lowV, highV, lowH, highH);
}

void insertPoint(int column, float xValue, float yValue, float h_view_lo, float h_view_hi, float v_view_lo, float v_view_hi) {
    if (xValue < h_view_lo || xValue > h_view_hi || yValue < v_view_lo || yValue > v_view_hi) {
        // printf("Point (%.2f, %.2f) is out of view\n", xValue, yValue);
        return;
    }

    float yStep = (v_view_hi - v_view_lo) / (float)(Y_AXIS_SIZE);

    int line = (Y_AXIS_SIZE - 1) - (int)((yValue - v_view_lo) / yStep);
    if (line < 0) line = 0;
    if (line >= Y_AXIS_SIZE) line = Y_AXIS_SIZE - 1;
    if (column < 0) column = 0;
    if (column >= X_AXIS_SIZE + 1) column = X_AXIS_SIZE;
    // printf("%d %d (%.6f)(%.6f)\n", line, column, xValue, yValue);
    axis[line][column] = '*';
}