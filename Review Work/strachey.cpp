#include <iostream>
#include <vector>

using namespace std;

//To shuffle:
//https://en.wikipedia.org/wiki/Magic_square#Transformations_that_preserve_the_magic_property

//k is the safety precursor to making even sized magic squares. 
//even square dimensions are determined by 4k+2
//@pre k >= 1
const int k = 1;
//j is the safety precursor for stepping in a strachey alg square
//@pre j>=0
const int j = 1;

//n is the safety precursor to making odd sized magic squares.
//odd square dimensions are determined by n
//@pre n >= 3 && n % 2 == 1
const int n = 3;
//s is the safety precursor for odd sized magic square starting values
//any nonzero positive integer is allowed
//@pre s >= 1
const int s = 1;
//d is the safety precursor for stepping in a siamese square
//@pre d>=0
const int d = j;


// Function to print the magic square and its row, column, and diagonal sums
void printMagicSquare(const vector<vector<int>> &magicSquare, int size)
{
    vector<int> rowSum(size, 0);
    vector<int> colSum(size, 0);
    int mainDiagSum = 0;
    int antiDiagSum = 0;

    cout << "Magic Square:" << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << magicSquare[i][j] << "\t";
            rowSum[i] += magicSquare[i][j];
            colSum[j] += magicSquare[i][j];
            if (i == j)
            {
                mainDiagSum += magicSquare[i][j];
            }
            if (i + j == size - 1)
            {
                antiDiagSum += magicSquare[i][j];
            }
        }
        cout << "| " << rowSum[i] << endl;
    }

    // Print column sums
    for (int j = 0; j < size; ++j)
    {
        cout << "--------";
    }
    cout<<endl;
    for (int j = 0; j < size; ++j)
    {
        cout << colSum[j] << "\t";
    }
    cout << "\\"<<mainDiagSum<<" /"<<antiDiagSum<<endl;
}

//Function to generate the next value in a siamese square. 
//Output must return a nonzero, and reliant on @param num
int siameseSequence(int num, int step) {
    return num+step;
}

// Function to generate Siamese magic square of odd order
vector<vector<int>> generateSiameseMagicSquare(int startNum, int size, int step) {
    vector<vector<int>> siameseMagicSquare(size, vector<int>(size, 0));

    int num = startNum;
    int row = 0;
    int col = size / 2;

    for (int i = 0; i < size * size; ++i) {
        siameseMagicSquare[row][col] = num;

        // Move diagonally up and right
        int nextRow = (row - 1 + size) % size;
        int nextCol = (col + 1) % size;

        // Check if the next position is filled
        if (siameseMagicSquare[nextRow][nextCol] != 0) {
            // Move vertically down one box instead
            row = (row + 1) % size;
        } else {
            // Move diagonally up and right
            row = nextRow;
            col = nextCol;
        }

        num=siameseSequence(num, step);
    }

    return siameseMagicSquare;
}


// Function to create the Strachey magic square
vector<vector<int>> createStracheyMagicSquare(int size, int step)
{
    // Step 1: Divide the grid into 4 quarters
    vector<vector<int>> magicSquare(size, vector<int>(size, 0));

    // Step 2: Create Siamese magic squares for each quarter
    vector<vector<int>> subSquareA = generateSiameseMagicSquare(1, size/2, step);
    vector<vector<int>> subSquareB = generateSiameseMagicSquare(size * size / 4 + 1, size/2, step);
    vector<vector<int>> subSquareC = generateSiameseMagicSquare(size * size / 2 + 1, size/2, step);
    vector<vector<int>> subSquareD = generateSiameseMagicSquare(3 * size * size / 4 + 1, size/2, step);
    
    // k is now equal to (size - 2) / 4
    // Step 3: Exchange the leftmost k columns in sub-square A with the corresponding columns of sub-square D.
    for(int i = 0; i<size/2; i++) {
        for(int j = 0; j<(size - 2) / 4; j++) {
            swap(subSquareA[i][j],subSquareD[i][j]);
        }
    }

    // Step 4: Exchange the rightmost k - 1 columns in sub-square C with the corresponding columns of sub-square B.
    for(int i = 0; i<size/2; i++) {
        for(int j = size/2 - ((size - 2) / 4)+1; j<size/2; j++) {
            swap(subSquareB[i][j],subSquareC[i][j]);
        }
    }
    // Step 5: Exchange the middle cell of the leftmost column of sub-square A with the corresponding cell of sub-square D.
    swap(subSquareA[size / 4][0], subSquareD[size / 4][0]);
    // Exchange the central cell in sub-square A with the corresponding cell of sub-square D.
    swap(subSquareA[size / 4][size / 4], subSquareD[size / 4][size / 4]);
    
    // Combine the sub-squares into the final magic square
    for (int i = 0; i < size / 2; ++i) {
        for (int j = 0; j < size / 2; ++j) {
            // Sub-square A (top left)
            magicSquare[i][j] = subSquareA[i][j];
            // Sub-square B (bottom right)
            magicSquare[i + size / 2][j + size / 2] = subSquareB[i][j];
            // Sub-square C (top right)
            magicSquare[i][j + size / 2] = subSquareC[i][j];
            // Sub-square D (bottom left)
            magicSquare[i + size / 2][j] = subSquareD[i][j];
        }
    }

    return magicSquare;
}

int main()
{
    cout << "Strachey size: " << 4 * k + 2 << endl;
    vector<vector<int>> magicSquare = createStracheyMagicSquare((4 * k) + 2, j);
    vector<vector<int>> magicSiamese = generateSiameseMagicSquare(s, n, d);

    cout << "The generated magic square:" << endl;
    printMagicSquare(magicSquare, (4 * k) + 2);

    cout << "The generated siamese square:" << endl;
    printMagicSquare(magicSiamese, n);
    return 0;
}
