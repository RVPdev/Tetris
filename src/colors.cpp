#include "colors.h"

// Define the colors for the cells
const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 18, 255};
const Color orange = {226, 116, 17, 255};
const Color yellow = {237, 234, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {13, 64, 213, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};

// GetCellColors returns a vector of Color objects that represent the different colors for the cells.
std::vector<Color>
GetCellColors()
{
    // Return a vector containing all the defined colors
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}