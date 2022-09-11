//
// Created by beloin on 10/09/2022.
//

#include <malloc.h>
#include "Matrix.h"

int getArrayIndexFromRowAndColumn(Matrix* m, int i, int j);

Matrix *CreateMatrix(float *items, int rows, int columns) {
    Matrix *m = malloc(sizeof (Matrix));
    m->mx = items;
    m->columns = columns;
    m->rows = rows;
    return m;
}

float GetItem(Matrix *m, int i, int j) {
    return *At(m, i, j);
}

void SetItem(Matrix *m, int i, int j, float v) {
    *At(m, i, j) = v;
}

float* At(Matrix *m, int i, int j) {
    int index = getArrayIndexFromRowAndColumn(m, i, j);
    return &m->mx[index];
}

int getArrayIndexFromRowAndColumn(Matrix* m, int i, int j) {
    int columns = m->columns;
    int offset = i * columns;
    return offset + j;
}

void PrintMatrix(Matrix *m) {
    printf("{\n");
    for (int i = 0; i < m->rows; ++i) {
        printf("    ");
        for (int j = 0; j < m->columns; ++j) {
            printf("%.2f", GetItem(m, i, j));
            if (j != m->columns-1) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("}");
}
