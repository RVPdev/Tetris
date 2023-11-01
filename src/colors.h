#pragma once  // Ensures the header file is included only once in a compilation unit
#include <raylib.h>  // Include the raylib library for the Color type
#include <vector>  // Include the vector library for the std::vector type

// Declare external Color constants to be used across multiple files
extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;

// Function declaration for GetCellColors, which returns a vector of Color objects
std::vector<Color> GetCellColors();
