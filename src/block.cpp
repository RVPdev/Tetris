#include "block.h" // Include the Block class header

// Constructor for the Block class
Block::Block()
{
    cellSize = 30;            // Set the cell size to 30 units
    rotationState = 0;        // Initialize the rotation state to 0
    colors = GetCellColors(); // Fetch the cell colors using the GetCellColors function
}

// Method to draw the block
void Block::Draw()
{
    std::vector<Position> tiles = cells[rotationState]; // Fetch the block cells for the current rotation state
    for (Position item : tiles)                         // Loop through each position in the tiles vector
    {
        // Draw each tile as a rectangle on the screen
        // We add and subtract 1 to give it a little border
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}
