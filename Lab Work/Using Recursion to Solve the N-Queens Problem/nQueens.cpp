/*
 * Name: Sam Pupke
 * Date Submitted: 15 April 2024
 * Lab Section: 001
 * Assignment Name: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;
// Function to check if it's safe to place a queen at position (row, col)
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check for queens in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check for queens in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check for queens in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to count how many solutions there are for placing n queens on an nxn chess board
int countSolutions(vector<vector<int>>& board, int row, int n) {
    // Base case: if all queens are placed successfully
    if (row == n) {
        return 1;
    }

    int count = 0;
    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            // Place the queen
            board[row][col] = 1;
            // Recur for the next row
            count += countSolutions(board, row + 1, n);
            // Backtrack and remove the queen
            board[row][col] = 0;
        }
    }

    return count;
}

// Function to count how many solutions there are for placing n queens on an nxn chess board
//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n) {
    // Initialize the chess board
    vector<vector<int>> board(n, vector<int>(n, 0));
    // Start with the first row
    return countSolutions(board, 0, n);
}

/*
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
*/