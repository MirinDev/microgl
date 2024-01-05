#ifndef MAT4_H_
#define MAT4_H_

#include <math.h>
#include <immintrin.h>
#include "../vectors.h"

typedef union 
{
    float m4x4[4][4];
    float m16[16];
} mat4;

mat4 mul_m4(mat4 m1, mat4 m2);
vec4 mul_v4_m4(mat4 m, vec4 v);

mat4 identity(float v);
mat4 project(float aspect, float fov, float near, float far);
mat4 translate(mat4 m, vec3 v);
mat4 rotate_x(mat4 m, float r);
mat4 rotate_y(mat4 m, float r);

#endif