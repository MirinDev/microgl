#include <microgl/frame.h>

Frame* create_frame(int w, int h)
{
    Frame* frame = (Frame*)malloc(sizeof(Frame));
    
    frame->data = (char*)malloc(w * h);
    frame->w = w;
    frame->h = h;

    return frame;
}

Frame* create_frame_data(char* data, int w, int h)
{
    Frame* frame = (Frame*)malloc(sizeof(Frame));
    
    frame->data = (char*)malloc(w * h);
    memcpy(frame->data, data, w * h);

    frame->w = w;
    frame->h = h;

    return frame;
}

void clear_frame(Frame* frame, char ch)
{
    memset(frame->data, ch, frame->w * frame->h);
}

void delete_frame(Frame* frame)
{
    free(frame->data);
    free(frame);
}