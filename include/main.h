#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "math/vectors.h"
#include "math/matrizes.h"
#include "math/angles.h"
#include "math/utils.h"

#include "microgl/frame.h"
#include "microgl/zframe.h"
#include "microgl/shader.h"

#include "microgl/raster.h"
#include "microgl/pipeline.h"

typedef struct 
{
    vec3 v;
    vec2 u;
    vec3 n;
} vertice;


vertice model[] = {
    (vertice){(vec3){-0.5, -0.5, -0.5}, (vec2){0, 0}, (vec3){0, 0, -1}}, 
    (vertice){(vec3){0.5, -0.5, -0.5}, (vec2){1, 0}, (vec3){0, 0, -1}}, 
    (vertice){(vec3){ 0.5,  0.5, -0.5}, (vec2){1, 1}, (vec3){0, 0, -1}}, 
    (vertice){(vec3){-0.5, 0.5, -0.5}, (vec2){0, 1}, (vec3){0, 0, -1}},

    (vertice){(vec3){-0.5, -0.5, 0.5}, (vec2){0, 0}, (vec3){0, 0, 1}}, 
    (vertice){(vec3){0.5, -0.5, 0.5}, (vec2){1, 0}, (vec3){0, 0, 1}}, 
    (vertice){(vec3){ 0.5,  0.5, 0.5}, (vec2){1, 1}, (vec3){0, 0, 1}}, 
    (vertice){(vec3){-0.5, 0.5, 0.5}, (vec2){0, 1}, (vec3){0, 0, 1}},

    (vertice){(vec3){-0.5, -0.5, -0.5}, (vec2){0, 0}, (vec3){-1, 0, 0}}, 
    (vertice){(vec3){-0.5, -0.5, 0.5}, (vec2){1, 0}, (vec3){-1, 0, 0}},
    (vertice){(vec3){-0.5, 0.5, 0.5}, (vec2){1, 1}, (vec3){-1, 0, 0}}, 
    (vertice){(vec3){-0.5, 0.5,-0.5}, (vec2){0, 1}, (vec3){-1, 0, 0}},

    (vertice){(vec3){0.5, -0.5, -0.5}, (vec2){0, 0}, (vec3){1, 0, 0}}, 
    (vertice){(vec3){0.5, -0.5, 0.5}, (vec2){1, 0}, (vec3){1, 0, 0}},
    (vertice){(vec3){0.5, 0.5, 0.5}, (vec2){1, 1}, (vec3){1, 0, 0}}, 
    (vertice){(vec3){0.5, 0.5,-0.5}, (vec2){0, 1}, (vec3){1, 0, 0}},

    (vertice){(vec3){-0.5, -0.5, -0.5}, (vec2){0, 0}, (vec3){0, -1, 0}}, 
    (vertice){(vec3){0.5, -0.5, -0.5}, (vec2){1, 0}, (vec3){0, -1, 0}},
    (vertice){(vec3){0.5, -0.5, 0.5}, (vec2){1, 1}, (vec3){0, -1, 0}}, 
    (vertice){(vec3){-0.5, -0.5, 0.5}, (vec2){0, 1}, (vec3){0, -1, 0}},

    (vertice){(vec3){-0.5, 0.5, -0.5}, (vec2){0, 0}, (vec3){0, 1, 0}}, 
    (vertice){(vec3){0.5, 0.5, -0.5}, (vec2){1, 0}, (vec3){0, 1, 0}},
    (vertice){(vec3){0.5, 0.5, 0.5}, (vec2){1, 0}, (vec3){0, 1, 0}}, 
    (vertice){(vec3){-0.5, 0.5, 0.5}, (vec2){1, 1}, (vec3){0, 1, 0}},
};

int model_inds[] = {
    0, 1, 2,
    2, 3, 0,

    4, 5, 6,
    6, 7, 4,

    8, 9, 10,
    10, 11, 8,

    12, 13, 14,
    14, 15, 12,

    16, 17, 18,
    18, 19, 16,

    20, 21, 22,
    22, 23, 20
};

#endif