#include <microgl/raster.h>

void fill_triangle(Frame* frame, ZFrame* z_frame, void* verts[3], VertShader vert_shader, FragShader frag_shader)
{
    vec4 tri[3];

    for (int i = 0; i < 3; i++)
    {
        tri[i] = (*vert_shader)(verts[i]);

        tri[i] = normalize_v4(tri[i]);

        tri[i].x = (tri[i].x + 0.5) * frame->w;
        tri[i].y = (tri[i].y + 0.5) * frame->h;
    }
    
    int min_x = clamp(min(tri[0].x, min(tri[1].x, tri[2].x)), 0, frame->w-1);
    int max_x = clamp(max(tri[0].x, max(tri[1].x, tri[2].x)), 0, frame->w-1);
    int min_y = clamp(min(tri[0].y, min(tri[1].y, tri[2].y)), 0, frame->h-1);
    int max_y = clamp(max(tri[0].y, max(tri[1].y, tri[2].y)), 0, frame->h-1);

    float tri_area = (tri[1].x - tri[0].x) * (tri[2].y - tri[0].y) - (tri[1].y - tri[0].y) * (tri[2].x - tri[0].x);
    for (int y = min_y; y <= max_y; y++)
    {
        for (int x = min_x; x <= max_x; x++)
        {
            float areaPBC = (tri[1].x - x) * (tri[2].y - y) - (tri[1].y - y) * (tri[2].x - x);
            float areaPAC = (tri[2].x - x) * (tri[0].y - y) - (tri[2].y - y) * (tri[0].x - x);
            float areaPAB = (tri[0].x - x) * (tri[1].y - y) - (tri[0].y - y) * (tri[1].x - x);

            float a = areaPBC / tri_area;
            float b = areaPAC / tri_area;
            float g = areaPAB / tri_area;

            if ((a >= 0.0 && b >= 0.0 && g >= 0.0))
            {
                float z = tri[0].z * a + tri[1].z * b + tri[2].z * g;

                if (z > 0 && z < 1 && z < *(z_frame->data + y * z_frame->w + x))
                {
                    *(frame->data + y * frame->w + x) = (*frag_shader)(verts, (vec3){a, b, g});
                    *(z_frame->data + y * z_frame->w + x) = z;
                }
            }
        }
    }
}

void fill_triangles(Frame* frame, ZFrame* z_frame, void* verts, size_t vert_size, int* inds, int inds_len, VertShader vert_shader, FragShader frag_shader)
{
    void* v[3];

    for (int i = 0; i < inds_len; i+=3)
    {
        v[0] = verts + inds[i] * vert_size;
        v[1] = verts + inds[i + 1] * vert_size;
        v[2] = verts + inds[i + 2] * vert_size;

        fill_triangle(frame, z_frame, v, vert_shader, frag_shader);
    }
}