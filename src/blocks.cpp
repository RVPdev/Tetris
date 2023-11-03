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

        Move(0, 3);
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

        Move(0, 3);
    }
};

// Define a new class IBlock, inheriting from Block
class IBlock : public Block
{
public:
    // Constructor for the IBlock class
    IBlock()
    {
        id = 3; // Set the block ID to 1

        // Define the block cells for rotation state 0
        cells[0] = {Position(1, 0),
                    Position(1, 1),
                    Position(1, 2),
                    Position(1, 3)};

        // Define the block cells for rotation state 1
        cells[1] = {Position(0, 2),
                    Position(1, 2),
                    Position(2, 2),
                    Position(3, 2)};

        // Define the block cells for rotation state 2
        cells[2] = {Position(2, 0),
                    Position(2, 1),
                    Position(2, 2),
                    Position(2, 3)};

        // Define the block cells for rotation state 3
        cells[3] = {Position(0, 1),
                    Position(1, 1),
                    Position(2, 1),
                    Position(3, 1)};

        Move(-1, 3);
    }
};

// Define a new class OBlock, inheriting from Block
class OBlock : public Block
{
public:
    // Constructor for the OBlock class
    OBlock()
    {
        id = 4; // Set the block ID to 1

        // Define the block cells for rotation state 0
        cells[0] = {Position(0, 0),
                    Position(0, 1),
                    Position(1, 0),
                    Position(1, 1)};

        // // Define the block cells for rotation state 1
        // cells[1] = {Position(0, 0),
        //             Position(0, 1),
        //             Position(1, 0),
        //             Position(1, 1)};

        // // Define the block cells for rotation state 2
        // cells[2] = {Position(0, 0),
        //             Position(0, 1),
        //             Position(1, 0),
        //             Position(1, 1)};

        // // Define the block cells for rotation state 3
        // cells[3] = {Position(0, 0),
        //             Position(0, 1),
        //             Position(1, 0),
        //             Position(1, 1)};

        Move(0, 4);
    }
};

// Define a new class SBlock, inheriting from Block
class SBlock : public Block
{
public:
    // Constructor for the SBlock class
    SBlock()
    {
        id = 5; // Set the block ID to 1

        // Define the block cells for rotation state 0
        cells[0] = {Position(0, 1),
                    Position(0, 2),
                    Position(1, 0),
                    Position(1, 1)};

        // Define the block cells for rotation state 1
        cells[1] = {Position(0, 1),
                    Position(1, 1),
                    Position(1, 2),
                    Position(2, 2)};

        // Define the block cells for rotation state 2
        cells[2] = {Position(1, 1),
                    Position(1, 2),
                    Position(2, 0),
                    Position(2, 1)};

        // Define the block cells for rotation state 3
        cells[3] = {Position(0, 0),
                    Position(1, 0),
                    Position(1, 1),
                    Position(2, 1)};

        Move(0, 3);
    }
};

// Define a new class TBlock, inheriting from Block
class TBlock : public Block
{
public:
    // Constructor for the TBlock class
    TBlock()
    {
        id = 6; // Set the block ID to 1

        // Define the block cells for rotation state 0
        cells[0] = {Position(0, 1),
                    Position(1, 0),
                    Position(1, 1),
                    Position(1, 2)};

        // Define the block cells for rotation state 1
        cells[1] = {Position(0, 1),
                    Position(1, 1),
                    Position(1, 2),
                    Position(2, 1)};

        // Define the block cells for rotation state 2
        cells[2] = {Position(1, 0),
                    Position(1, 1),
                    Position(1, 2),
                    Position(2, 1)};

        // Define the block cells for rotation state 3
        cells[3] = {Position(0, 1),
                    Position(1, 0),
                    Position(1, 1),
                    Position(2, 1)};

        Move(0, 3);
    }
};

// Define a new class ZBlock, inheriting from Block
class ZBlock : public Block
{
public:
    // Constructor for the ZBlock class
    ZBlock()
    {
        id = 7; // Set the block ID to 1

        // Define the block cells for rotation state 0
        cells[0] = {Position(0, 0),
                    Position(0, 1),
                    Position(1, 1),
                    Position(1, 2)};

        // Define the block cells for rotation state 1
        cells[1] = {Position(0, 2),
                    Position(1, 1),
                    Position(1, 2),
                    Position(2, 1)};

        // Define the block cells for rotation state 2
        cells[2] = {Position(1, 0),
                    Position(1, 1),
                    Position(2, 1),
                    Position(2, 2)};

        // Define the block cells for rotation state 3
        cells[3] = {Position(0, 1),
                    Position(1, 0),
                    Position(1, 1),
                    Position(2, 0)};

        Move(0, 3);
    }
};
