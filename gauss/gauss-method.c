//
// Created by beloin on 10/9/22.
//

#include "gauss-method.h"

void PrimitiveGauss(double **m, int n) {
    int i, j, k;
    double multiplier, *aux;

    for (i = 0; i < n - 1; ++i) {
        if (m[i][i] == 0) { // Null pivot
            j = i + 1;
            while (j < n && m[j][i] == 0) {
                j++;
            }

            // Change null pivots to another not null row
            if (j < n) {
                aux = m[i];
                m[i] = m[j];
                m[j] = aux;
            }
        }

        if (m[i][i] != 0) {
            for (j = i + 1; j < n; ++j) {
                multiplier = -(m[j][i] / m[i][i]);
                m[j][i] = 0;
                for (k = i + 1; k <= n; k++) {
                    m[j][k] = m[j][k] + (multiplier * m[i][k]);
                }
            }
        }
    }
}

