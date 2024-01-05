#include <microgl/shader.h>

vec2 interpolate_v2(vec2 v[3], vec3 interpolate)
{
    vec2 r;
    r.x = v[0].x * interpolate.x + v[1].x * interpolate.y + v[2].x * interpolate.z;
    r.y = v[0].y * interpolate.x + v[1].y * interpolate.y + v[2].y * interpolate.z;

    return r;
}

vec3 interpolate_v3(vec3 v[3], vec3 interpolate)
{
    vec3 r;
    r.x = v[0].x * interpolate.x + v[1].x * interpolate.y + v[2].x * interpolate.z;
    r.y = v[0].y * interpolate.x + v[1].y * interpolate.y + v[2].y * interpolate.z;
    r.z = v[0].z * interpolate.x + v[1].z * interpolate.y + v[2].z * interpolate.z;

    return r;
}

char Texture(Frame* frame, vec2 uv)
{
    int x = uv.x * (float)frame->w;
    int y = uv.y * (float)frame->h;
    
    return *(frame->data + y * frame->w + x);
}