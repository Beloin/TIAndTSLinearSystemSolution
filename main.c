//
// Created by beloin on 10/09/2022.
//

#include <stdio.h>
#include <malloc.h>
#include "Matrix.h"

int main() {
    float *arr = malloc(sizeof(float) * 9);
    arr[0] = 12.2F;
    arr[1] = 12.2F;
    arr[2] = 7;
    arr[3] = 45;
    arr[4] = 12;
    arr[5] = 97;
    arr[6] = 72;
    arr[7] = 45;
    arr[8] = 125.0F;

    Matrix *m = CreateMatrix(arr, 3, 3);
    PrintMatrix(m);
    return 0;
}