#ifndef FRAME_H_
#define FRAME_H_

typedef struct 
{
    char* data;
    int w, h;
} Frame;

Frame* create_frame(int w, int h);
Frame* create_frame_data(char* data, int w, int h);
void delete_frame(Frame* frame);
void clear_frame(Frame* frame, char ch);

#endif