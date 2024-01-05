#include <microgl/pipeline.h>

void init()
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
}

void quit()
{
    endwin();
}

void present_frame(Frame* frame)
{
    char line[frame->w + 1];
    line[frame->w] = '\0';

    for (int y = 0; y < frame->h; y++)
    {
        memcpy(line, frame->data + y * frame->w, frame->w);

        move(y, 0);
        printw("%s", line);
    }

    refresh();
}