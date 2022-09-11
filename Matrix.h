//
// Created by beloin on 10/09/2022.
//

#ifndef RETROSUBS_MATRIX_H
#define RETROSUBS_MATRIX_H

typedef struct Matrix {
    float *mx;
    int rows, columns;
} Matrix;

Matrix *CreateMatrix(float *items, int rows, int columns);

float GetItem(Matrix *m, int i, int j);
float At(Matrix *m, int i, int j);

#endif //RETROSUBS_MATRIX_H
