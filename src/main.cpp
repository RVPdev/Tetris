#include <raylib.h> // Include the Raylib library for game development
#include "game.h"   // Include the Game Class
#include "colors.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Tetris"); // Initialize the game window with dimensions 300x600 and title "Tetris"
    SetTargetFPS(60);               // Set the target frames per second to 60

    Game game = Game();

    while (!WindowShouldClose()) // Main game loop; continues until the window is closed
    {

        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        BeginDrawing(); // Begin the drawing phase

        ClearBackground(darkBlue); // Clear the background with the dark blue color

        DrawText("Score", 355, 15, 38, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        game.Draw();

        EndDrawing(); // End the drawing phase
    }

    CloseWindow(); // Close the game window and free up resources
    return 0;      // Return 0 to indicate successful execution
}
