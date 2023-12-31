#include <raylib.h> // Include the Raylib library for game development
#include "game.h"   // Include the Game Class
#include "colors.h"
#include <iostream>

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
        DrawText("Next", 355, 175, 38, WHITE);
        if (game.gameOver)
        {
            DrawText("GAME OVER", 320, 450, 29, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        int textSize = MeasureText(scoreText, 38);

        DrawText(scoreText, 320 + (170 - textSize) / 2, 65, 38, WHITE);

        game.Draw();

        EndDrawing(); // End the drawing phase
    }

    CloseWindow(); // Close the game window and free up resources
    return 0;      // Return 0 to indicate successful execution
}
