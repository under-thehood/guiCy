#ifndef _CGUI_WINDOW_H_
#define _CGUI_WINDOW_H_
#include "./common.h"

typedef struct
{
    int width;
    int height;
    char *title;
} Window;

extern Window createWindow(int width, int height, char *title);

extern void closeWindow(Window *win);

extern bool isWindowClosed(Window *win);

extern void updateWindow(Window *win);

#endif