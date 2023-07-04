#ifndef _CGUI_WINDOW_H_
#define _CGUI_WINDOW_H_
#include "./common.h"

typedef struct
{
    int width;
    int height;
    char *title;
} Window;

Window createWindow(int width, int height, char *title);

void closeWindow(Window *win);

bool isWindowClosed(Window *win);

void updateWindow(Window *win);

#endif