#ifndef _CGUI_WIDGET_LAYOUT_H_
#define _CGUI_WIDGET_LAYOUT_H_
#include "./widget_collection.h"
#include"../window.h"

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




extern Layout *createLayout(Widget base, LayoutDirection direction);

extern void destroyLayout(Layout *layout);

extern void pushChildrenToLayout(Layout *layout, Widget *widget);

extern void updateLayout(Window *win, Layout *layout);
extern void paintLayout(void *layout_void);
#endif