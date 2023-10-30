#include "grid.h"   // Include the header file for the Grid class
#include <iostream> // Include the standard I/O library

using namespace std; // Use the standard namespace

// Constructor for the Grid class
Grid::Grid()
{
    numCols = 10;  // Initialize the number of columns to 10
    numRows = 20;  // Initialize the number of rows to 20
    cellSize = 30; // Initialize the size of each cell to 30 units
    Initialize();  // Call the Initialize method to set up the grid
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
