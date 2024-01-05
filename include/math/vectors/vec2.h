#ifndef VEC2_H_
#define VEC2_H_

#include <math.h>
#include <immintrin.h>

typedef union
{
    struct{float x, y;};
    struct{float data[2];};
} vec2;

vec2 add_v2(vec2 v1, vec2 v2);
vec2 sub_v2(vec2 v1, vec2 v2);
vec2 mul_v2(vec2 v1, vec2 v2);
vec2 div_v2(vec2 v1, vec2 v2);
vec2 normalize_v2(vec2 v);

#endif