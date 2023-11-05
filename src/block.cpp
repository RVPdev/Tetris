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
void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions(); // Fetch the block cells for the current rotation state
    for (Position item : tiles)                       // Loop through each position in the tiles vector
    {
        // Draw each tile as a rectangle on the screen
        // We add and subtract 1 to give it a little border
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
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

void Block::Rotate()
{
    rotationState++;
    if(rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}
