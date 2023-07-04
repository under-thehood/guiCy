#ifndef _CGUI_WIDGET_LAYOUT_H_
#define _CGUI_WIDGET_LAYOUT_H_
#include"./widget_collection.h"


typedef enum
{
    LAYOUT_HORIZONTAL,
    LAYOUT_VERTICAL
} LayoutDirection;

typedef struct
{
    Widget base;
    LayoutDirection direction;
    WidgetCollection *childrens;
} Layout;


Layout *createLayout(Widget base, LayoutDirection direction);

void destroyLayout(Layout *layout);

void pushChildrenToLayout(Layout *layout, Widget *widget);


// void updateLayout(Window *win, Layout *layout)
// {
//     layout->base.width = win->width;
//     layout->base.height = win->height;
// }

#endif