#ifndef _CGUI_WIDGET_H_
#define _CGUI_WIDGET_H_

typedef struct _widget
{
    float x;
    float y;
    float width;
    float height;
    void (*paint)(void *widget);
} Widget;

// void displayChildren(Widget widget, Color color)
// {
//     DrawRectangle(widget.x, widget.y, widget.width, widget.height, color);
// }


#endif