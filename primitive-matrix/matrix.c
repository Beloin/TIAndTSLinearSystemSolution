//
// Created by beloin on 9/25/22.
//

#include <malloc.h>
#include "matrix.h"

double **CreatePrimitiveMatrix(int i, int j) {
    int k, l;
    double **matrix;
    matrix = malloc(sizeof(double) * i);
    if (matrix == NULL) {
        return NULL;
    }

    for (k = 0; k <= i; ++k) {
        matrix[k] = malloc(sizeof(double) * j);
        if (matrix[k] == NULL) {
            for (l = 0; l < k; ++k) {
                free(matrix[l]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

void ReadPrimitiveMatrix(double **m, int i, int j) {
    int k, l;
    for (k = 0; k < i; ++k) {
        for (l = 0; l < j; ++l) {
            printf("M[%d][%d] = ", k, l);
            scanf("%lf", &m[k][l]);
        }
    }
}

void ShowPrimitiveMatrix(double **m, int i, int j) {
    printf("{\n");
    for (int k = 0; k < i; ++k) {
        printf("    ");
        for (int l = 0; l < j; ++l) {
            printf("%10.3f", m[k][l]);
            if (l != i - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("}");
}
