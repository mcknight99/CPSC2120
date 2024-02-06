/*
 * Name: Sam Pupke
 * Date Submitted: 12 Feb 2024
 * Lab Section: 001
 * Assignment Name: Lab 3: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Implement the (parameterized) constructor and findGroup functions below

/// @brief Parameterized constructor for Grouping
/// @param fileName text file to be opened and grouped
Grouping::Grouping(string fileName)
{
    int GRID_SIZE = 10; // because we can't modify the class
    // Initialize the grid with zeros
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            grid[i][j] = 0;
        }
    }

    // Read the file and populate the grid
    ifstream inputFile(fileName);
    if (inputFile.is_open())
    {
        for (int i = 0; i < GRID_SIZE; ++i)
        {
            string line;
            getline(inputFile, line);

            // Convert '.' to 0, any other character to 1
            for (int j = 0; j < GRID_SIZE; ++j)
            {
                grid[i][j] = (line[j] == '.') ? 0 : 1;
            }
        }
        inputFile.close();
    }

    // Process the grid to find groups
    findGroups(GRID_SIZE, GRID_SIZE);
}

void Grouping::findGroup(int row, int col, vector<GridSquare> &currentGroup)
{
    int GRID_SIZE = 10; // because we can't modify the class
    // Check if the current position is within bounds and represents an occupied square
    if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE && grid[row][col] == 1)
    {
        // Mark the current square as visited
        grid[row][col] = 0;

        // Add the current square to the current group
        currentGroup.push_back(GridSquare(row, col));

        // Recursively explore adjacent squares
        findGroup(row + 1, col, currentGroup); // Down
        findGroup(row - 1, col, currentGroup); // Up
        findGroup(row, col + 1, currentGroup); // Right
        findGroup(row, col - 1, currentGroup); // Left
    }
}

void Grouping::findGroups(int row, int col)
{
    int GRID_SIZE = 10;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (grid[i][j] == 1)
            {
                // If the current square is occupied and not part of any group, start a new group
                vector<GridSquare> currentGroup;
                findGroup(i, j, currentGroup);

                // Add the current group to the vector of groups
                groups.push_back(currentGroup);
            }
        }
    }
}

// Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} // Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

// Compare with == operator, used in test cases
bool GridSquare::operator==(const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() // return row value
{
    return row;
}

int GridSquare::getCol() // return column value
{
    return col;
}

// Output using << operator, used in Grouping::printGroups()
// Function definition for <ostream> << <GridSquare>
ostream &operator<<(ostream &os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{}, groups() {} // Default constructor, no groups

void Grouping::printGroups() // Displays grid's groups of squares
{
    for (size_t g = 0; g < groups.size(); g++) // original code came with int instead of size_t, I changed it to size_t to remove warnings
    {
        cout << "Group " << g + 1 << ": ";
        for (size_t s = 0; s < groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() // Needed in unit tests
{
    return groups;
}