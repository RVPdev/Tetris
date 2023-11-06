#include "grid.h"   // Include the header file for the Grid class
#include <iostream> // Include the standard I/O library
#include "colors.h"

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

// Method to check if a cell is outside the boundaries of the grid
bool Grid::IsCellOutside(int row, int col)
{
    // Check if the cell's row and column are within the grid boundaries
    if (row >= 0 && row < numRows && col >= 0 && col < numCols)
    {
        return false; // The cell is inside the grid, return false
    }

    // If the cell's row or column are outside the grid boundaries, return true
    return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
    if (grid[row][col] == 0)
    {
        return true;
    }

    return false;
}
