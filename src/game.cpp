#include "game.h" // Include the header for the Game class
#include <random> // Include the random library for generating random numbers

// Constructor for the Game class
Game::Game()
{
    grid = Grid();                   // Initialize the grid for the game
    blocks = GetAllBlocks();         // Retrieve all types of blocks available in the game
    currentBlock = GetRandomBlock(); // Set the current block to a random block
    nextBlock = GetRandomBlock();    // Set the next block to a random block
}

// Method to get a random block from the available block types
Block Game::GetRandomBlock()
{
    if (blocks.empty()) // Check if the list of blocks is empty
    {
        blocks = GetAllBlocks(); // If empty, refill the list with all block types
    }
    int randomIndex = rand() % blocks.size();   // Generate a random index
    Block block = blocks[randomIndex];          // Get the block at the random index
    blocks.erase(blocks.begin() + randomIndex); // Remove the selected block from the list
    return block;                               // Return the randomly selected block
}

// Method to retrieve all block types for the game
std::vector<Block> Game::GetAllBlocks()
{
    // Return a vector containing one of each type of block
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

// Method to draw the game state
void Game::Draw()
{
    grid.Draw();         // Draw the grid
    currentBlock.Draw(); // Draw the current block
}

// Method to handle user input for moving blocks
void Game::HandleInput()
{
    int keyPressed = GetKeyPressed(); // Get the key pressed by the user

    switch (keyPressed) // Switch statement to handle different key presses
    {
    case KEY_LEFT:       // If the left arrow key is pressed
        MoveBlockLeft(); // Call the method to move the block left
        break;

    case KEY_RIGHT:       // If the right arrow key is pressed
        MoveBlockRight(); // Call the method to move the block right
        break;

    case KEY_DOWN:       // If the down arrow key is pressed
        MoveBlockDown(); // Call the method to move the block down
        break;

    case KEY_UP:       // If the up arrow key is pressed
        RotateBlock(); // Call the method to rotate the block
        break;
    }
}

// Method to move the current block one unit to the left
void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);             // Attempt to move the current block left by decreasing the column index by 1
    if (IsBlockOutside() || !BlockFits()) // Check if the block is outside the grid after moving
    {
        currentBlock.Move(0, 1); // Move the block back to the right if it went outside the grid
    }
}

// Method to move the current block one unit to the right
void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);              // Attempt to move the current block right by increasing the column index by 1
    if (IsBlockOutside() || !BlockFits()) // Check if the block is outside the grid after moving
    {
        currentBlock.Move(0, -1); // Move the block back to the left if it went outside the grid
    }
}

// Method to move the current block one unit down
void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);              // Attempt to move the current block down by increasing the row index by 1
    if (IsBlockOutside() || !BlockFits()) // Check if the block is outside the grid after moving
    {
        currentBlock.Move(-1, 0); // Move the block back up if it went outside the grid
        LockBlock();
    }
}

// Helper method to determine if any part of the current block is outside the grid boundaries
bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions(); // Get the current positions of the block's cells
    for (Position item : tiles)                                    // Iterate through each cell of the block
    {
        if (grid.IsCellOutside(item.row, item.column)) // Use the grid's method to check if the cell is outside
        {
            return true; // Return true if any cell is outside the grid
        }
    }
    return false; // Return false if all cells are inside the grid
}

// Method to rotate the current block within the game
void Game::RotateBlock()
{
    currentBlock.Rotate();                // Call the Rotate method of the current block to change its orientation
    if (IsBlockOutside() || !BlockFits()) // Undo rotation if the block is outside the grid
    {
        currentBlock.UndoRotation();
    }
}

// Method to lock the current block in place on the grid
void Game::LockBlock()
{
    // Retrieve the current positions of the block's cells
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    // Iterate through each cell position of the current block
    for (Position item : tiles)
    {
        // Set the grid cell's value to the block's ID, effectively placing the block on the grid
        grid.grid[item.row][item.column] = currentBlock.id;
    }

    // Replace the current block with the next block
    currentBlock = nextBlock;

    // Generate a new block to become the next block
    nextBlock = GetRandomBlock();
}

// Method to check if the current block fits in the grid without overlapping non-empty cells
bool Game::BlockFits()
{
    // Retrieve the current positions of the block's cells
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    // Iterate through each cell position of the current block
    for (Position item : tiles)
    {
        // Check if the cell at the block's position is not empty (i.e., already occupied)
        if (grid.IsCellEmpty(item.row, item.column) == false)
        {
            // If any cell is not empty, the block does not fit, return false
            return false;
        }
    }

    // If all cells are empty, the block fits, return true
    return true;
}
