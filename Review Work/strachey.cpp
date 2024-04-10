#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// To shuffle:
// https://en.wikipedia.org/wiki/Magic_square#Transformations_that_preserve_the_magic_property

// k is the safety precursor to making even sized magic squares.
// even square dimensions are determined by 4k+2
//@pre k >= 1
const unsigned long long k = 1;
// j is the safety precursor for stepping in a strachey alg square
//@pre j>=0
const unsigned long long j = 1;

// n is the safety precursor to making odd sized magic squares.
// odd square dimensions are determined by n
//@pre n >= 3 && n % 2 == 1
const unsigned long long n = 3;
// s is the safety precursor for odd sized magic square starting values
// any nonzero positive integer is allowed
//@pre s >= 1
const unsigned long long s = 1;
// d is the safety precursor for stepping in a siamese square
//@pre d>=0
const unsigned long long d = j;

// Function to print the magic square and its row, column, and diagonal sums
void printMagicSquare(const vector<vector<unsigned long long>> &magicSquare, unsigned long long size)
{
    vector<unsigned long long> rowSum(size, 0);
    vector<unsigned long long> colSum(size, 0);
    unsigned long long mainDiagSum = 0;
    unsigned long long antiDiagSum = 0;

    cout << "Magic Square:" << endl;
    for (unsigned long long i = 0; i < size; ++i)
    {
        for (unsigned long long j = 0; j < size; ++j)
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
    for (unsigned long long j = 0; j < size; ++j)
    {
        cout << "--------";
    }
    cout << endl;
    for (unsigned long long j = 0; j < size; ++j)
    {
        cout << colSum[j] << "\t";
    }
    cout << "\\" << mainDiagSum << " /" << antiDiagSum << endl;
}

// Function to generate Siamese magic square of odd order
vector<vector<unsigned long long>> generateSiameseMagicSquare(unsigned long long startNum, unsigned long long size, unsigned long long step)
{
    vector<vector<unsigned long long>> siameseMagicSquare(size, vector<unsigned long long>(size, 0));

    unsigned long long num = startNum;
    unsigned long long row = 0;
    unsigned long long col = size / 2;

    for (unsigned long long i = 0; i < size * size; ++i)
    {
        siameseMagicSquare[row][col] = num;

        // Move diagonally up and right
        unsigned long long nextRow = (row - 1 + size) % size;
        unsigned long long nextCol = (col + 1) % size;

        // Check if the next position is filled
        if (siameseMagicSquare[nextRow][nextCol] != 0)
        {
            // Move vertically down one box instead
            row = (row + 1) % size;
        }
        else
        {
            // Move diagonally up and right
            row = nextRow;
            col = nextCol;
        }
        // iterate forwards the step linearly
        num = num + step;
    }

    return siameseMagicSquare;
}

// Function to create the Strachey magic square
vector<vector<unsigned long long>> generateStracheyMagicSquare(unsigned long long size, unsigned long long step)
{
    // Step 1: Divide the grid into 4 quarters
    vector<vector<unsigned long long>> magicSquare(size, vector<unsigned long long>(size, 0));

    // Step 2: Create Siamese magic squares for each quarter
    vector<vector<unsigned long long>> subSquareA = generateSiameseMagicSquare(1, size / 2, step);
    vector<vector<unsigned long long>> subSquareB = generateSiameseMagicSquare(size * size / 4 + 1, size / 2, step);
    vector<vector<unsigned long long>> subSquareC = generateSiameseMagicSquare(size * size / 2 + 1, size / 2, step);
    vector<vector<unsigned long long>> subSquareD = generateSiameseMagicSquare(3 * size * size / 4 + 1, size / 2, step);

    // k is now equal to (size - 2) / 4
    // Step 3: Exchange the leftmost k columns in sub-square A with the corresponding columns of sub-square D.
    for (unsigned long long i = 0; i < size / 2; i++)
    {
        for (unsigned long long j = 0; j < (size - 2) / 4; j++)
        {
            swap(subSquareA[i][j], subSquareD[i][j]);
        }
    }

    // Step 4: Exchange the rightmost k - 1 columns in sub-square C with the corresponding columns of sub-square B.
    for (unsigned long long i = 0; i < size / 2; i++)
    {
        for (unsigned long long j = size / 2 - ((size - 2) / 4) + 1; j < size / 2; j++)
        {
            swap(subSquareB[i][j], subSquareC[i][j]);
        }
    }
    // Step 5: Exchange the middle cell of the leftmost column of sub-square A with the corresponding cell of sub-square D.
    swap(subSquareA[size / 4][0], subSquareD[size / 4][0]);
    // Exchange the central cell in sub-square A with the corresponding cell of sub-square D.
    swap(subSquareA[size / 4][size / 4], subSquareD[size / 4][size / 4]);

    // Combine the sub-squares into the final magic square
    for (unsigned long long i = 0; i < size / 2; ++i)
    {
        for (unsigned long long j = 0; j < size / 2; ++j)
        {
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

vector<vector<unsigned long long>> generateDoublyEvenMagicSquare(unsigned long long size)
{
    vector<vector<unsigned long long>> magicSquare(size, vector<unsigned long long>(size, 0));
    unsigned long long iterator = 1;
    for (unsigned long long i = 0; i < size; ++i)
    {
        for (unsigned long long j = 0; j < size; ++j, ++iterator)
        {
            magicSquare[i][j] = (((i + 1) / 2) + ((j + 1) / 2) + 1) % 2 == 1 ? iterator : (size * size) + 1 - iterator;
            /*
            if((((i+1)/2)+((j+1)/2)+1)%2==1) { //to see where this monstrosity comes from, check out dea.cpp
                magicSquare[i][j]=iterator;
            } else { //it would be silly to make this a ternary operator statement. oops my finger slipped.
                magicSquare[i][j]=(size*size)+1-iterator;
            }
            */
            // iterator++; //also works without this.  oops i did another silly and added the iterator in the magicsquare input
            // is there another linear iterator we can use such as step?
            // no, because it subtracts from n^2 and becomes negative.
            // could there be a max subtract instead to make a range?
            // purposefully keeping the dead code because A. its more readable and B. it will be easier to implement from for a step feature
        }
    }
    return magicSquare;
}

void writeMagicSquareToCSV(const std::vector<std::vector<unsigned long long>> &square, const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    unsigned long long n = square.size();
    for (unsigned long long i = 0; i < n; ++i)
    {
        unsigned long long rowSum = 0;
        for (unsigned long long j = 0; j < n; ++j)
        {
            rowSum += square[i][j];
            file << square[i][j] << ",";
        }
        file << "," << rowSum << std::endl;
    }

    for(unsigned long long j = 0; j<=n; j++) {
        file<<",";
    }
    file<<endl;

    for (unsigned long long j = 0; j < n; ++j)
    {
        unsigned long long colSum = 0;
        for (unsigned long long i = 0; i < n; ++i)
        {
            colSum += square[i][j];
        }
        file << colSum;
        file << ",";
    }

    unsigned long long diagonalSum = 0;
    unsigned long long antiDiagonalSum = 0;
    for (unsigned long long i = 0; i < n; ++i)
    {
        diagonalSum += square[i][i];
        antiDiagonalSum += square[i][n - i - 1];
    }
    file << ",\\" <<diagonalSum << " /" << antiDiagonalSum << std::endl;

    cout << "Written magic square to " << filename << endl;
    file.close();
}

int main()
{
    unsigned long long size = 0;
    cout << "What size magic square would you like?\n";
    cin >> size;

    vector<vector<unsigned long long>> magicSquare;
    if (size % 2 == 1)
    { // odd
        magicSquare = generateSiameseMagicSquare(s, size, d);
    }
    else if (size % 4 == 2 && size >= 6)
    { // singly even
        magicSquare = generateStracheyMagicSquare(size, j);
    }
    else
    { // doubly even
        magicSquare = generateDoublyEvenMagicSquare(size);
    }
    //printMagicSquare(magicSquare, size);
    writeMagicSquareToCSV(magicSquare, "test.csv");

    /*
        cout << "Strachey size: " << 4 * k + 2 << endl;
        vector<vector<unsigned long long>> magicSquare = generateStracheyMagicSquare((4 * k) + 2, j);
        vector<vector<unsigned long long>> magicSiamese = generateSiameseMagicSquare(s, n, d);

        cout << "The generated magic square:" << endl;
        printMagicSquare(magicSquare, (4 * k) + 2);

        cout << "The generated siamese square:" << endl;
        printMagicSquare(magicSiamese, n);
        */
    return 0;
}
