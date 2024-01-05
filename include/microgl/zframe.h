#ifndef ZFRAME_H_
#define ZFRAME_H_

typedef struct 
{
    float* data;
    int w, h;
} ZFrame;

ZFrame* create_zframe(int w, int h);
void delete_zframe(ZFrame* z_frame);
void clear_zframe(ZFrame* z_frame);

#endif