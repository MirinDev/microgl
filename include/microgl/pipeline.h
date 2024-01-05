#ifndef PIPELINE_H_
#define PIPELINE_H_

#include <ncurses.h>
#include "frame.h"

void init();
void quit();

void present_frame(Frame* frame);

#endif