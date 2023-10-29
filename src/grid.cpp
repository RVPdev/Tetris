#include <grid.h>
#include <iostream>

using namespace std;

Grid::Grid()
{
    numCols = 10;
    numRows = 20;
    cellSize = 30;
    Initialize();
}

void Grid::Initialize()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            cout << grid[row][column] << " ";
        }
        cout << endl;
    }
}