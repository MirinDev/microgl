#include <math/vectors/vec3.h>

vec3 v2_to_v3(vec2 v, float x)
{
    return (vec3){v.x, v.y, x};
}

vec3 add_v3(vec3 v1, vec3 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, 0);

    __m128 v_id = _mm_add_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec3){v[3], v[2], v[1]};
}

vec3 sub_v3(vec3 v1, vec3 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, 0);

    __m128 v_id = _mm_sub_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec3){v[3], v[2], v[1]};
}

vec3 mul_v3(vec3 v1, vec3 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, 0);

    __m128 v_id = _mm_mul_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec3){v[3], v[2], v[1]};
}

vec3 div_v3(vec3 v1, vec3 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, 0);

    __m128 v_id = _mm_div_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec3){v[3], v[2], v[1]};
}

vec3 normalize_v3(vec3 v)
{
    float l = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
    if (l == 0) return v;

    __m128 v1_id = _mm_set_ps(v.x, v.y, v.z, 0);
    __m128 v2_id = _mm_set_ps(l, l, l, l);

    __m128 v_id = _mm_div_ps(v1_id, v2_id);
    float* r = (float*)&v_id;

    return (vec3){r[3], r[2], r[1]};
}

float dot_v3(vec3 v1, vec3 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, 0);

    __m128 v_id = _mm_mul_ps(v1_id, v2_id);
    float* r = (float*)&v_id;

    return r[3] + r[2] + r[1];
}