#include <raylib.h>
#include "grid.h"

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(darkBlue);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}