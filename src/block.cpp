#include "block.h" // Include the Block class header

// Constructor for the Block class
Block::Block()
{
    cellSize = 30;            // Set the cell size to 30 units
    rotationState = 0;        // Initialize the rotation state to 0
    colors = GetCellColors(); // Fetch the cell colors using the GetCellColors function
    rowOffset = 0;
    columnOffset = 0;
}

// Method to draw the block
void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions(); // Fetch the block cells for the current rotation state
    for (Position item : tiles)                       // Loop through each position in the tiles vector
    {
        // Draw each tile as a rectangle on the screen
        // We add and subtract 1 to give it a little border
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

// Method to move the block by a certain number of rows and columns
void Block::Move(int rows, int columns)
{
    rowOffset += rows;       // Increase the row offset by the specified number of rows
    columnOffset += columns; // Increase the column offset by the specified number of columns
}

// Method to get the positions of the cells in the current block, adjusted for the current offsets
std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState]; // Get the positions of the cells for the current rotation state
    std::vector<Position> movedTiles;                   // Vector to store the adjusted positions

    // Loop through each cell position
    for (Position item : tiles)
    {
        // Create a new Position object with the adjusted row and column values
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos); // Add the adjusted position to the vector
    }

    return movedTiles; // Return the vector of adjusted positions
}

// Method to rotate the block to its next rotation state
void Block::Rotate()
{
    rotationState++; // Increment the rotation state to rotate the block

    // Check if the rotation state has reached the number of possible states
    if (rotationState == (int)cells.size())
    {
        rotationState = 0; // Reset the rotation state back to the initial state if it has
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if(rotationState == -1)
    {
        rotationState = cells.size() -1;
    }
}
