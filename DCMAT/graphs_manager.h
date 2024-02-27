// Author: Marco Tulio Alves de Barros

#ifndef _GRAPHS_MANAGER_H_
#define _GRAPHS_MANAGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define X_AXIS_SIZE 80
#define Y_AXIS_SIZE 25

void drawAxis(bool hasAxis, float lowV, float highV, float lowH, float highH);
void clearAxis();
void insertPoint(int column, float xValue, float yValue, float h_view_lo, float h_view_hi, float v_view_lo, float v_view_hi);

#endif