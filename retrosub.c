//
// Created by beloin on 10/09/2022.
//

#include "retrosub.h"
#include "malloc.h"

int retroSubstitution(Matrix *mx, Matrix *output) {
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

        for (int j = i+1; j < m; ++j) {
            float aij = *At(mx, i, j);
            float xj = Xs[j];
            sum += aij * xj;
        }

        if (aii == 0) {
            if (bi != sum) {
                output = NULL;
                return 2;
            } else {
                type = 1;
                Xs[i] = 0;
            }
        } else {
            Xs[i] = (bi - sum) / aii;
        }
    }

    *output = *CreateMatrix(Xs, n, 1);
    return type;
}
