#include <raylib.h> // Include the Raylib library for game development
#include "game.h"   // Include the Game Class

int main()
{
    Color darkBlue = {44, 44, 127, 255}; // Define a dark blue color
    InitWindow(300, 600, "Tetris");      // Initialize the game window with dimensions 300x600 and title "Tetris"
    SetTargetFPS(60);                    // Set the target frames per second to 60

    Game game = Game();

    while (!WindowShouldClose()) // Main game loop; continues until the window is closed
    {
        game.HandleInput();

        BeginDrawing(); // Begin the drawing phase

        ClearBackground(darkBlue); // Clear the background with the dark blue color

        game.Draw();

        EndDrawing(); // End the drawing phase
    }

    CloseWindow(); // Close the game window and free up resources
    return 0;      // Return 0 to indicate successful execution
}
