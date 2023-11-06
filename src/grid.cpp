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
            DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
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

// Function to check if a cell at the given row and column is empty (not occupied by a block)
bool Grid::IsCellEmpty(int row, int col)
{
    // If the cell's value is 0, it means the cell is empty and can be occupied
    if (grid[row][col] == 0)
    {
        return true;
    }

    // If the cell's value is not 0, it means the cell is occupied and cannot be occupied
    return false;
}

// Function to clear all rows that are completely filled with blocks
int Grid::ClearFullRows()
{
    int completed = 0; // Counter for the number of rows cleared

    // Iterate through each row from bottom to top
    for (int row = numRows - 1; row >= 0; row--)
    {
        // Check if the current row is full
        if (IsRowFull(row))
        {
            ClearRow(row); // Clear the full row
            completed++;   // Increment the completed rows counter
        }
        // If rows have been completed and the current row is not full, move it down
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }

    // Return the number of rows that were cleared
    return completed;
}

// Function to check if a row is completely filled with blocks
bool Grid::IsRowFull(int row)
{
    // Iterate through each column in the row
    for (int col = 0; col < numCols; col++)
    {
        // If any cell in the row is empty, the row is not full
        if (grid[row][col] == 0)
        {
            return false;
        }
    }

    // If all cells in the row are occupied, the row is full
    return true;
}

// Function to clear a row by setting all its cells to empty
void Grid::ClearRow(int row)
{
    // Iterate through each column in the row
    for (int col = 0; col < numCols; col++)
    {
        // Set each cell in the row to 0, indicating it is empty
        grid[row][col] = 0;
    }
}

// Function to move a row down by a certain number of rows
void Grid::MoveRowDown(int row, int numRows)
{
    // Iterate through each column in the row
    for (int col = 0; col < numCols; col++)
    {
        // Move the cell's value down by the specified number of rows
        grid[row + numRows][col] = grid[row][col];
        // Set the original cell's value to 0, indicating it is now empty
        grid[row][col] = 0;
    }
}
