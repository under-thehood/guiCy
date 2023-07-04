#include"../include/window.h"



Window createWindow(int width, int height, char *title)
{
    InitWindow(width, height, title);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    return (Window){.width = width, .height = height, .title = title};
}

void closeWindow(Window *win)
{
    CloseWindow();
}

bool isWindowClosed(Window *win)
{
    return WindowShouldClose();
}

void updateWindow(Window *win)
{
    if (IsWindowResized())
    {
        win->width = GetScreenWidth();
        win->height = GetScreenHeight();
    }
}
