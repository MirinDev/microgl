#include <math/vectors/vec2.h>

vec2 add_v2(vec2 v1, vec2 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, 0, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, 0, 0);

    __m128 v_id = _mm_add_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec2){v[3], v[2]};
}

vec2 sub_v2(vec2 v1, vec2 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, 0, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, 0, 0);

    __m128 v_id = _mm_sub_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec2){v[3], v[2]};
}

vec2 mul_v2(vec2 v1, vec2 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, 0, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, 0, 0);

    __m128 v_id = _mm_mul_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec2){v[0], v[1]};
}

vec2 div_v2(vec2 v1, vec2 v2)
{
    __m128 v1_id = _mm_set_ps(v1.x, v1.y, 0, 0);
    __m128 v2_id = _mm_set_ps(v2.x, v2.y, 0, 0);

    __m128 v_id = _mm_div_ps(v1_id, v2_id);
    float* v = (float*)&v_id;

    return (vec2){v[3], v[2]};
}

vec2 normalize_v2(vec2 v)
{
    float l = sqrtf(powf(v.x, 2) + powf(v.y, 2));
    if (l == 0) return v;

    __m128 v1_id = _mm_set_ps(v.x, v.y, 0, 0);
    __m128 v2_id = _mm_set_ps(l, l, l, l);

    __m128 v_id = _mm_div_ps(v1_id, v2_id);
    float* r = (float*)&v_id;

    return (vec2){r[3], r[2]};
}