#include "../../include/widget/widget_collection.h"

#define LAYOUT_STACK_INITIAL_SIZE 4

void checkMemory(void *memory)
{
    if (memory == NULL)
    {
        fprintf(stderr, "[ERROR]:%s", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void growWidgetCollection(WidgetCollection *collection)
{
    collection->data = (Widget **)realloc(collection->data, collection->capacity + LAYOUT_STACK_INITIAL_SIZE);
    checkMemory(collection->data);
    collection->capacity = collection->capacity + LAYOUT_STACK_INITIAL_SIZE;
}

WidgetCollection *createWidgetCollection()
{
    WidgetCollection *stack = (WidgetCollection *)malloc(sizeof(WidgetCollection));
    checkMemory(stack);
    stack->data = (Widget **)malloc(sizeof(Widget *) * LAYOUT_STACK_INITIAL_SIZE);
    checkMemory(stack->data);

    stack->capacity = LAYOUT_STACK_INITIAL_SIZE;
    stack->size = 0;
    return stack;
}
void destroyWidgetCollection(WidgetCollection *collection)
{
    free(collection->data);
    collection->size = 0;
    collection->capacity = 0;
    free(collection);
}

void pushWidget(WidgetCollection *collection, Widget *widget)
{
    if ((collection->size + 2) > collection->capacity)
    {
        growWidgetCollection(collection);
    }
    // memcpy(collection->data + collection->size++, widget, sizeof(Widget));
    collection->data[collection->size++] = widget;
}
