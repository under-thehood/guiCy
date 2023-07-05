#ifndef _CGUI_WIDGET_COLLECTION_H_
#define _CGUI_WIDGET_COLLECTION_H_
#include "./widget.h"
#include "../common.h"

typedef struct
{
    Widget **data;
    size_t size;
    size_t capacity;
} WidgetCollection;

extern WidgetCollection *createWidgetCollection();

extern void destroyWidgetCollection(WidgetCollection *collection);

extern void pushWidget(WidgetCollection *collection, Widget *widget);
#endif