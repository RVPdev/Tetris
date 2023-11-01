#pragma once // Makes sure this header file is included only once during compilation

// Defines the Position class to represent a grid position
class Position
{
public:
    Position(int row, int column); // Constructor that initializes the row and column
    int row;                       // Row position on the grid
    int column;                    // Column position on the grid
};
