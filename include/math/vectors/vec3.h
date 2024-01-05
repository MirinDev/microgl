#ifndef VEC3_H_
#define VEC3_H_

#include <math.h>
#include <immintrin.h>

#include "vec2.h"

typedef union 
{
    struct{float x, y, z;};
    struct{float data[3];};
} vec3;

vec3 v2_to_v3(vec2 v, float x);

vec3 add_v3(vec3 v1, vec3 v2);
vec3 sub_v3(vec3 v1, vec3 v2);
vec3 mul_v3(vec3 v1, vec3 v2);
vec3 div_v3(vec3 v1, vec3 v2);
vec3 normalize_v3(vec3 v);
float dot_v3(vec3 v1, vec3 v2);

#endif