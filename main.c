//
// Created by beloin on 10/09/2022.
//

#include <stdio.h>
#include "primitive-matrix/matrix.h"

int main() {
    int n, type;
    double **matrix;
    printf("Select Vars Quantity: ");
    scanf("%d", &n);
    matrix = CreatePrimitiveMatrix(n, n + 1);

    if (matrix == NULL) {
        printf("Problem with Memory");
        return 1;
    }

    ReadPrimitiveMatrix(matrix, n, n + 1);
    ShowPrimitiveMatrix(matrix, n, n + 1);

    return 0;
}