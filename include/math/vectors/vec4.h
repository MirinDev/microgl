#ifndef VEC4_H_
#define VEC4_H_

#include <math.h>
#include <immintrin.h>

#include "vec2.h"
#include "vec3.h"

typedef union 
{
    struct{float x, y, z, w;};
    struct{float data[4];};
} vec4;

vec3 xyz_v4(vec4 v);

vec4 v2_to_v4(vec2 v, float x, float y);
vec4 v3_to_v4(vec3 v, float x);

vec4 add_v4(vec4 v1, vec4 v2);
vec4 sub_v4(vec4 v1, vec4 v2);
vec4 mul_v4(vec4 v1, vec4 v2);
vec4 div_v4(vec4 v1, vec4 v2);
vec4 normalize_v4(vec4 v);

#endif