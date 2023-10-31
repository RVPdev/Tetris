#pragma once        // Ensures that the header file is included only once in a compilation
#include <vector>   // Include the standard vector library
#include <raylib.h> // Include the Raylib library for game development

class Grid // Define the Grid class
{
public:                // Public members and methods
    Grid();            // Constructor declaration
    void Initialize(); // Method to initialize the grid
    void Print();      // Method to print the grid (likely for debugging)
    void Draw();       // Method to Draw the grid
    int grid[20][10];  // 2D array representing the grid, with 20 rows and 10 columns

private:                                // Private members and methods
    int numRows;                        // Number of rows in the grid
    int numCols;                        // Number of columns in the grid
    int cellSize;                       // Size of each cell in the grid
    std::vector<Color> colors;          // Vector to store the colors for each cell
};
