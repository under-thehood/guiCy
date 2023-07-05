#include "../../include/widget/container.h"

static void paintContainer(void *widget)
{
    Container *container = (Container *)widget;
    DrawRectangle(container->base.x, container->base.y, container->base.width, container->base.height, container->color);
}

Container *createContainer(float width, float height, Color color)
{
    Container *container = (Container *)malloc(sizeof(Container));

    container->base.width = width;
    container->base.height = height;
    container->color = color;
    container->base.paint = paintContainer;
    return container;
}
