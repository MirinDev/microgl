#include <math/vectors/vec4.h>

vec3 xyz_v4(vec4 v)
{
    return (vec3){v.x, v.y, v.z};
}

vec4 v2_to_v4(vec2 v, float x, float y)
{
    return (vec4){v.x, v.y, x, y};
}

vec4 v3_to_v4(vec3 v, float x)
{
    return (vec4){v.x, v.y, v.z, x};
}

vec4 add_v4(vec4 v1, vec4 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, v1.w);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, v2.w);

    __m128 v_id = _mm_add_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec4){v[3], v[2], v[1], v[0]};
}

vec4 sub_v4(vec4 v1, vec4 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, v1.w);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, v2.w);

    __m128 v_id = _mm_sub_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec4){v[3], v[2], v[1], v[0]};
}

vec4 mul_v4(vec4 v1, vec4 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, v1.w);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, v2.w);

    __m128 v_id = _mm_mul_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec4){v[3], v[2], v[1], v[0]};
}

vec4 div_v4(vec4 v1, vec4 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, v1.z, v1.w);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, v2.z, v2.w);

    __m128 v_id = _mm_div_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec4){v[3], v[2], v[1], v[0]};
}

vec4 normalize_v4(vec4 v)
{
    float l = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2) + powf(v.w, 2));
    if (l == 0) return v;

    __m128 v1_id = _mm_set_ps(v.x, v.y, v.z, v.w);
    __m128 v2_id = _mm_set_ps(l, l, l, l);

    __m128 v_id = _mm_div_ps(v1_id, v2_id);
    float* r = (float*)&v_id;

    return (vec4){r[3], r[2], r[1], r[0]};
}
