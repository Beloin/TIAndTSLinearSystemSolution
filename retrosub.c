//
// Created by beloin on 10/09/2022.
//

#include "retrosub.h"
#include "malloc.h"
#include "primitive-matrix/matrix.h"
#include "math.h"

#define EPSILON 0.0001


int RetroSubstitution(Matrix *mx, Matrix *output) {
    int m = mx->columns - 1; // Augmented Matrix
    int n = mx->rows;

    float Xs[m];
    for (int i = 0; i < m; ++i) {
        Xs[i] = 0;
    }

    int type = 0;

    for (int i = n - 1; i != 0; --i) {
        float sum = 0;
        float bi = *At(mx, i, m);
        float aii = *At(mx, i, i);

        for (int j = i + 1; j < m; ++j) {
            float aij = *At(mx, i, j);
            float xj = Xs[j];
            sum += aij * xj;
        }

        if (aii == 0) {
            if (fabsf(bi - sum) < EPSILON) {
                type = 1;
                Xs[i] = 0;
            } else {
                output = NULL;
                return 2;
            }
        } else {
            Xs[i] = (bi - sum) / aii;
        }
    }

    *output = *CreateMatrix(Xs, n, 1);
    return type;
}

int PrimitiveRetroSubstitution(double **mx, double **output, int n) {
    double Xs[n-1];
    for (int i = 0; i < n-1; ++i) {
        Xs[i] = 0;
    }

    int type = 0;
    for (int i = n-1; i != -1; --i) {
        double sum = 0;
        double bi = mx[i][n];
        double aii = mx[i][i];

        for (int j = i + 1; j < n; ++j) {
            double aij = mx[i][j];
            double xj = Xs[j];
            sum += aij * xj;
        }

        if (aii == 0) {
            if (fabs(bi - sum) < EPSILON) {
                type = 1;
                Xs[i] = 0;
            } else {
                output = NULL;
                return 2;
            }
        } else {
            Xs[i] = (bi - sum) / aii;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("TEST: %f\n", Xs[i]);
        output[i][0] = Xs[i];
    }


    return type;
}