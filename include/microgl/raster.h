#ifndef RASTER_H_
#define RASTER_H_

#include "../math/utils.h"

#include "frame.h"
#include "zframe.h"
#include "shader.h"

void fill_triangle(Frame* frame, ZFrame* z_frame, void* verts[3], VertShader vert_shader, FragShader frag_shader);
void fill_triangles(Frame* frame, ZFrame* z_frame, void* verts, size_t vert_len, int* inds, int inds_len, VertShader vert_shader, FragShader frag_shader);

#endif