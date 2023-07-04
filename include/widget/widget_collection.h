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

WidgetCollection *createWidgetCollection();

void destroyWidgetCollection(WidgetCollection *collection);

void pushWidget(WidgetCollection *collection, Widget *widget);
#endif