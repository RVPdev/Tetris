#include "grid.h"   // Include the header file for the Grid class
#include <iostream> // Include the standard I/O library

using namespace std; // Use the standard namespace

// Constructor for the Grid class
Grid::Grid()
{
    numCols = 10;             // Initialize the number of columns to 10
    numRows = 20;             // Initialize the number of rows to 20
    cellSize = 30;            // Initialize the size of each cell to 30 units
    Initialize();             // Call the Initialize method to set up the grid
    colors = GetCellColors(); // Initialize colors array
}

// Initialize the grid with zeros
void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++) // Loop through each row
    {
        for (int column = 0; column < numCols; column++) // Loop through each column in the current row
        {
            grid[row][column] = 0; // Set each cell to 0 (empty)
        }
    }
}

// Print the grid to the console (likely for debugging)
void Grid::Print()
{
    for (int row = 0; row < numRows; row++) // Loop through each row
    {
        for (int column = 0; column < numCols; column++) // Loop through each column in the current row
        {
            cout << grid[row][column] << " "; // Print the value of each cell, followed by a space
        }
        cout << endl; // Move to the next line after printing all columns in the current row
    }
}

// GetCellColors returns a vector of Color objects that represent the different colors for the cells.
std::vector<Color> Grid::GetCellColors()
{
    // Define the colors for the cells
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 213, 255};

    // Return a vector containing all the defined colors
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

// Draw method is responsible for drawing the grid on the screen.
void Grid::Draw()
{
    // Loop through each row in the grid
    for (int row = 0; row < numRows; row++)
    {
        // Loop through each column in the grid
        for (int col = 0; col < numCols; col++)
        {
            // Get the value of the cell at the current row and column
            int cellValue = grid[row][col];

            // Draw the cell using the color corresponding to its value
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}
