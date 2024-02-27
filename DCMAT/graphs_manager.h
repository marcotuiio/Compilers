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

void setAxis(float lowV, float highV, float lowH, float highH);
void drawAxis(bool hasAxis);
void clearAxis(float lowV, float highV, float lowH, float highH);
void insertPoint(int column, float xValue, float yValue, float h_view_lo, float h_view_hi, float v_view_lo, float v_view_hi);

#endif