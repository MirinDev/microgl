#include <microgl/zframe.h>

ZFrame* create_zframe(int w, int h)
{
    ZFrame* z_frame = (ZFrame*)malloc(sizeof(ZFrame));
    
    z_frame->data = (float*)malloc(sizeof(float) * w * h);
    z_frame->w = w;
    z_frame->h = h;

    return z_frame;
}

void delete_zframe(ZFrame* z_frame)
{
    free(z_frame->data);
    free(z_frame);
}

void clear_zframe(ZFrame* z_frame)
{
    for (int i = 0; i < z_frame->w * z_frame->h; i++)
        z_frame->data[i] = 1.0;
}