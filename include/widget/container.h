#ifndef _CGUI_WIDGET_CONTAINER_H_
#define _CGUI_WIDGET_CONTAINER_H_
#include "./widget.h"
#include "../common.h"

typedef struct
{
    Widget base;
    Color color;
} Container;

Container *createContainer(float width, float height, Color color);
#endif