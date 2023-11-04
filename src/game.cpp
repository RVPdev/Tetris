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

void Game::HandleIinput()
{
    int keyPressed = GetKeyPressed();

    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;

    case KEY_RIGHT:
        MoveBlockRight();
        break;

    case KEY_DOWN:
        MoveBlockDown();
        break;
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
}