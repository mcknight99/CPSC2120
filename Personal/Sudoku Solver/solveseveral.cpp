#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a number at a given position
bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    // Check if the number is not already present in the current row, column, and 3x3 subgrid
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num || board[(row - (row % 3)) + (i / 3)][(col - (col % 3)) + (i % 3)] == num) {
            return false;
        }
    }
    return true;
}

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------\n";
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // Find an empty cell
            if (board[row][col] == 0) {
                // Try placing numbers 1-9
                for (int num = 1; num <= 9; ++num) {
                    // Check if it's safe to place 'num' at the current position
                    if (isSafe(board, row, col, num)) {
                        // Place the number
                        board[row][col] = num;
                        // Recursively solve the rest of the puzzle
                        if (solveSudoku(board)) {
                            // Print the solution
                            cout << "Solution:\n";
                            printBoard(board);
                            // Keep searching for more solutions
                        }
                        // Backtrack
                        board[row][col] = 0;
                    }
                }
                // If no number can be placed, return false - impossible case board
                // This is the effective base case that allows us to finally branch
                //      all the way back out of the solution recursion once there
                //      are no more solutions to be found anywhere
                return false;
            }
        }
    }
    // Return true if *a* solution was found recursively 
    return true; 
}


int main() {
    //vector<vector<int>> board = {
    //    {4,0,0,0,3,1,0,0,9},
    //    {3,2,0,0,0,5,6,0,8},
    //    {0,5,1,8,0,6,2,0,0},
    //    {8,0,0,5,0,0,1,9,0},
    //    {5,0,2,0,8,0,0,0,0},
    //    {1,6,0,3,2,9,5,0,7},
    //    {0,4,9,6,0,0,0,2,0},
    //    {2,1,8,0,5,0,0,0,4},
    //    {6,0,5,4,0,2,8,0,1}
    //};
    vector<vector<int>> board = {
        {1, 2, 3, 0, 0, 7, 0, 0, 8},
        {4, 5, 6, 1, 0, 0, 0, 0, 0},
        {7, 8, 9, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 2, 3, 4, 5, 0, 0},
        {6, 0, 0, 9, 1, 5, 0, 0, 0},
        {0, 0, 0, 8, 7, 6, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 3, 2, 1},
        {0, 0, 0, 0, 0, 0, 6, 5, 4},
        {0, 4, 0, 3, 0, 0, 9, 8, 7}
    };

    if (!solveSudoku(board)) {
        cout << "Out of solutions!\n";
    }
    //this method means that the original board remains unchanged after solving compared to the single solver
    cout << "Original board:\n";
    printBoard(board);

    return 0;
}
