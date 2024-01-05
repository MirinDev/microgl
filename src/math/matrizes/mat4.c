#include <math/matrizes/mat4.h>

mat4 mul_m4(mat4 m1, mat4 m2)
{
    mat4 m;

    for (int i = 0; i < 4; i+=2)
    {
        __m256 v1_id = _mm256_loadu_ps(m1.m4x4[i]);

        for (int j = 0; j < 4; j++)
        {
            __m256 v2_id = _mm256_set_ps(m2.m4x4[3][j], m2.m4x4[2][j], m2.m4x4[1][j], m2.m4x4[0][j], 
                                         m2.m4x4[3][j], m2.m4x4[2][j], m2.m4x4[1][j], m2.m4x4[0][j]);
            __m256 v = _mm256_mul_ps(v1_id, v2_id);
            m.m4x4[i + 1][j] = v[7] + v[6] + v[5] + v[4];
            m.m4x4[i][j]     = v[3] + v[2] + v[1] + v[0];
        }
    }

    return m;
}

vec4 mul_v4_m4(mat4 m, vec4 v)
{
    vec4 r;

    __m256 v1_id = _mm256_set_ps(v.w, v.z, v.y, v.x, 
                                 v.w, v.z, v.y, v.x);

    for (int i = 0; i < 4; i+=2)
    {
        __m256 v2_id = _mm256_loadu_ps(m.m4x4[i]);
        __m256 v_id = _mm256_mul_ps(v1_id, v2_id);

        r.data[i + 1] = v_id[7] + v_id[6] + v_id[5] + v_id[4];
        r.data[i]     = v_id[3] + v_id[2] + v_id[1] + v_id[0];
    }

    return r;
}

mat4 identity(float v)
{
    return (mat4){
        v, 0, 0, 0,
        0, v, 0, 0,
        0, 0, v, 0,
        0, 0, 0, v
    };
}

mat4 project(float aspect, float fov, float near, float far)
{
    mat4 m = identity(1.0);

    float ar = tanf(fov / 2.0f);

    m.m16[0] = 1 / (aspect * ar);
    m.m16[5] = 1 / ar;
    m.m16[10] = - (far + near) / (far - near);
    m.m16[11] = - (2 * far * near) / (far - near);

    m.m16[14] = -1;
    m.m16[15] = 0;

    return m;
}

mat4 translate(mat4 m, vec3 v)
{
    mat4 translate_m = identity(1.0);

    translate_m.m16[3] = v.x;
    translate_m.m16[7] = v.y;
    translate_m.m16[11] = v.z;

    return mul_m4(m, translate_m);
}

mat4 rotate_x(mat4 m, float r)
{
    mat4 rotate_m = identity(1.0);

    rotate_m.m16[5] = cosf(r);
    rotate_m.m16[6] = -sinf(r);
    rotate_m.m16[9] = sinf(r);
    rotate_m.m16[10] = cosf(r);

    return mul_m4(m, rotate_m);
}

mat4 rotate_y(mat4 m, float r)
{
    mat4 rotate_m = identity(1.0);

    rotate_m.m16[0] = cosf(r);
    rotate_m.m16[2] = sinf(r);
    rotate_m.m16[8] = -sinf(r);
    rotate_m.m16[10] = cosf(r);

    return mul_m4(m, rotate_m);
}
