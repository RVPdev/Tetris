#include <raylib.h>   // Include the Raylib library for game development
#include "grid.h"     // Include the custom Grid class header
#include "blocks.cpp" // Include the blocks definitions

int main()
{
    Color darkBlue = {44, 44, 127, 255}; // Define a dark blue color
    InitWindow(300, 600, "Tetris");      // Initialize the game window with dimensions 300x600 and title "Tetris"
    SetTargetFPS(60);                    // Set the target frames per second to 60

    Grid grid = Grid(); // Create a new Grid object
    grid.Print();       // Call the Print method of the Grid object to display its contents (for debugging)

    LBlock block = LBlock(); // Create a new LBlock object

    while (!WindowShouldClose()) // Main game loop; continues until the window is closed
    {
        BeginDrawing(); // Begin the drawing phase

        ClearBackground(darkBlue); // Clear the background with the dark blue color

        grid.Draw(); // Draw the grid on the screen

        block.Draw(); // Draw the LBlock on the screen

        EndDrawing(); // End the drawing phase
    }

    CloseWindow(); // Close the game window and free up resources
    return 0;      // Return 0 to indicate successful execution
}
