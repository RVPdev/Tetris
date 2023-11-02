#pragma once // Ensures this header file is included only once during compilation

#include <vector>     // Include the vector library for dynamic arrays
#include <map>        // Include the map library for key-value pairs
#include "position.h" // Include the Position class header
#include "colors.h"   // Include the Colors header for color definitions

// Define the Block class
class Block
{
public:                                         // Public members
    Block();                                    // Constructor for the Block class
    void Draw();                                // Method to draw the block
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    int id;                                     // Unique identifier for each block type
    std::map<int, std::vector<Position>> cells; // Map to hold block cells for each rotation state

private:                       // Private members
    int cellSize;              // Size of each cell in the block
    int rotationState;         // Current rotation state of the block
    std::vector<Color> colors; // Vector to hold the colors for the block
    int rowOffset;
    int columnOffset;
};
