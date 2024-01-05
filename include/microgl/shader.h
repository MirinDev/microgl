#ifndef SHADER_H_
#define SHADER_H_

#include "../math/vectors.h"
#include "frame.h"

typedef vec4(*VertShader)(void*);
typedef char(*FragShader)(void*, vec3);

vec2 interpolate_v2(vec2 v[3], vec3 interpolate);
vec3 interpolate_v3(vec3 v[3], vec3 interpolate);
char Texture(Frame* frame, vec2 uv);

#endif