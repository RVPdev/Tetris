#include "block.h"    // Include the Block class header
#include "position.h" // Include the Position class header

// Define a new class LBlock, inheriting from Block
class LBlock : public Block
{
public:
    // Constructor for the LBlock class
    LBlock()
    {
        id = 1; // Set the block ID to 1

        // Define the block cells for rotation state 0
        cells[0] = {Position(0, 2),
                    Position(1, 0),
                    Position(1, 1),
                    Position(1, 2)};

        // Define the block cells for rotation state 1
        cells[1] = {Position(0, 1),
                    Position(1, 1),
                    Position(2, 1),
                    Position(2, 2)};

        // Define the block cells for rotation state 2
        cells[2] = {Position(1, 0),
                    Position(1, 1),
                    Position(1, 2),
                    Position(2, 0)};

        // Define the block cells for rotation state 3
        cells[3] = {Position(0, 0),
                    Position(0, 1),
                    Position(1, 1),
                    Position(2, 1)};
    }
};

// Define a new class JBlock, inheriting from Block
class JBlock : public Block
{
public:
    // Constructor for the JBlock class
    JBlock()
    {
        id = 2; // Set the block ID to 1

        // Define the block cells for rotation state 0
        cells[0] = {Position(0, 0),
                    Position(1, 0),
                    Position(1, 1),
                    Position(1, 2)};

        // Define the block cells for rotation state 1
        cells[1] = {Position(0, 1),
                    Position(0, 2),
                    Position(1, 1),
                    Position(2, 1)};

        // Define the block cells for rotation state 2
        cells[2] = {Position(1, 0),
                    Position(1, 1),
                    Position(1, 2),
                    Position(2, 2)};

        // Define the block cells for rotation state 3
        cells[3] = {Position(0, 1),
                    Position(1, 1),
                    Position(2, 0),
                    Position(2, 1)};
    }
};
