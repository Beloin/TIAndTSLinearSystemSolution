//
// Created by beloin on 10/09/2022.
//

#ifndef RETROSUBS_RETROSUB_H
#define RETROSUBS_RETROSUB_H

#include "matrix/Matrix.h"

int RetroSubstitution(Matrix *mx, Matrix *output);
int PrimitiveRetroSubstitution(double **mx, double **output, int rows, int cols);

#endif //RETROSUBS_RETROSUB_H
