
#include "../include/window.h"
#include "../include/widget/layout.h"
#include "../include/widget/container.h"

//=============================Main Section============================================
int main(int argc, char const *argv[])
{
    Window win = createWindow(200, 200, "Some title");
    Layout *layout = createLayout((Widget){.x = 0, .y = 0, .width = win.width, .height = win.height}, LAYOUT_HORIZONTAL);

    pushChildrenToLayout(layout, &(createContainer(12, 12, GREEN)->base));
    pushChildrenToLayout(layout, &(createContainer(12, 12, RED)->base));
    pushChildrenToLayout(layout, &(createContainer(12, 12, BLACK)->base));
    pushChildrenToLayout(layout, &(createContainer(12, 12, ORANGE)->base));
    pushChildrenToLayout(layout, &(createContainer(12, 12, YELLOW)->base));
    Layout *layout2 = createLayout((Widget){.x = 0, .y = 0, .width = win.width, .height = win.height}, LAYOUT_VERTICAL);
    pushChildrenToLayout(layout2, &(createContainer(12, 12, WHITE)->base));
    pushChildrenToLayout(layout2, &(createContainer(12, 12, BROWN)->base));
    pushChildrenToLayout(layout2, &(createContainer(12, 12, GRAY)->base));
    pushChildrenToLayout(layout, &(layout2->base));

    while (!isWindowClosed(&win))
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        updateWindow(&win);
        updateLayout(&win, layout);

        paintLayout(layout);
        EndDrawing();
    }

    closeWindow(&win);
    return 0;
}
