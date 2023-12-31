#pragma once          // Ensures this header file is included only once during compilation
#include "grid.h"     // Include the Grid class header for grid-related functionalities
#include "blocks.cpp" // Include the blocks definitions

// Game class encapsulates the main game logic and state
class Game
{
public:
    Game();                            // Constructor to initialize the game
    Block GetRandomBlock();            // Method to get a random block from the available types
    std::vector<Block> GetAllBlocks(); // Method to retrieve all block types for the game
    void Draw();                       // Method to draw the game state, including the grid and blocks
    void HandleInput();                // Method to handle the player input
    void MoveBlockLeft();              // Method to handle left movement
    void MoveBlockRight();             // Method to handle Right movement
    void MoveBlockDown();              // Method to handle Down movement
    Grid grid;                         // Grid object representing the game board
    bool gameOver;                     // Bool value to indicate game over status
    int score;

private:
    bool IsBlockOutside();                                  // Check if the block goes outside the border of the grid
    void RotateBlock();                                     // Method to rotate the Block
    void LockBlock();                                       // Method to Lock block sin place
    bool BlockFits();                                       // Method to check if the block fits in the position
    void Reset();                                           // Method to Reset the game board
    void UpdateScore(int linesCleared, int moveDownPoints); // Method to Update the score
    std::vector<Block> blocks;                              // Vector of all block types available in the game
    Block currentBlock;                                     // The block that is currently being controlled by the player
    Block nextBlock;                                        // The next block that will appear after the current block is placed
};
