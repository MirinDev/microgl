#ifndef MAT3_H_
#define MAT3_H_

#include <math.h>
#include <immintrin.h>
#include "../vectors.h"

typedef union 
{
    float m3x3[3][3];
    float m9[9];
} mat3;

float deg2rad(float deg);

#endif