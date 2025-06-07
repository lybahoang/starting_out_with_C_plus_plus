/* --- Lo Shu Magic Square ---
The program checks whether a 3x3 table of numbers
is a Lo Shu Magic Square or not.
*/

#include <iostream>
#include <vector>
using namespace std;

// Global constants
const int NUM_ROWS = 3, NUM_COLS = 3, SUM = 15;

// Function prototypes
void getNumber(int arr[][NUM_COLS], int rows);
bool checkRows(const int arr[][NUM_COLS], int rows);
bool checkColums(const int arr[][NUM_COLS], int rows);
bool checkDiagonal(const int arr[][NUM_COLS], int rows);

// The main Function
int main()
{
    // Array declaration
    int table[NUM_ROWS][NUM_COLS];

    // Prompt for the number in the table
    getNumber(table, NUM_ROWS);

    // Determine if the table is a Lo Shu magic table
    if (checkRows(table, NUM_ROWS) &&
        checkColums(table, NUM_ROWS) &&
        checkDiagonal(table, NUM_ROWS))
    {
        cout << "The table is a Lo Shu Magic Table.\n";
        cout << checkRows(table, NUM_ROWS) << endl;
        cout << checkColums(table, NUM_ROWS) << endl;
        cout << checkDiagonal(table, NUM_ROWS) << endl;
    }
    else
    {
        cout << "The table is not a Lo Shu Magic Table.\n";
        cout << checkRows(table, NUM_ROWS) << endl;
        cout << checkColums(table, NUM_ROWS) << endl;
        cout << checkDiagonal(table, NUM_ROWS) << endl;
    }

    return 0;
}

/* ===> Function getNumber Definition <===
The function prompts for numbers in the table
*/
void getNumber(int table[][NUM_COLS], int rows)
{
    for (int row = 0; row < NUM_ROWS; row++)
    {
        cout << "Row " << (row + 1) << endl;
        for (int col = 0; col < NUM_COLS; col++)
        {
            do
            {
                cout << "Enter number for column " << (col + 1) << ": ";
                cin >> table[row][col];
                if (table[row][col] > 9 || table[row][col] < 1)
                {
                    cout << "Invalid number. Enter a number 0 - 9.\n\n";
                }
            } while (table[row][col] > 9 || table[row][col] < 1);
        }
    }
}

/* ===> The checkRows Definition <==
The function checks if the sum of all rows of
the table equal to each other or not, and returns
true if they are equal, otherwise return false.
*/
bool checkRows(const int table[][NUM_COLS], int rows)
{
    bool areRowsValid = true;

    for (int row = 0; row < rows; row++)
    {
        int rowSum = 0;

        for (int col = 0; col < NUM_COLS; col++)
        {
            rowSum += table[row][col];
        }

        if (rowSum != SUM)
        {
            areRowsValid = false;
        }
    }

    return areRowsValid;
}

/* ===> The checkColumns Definition <==
The function checks if the sum of all columns of
the table equal to each other or not, and returns
true if they are equal, otherwise return false.
*/
bool checkColums(const int table[][NUM_COLS], int rows)
{
    bool areColsValid = true;

    for (int col = 0; col < NUM_COLS; col++)
    {
        int colSum = 0;

        for (int row = 0; row < rows; row++)
        {
            colSum += table[row][col];
        }

        if (colSum != SUM)
        {
            areColsValid = false;
        }
    }

    return areColsValid;
}

/* ===> The checkDiagonal Definition <==
The function checks if the sum of all diagonals of
the table equal to each other or not, and returns
true if they are equal, otherwise return false.
*/
bool checkDiagonal(const int table[][NUM_COLS], int rows)
{
    int diagonalSum1 = table[0][0] + table[1][1] + table[2][2];
    int diagonalSum2 = table[0][2] + table[1][1] + table[2][0];

    if (diagonalSum1 == diagonalSum2 && diagonalSum1 == SUM)
    {
        return true;
    }
    else
    {
        return false;
    }
}
