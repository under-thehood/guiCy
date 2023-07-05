#include "../../include/widget/layout.h"

static void displayHorizontalLayout(Layout *layout)
{

    for (size_t i = 0; i < layout->childrens->size; i++)
    {
        layout->childrens->data[i]->width = ceilf(layout->base.width / layout->childrens->size);
        layout->childrens->data[i]->height = layout->base.height;
        layout->childrens->data[i]->x = layout->base.x + layout->childrens->data[i]->width * i;
        layout->childrens->data[i]->y = layout->base.y;
        layout->childrens->data[i]->paint((layout->childrens->data[i]));
        // displayChildren(widget, GREEN);
    }
}
static void displayVerticalLayout(Layout *layout)
{
    // Widget widget;
    for (size_t i = 0; i < layout->childrens->size; i++)
    {
        layout->childrens->data[i]->width = layout->base.width;
        layout->childrens->data[i]->height = ceilf(layout->base.height / layout->childrens->size);
        layout->childrens->data[i]->x = layout->base.x;
        layout->childrens->data[i]->y = layout->base.y + layout->childrens->data[i]->height * i;
        layout->childrens->data[i]->paint((layout->childrens->data[i]));
    }
}

void paintLayout(void *layout_void)
{
    Layout *layout = (Layout *)layout_void;
    if (layout->direction == LAYOUT_HORIZONTAL)
    {
        displayHorizontalLayout(layout);
    }

    if (layout->direction == LAYOUT_VERTICAL)
    {
        displayVerticalLayout(layout);
    }
}

Layout *createLayout(Widget base, LayoutDirection direction)
{
    Layout *layout = (Layout *)malloc(sizeof(Layout));
    layout->base = base;
    layout->direction = direction;
    layout->childrens = createWidgetCollection();
    layout->base.paint = paintLayout;
    return layout;
}
void destroyLayout(Layout *layout)
{
    destroyWidgetCollection(layout->childrens);
    free(layout);
}

void pushChildrenToLayout(Layout *layout, Widget *widget)
{
    pushWidget(layout->childrens, widget);
}

void updateLayout(Window *win, Layout *layout)
{
    layout->base.width = win->width;
    layout->base.height = win->height;
}