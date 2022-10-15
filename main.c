//
// Created by beloin on 10/09/2022.
//

#include <stdio.h>
#include "primitive-matrix/matrix.h"
#include "retrosub.h"
#include "gauss/gauss-method.h"

double **createMatrix() {
    int n = 3;
    double **matrix;
    matrix = CreatePrimitiveMatrix(n, n + 1);

    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[0][2] = -1;
    matrix[0][3] = 4;

    matrix[1][0] = 2;
    matrix[1][1] = 1;
    matrix[1][2] = 1;
    matrix[1][3] = 9;

    matrix[2][0] = -1;
    matrix[2][1] = 1;
    matrix[2][2] = 2;
    matrix[2][3] = 2;

    return matrix;
}

int main() {
    int n, type;
    n = 3;
    double **matrix = createMatrix();
//    printf("Select Vars Quantity: ");
//    scanf("%d", &n);
//    matrix = CreatePrimitiveMatrix(n, n + 1);
//    if (matrix == NULL) {
//        printf("Problem with Memory");
//        return 1;
//    }

//    ReadPrimitiveMatrix(matrix, n, n + 1);
    ShowPrimitiveMatrix(matrix, n, n + 1);

    PrimitiveGauss(matrix, n);
    ShowPrimitiveMatrix(matrix, n, n + 1);

    double **output;
    output = CreatePrimitiveMatrix(n - 1, 1);
    PrimitiveRetroSubstitution(matrix, output, n);
    ShowPrimitiveMatrix(output, n, 1);

    return 0;
}