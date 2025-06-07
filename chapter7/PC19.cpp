/* --- 2D Array Operations --- */

#include <iostream>
using namespace std;

// Global constants
const int COLS = 5;  // Number of columns in each array
const int ROWS = 7;  // Number of rows in in each array

// Function prototypes
double getTotal(const double arr[][COLS]);
double getAverage(const double arr[][COLS]);
double getRowTotal(const double arr[][COLS], int row);
double getColumnTotal(const double arr[][COLS], int col);
double getHighestInRow(const double arr[][COLS], int row);
double getLowestInRow(const double arr[][COLS], int col);
void displayArray(const double arr[][COLS]);

// The main Function
int main()
{
    // First test array declaration
    double array1[ROWS][COLS] = { {1, 2, 3, 4, 5},
                                  {5, 6, 7, 8, 9},
                                  {0, 2, 4, 6, 8},
                                  {1, 3, 5, 7, 9},
                                  {2, 5, 9, 0, 15},
                                  {2.5, 9, 3.8, 5.1, 27},
                                  {25, 77, 45, 16, 19} };
    // Display the array 1
    displayArray(array1);

    // Display the total of the array
    cout << "\nTotal of Array: " << getTotal(array1) << endl;

    // Display the Average of the array
    cout << "Average of Array: " << getAverage(array1) << endl;

    // Display a specified row total
    cout << "Total of row 3: " << getRowTotal(array1, 3) << endl;

    // Display a specified column total
    cout << "Total of column 2: " << getColumnTotal(array1, 2) << endl;

    // Display the highest number in row 6
    cout << "Highest in row 6: " << getHighestInRow(array1, 6) << endl;

    // Display the lowest number in row 6
    cout << "Highest in row 7: " << getLowestInRow(array1, 7) << endl;


    cout << endl;
    // Second test array declaration
    double array2[ROWS][COLS] = { {8, 2, 10, 4, 5},
                                  {5, 19, 7, 21, 9},
                                  {30, 2, 4, 6, 8},
                                  {1, 3.3, 5, 7, 9},
                                  {2.3, 5, 9, 40, 15},
                                  {2.5, 9, 8.3, 1.5, 2.7},
                                  {30, 68, 45, 61, 25} };
    // Display the array 2
    displayArray(array2);

    // Display the total of the array
    cout << "\nTotal of Array: " << getTotal(array2) << endl;

    // Display the Average of the array
    cout << "Average of Array: " << getAverage(array2) << endl;

    // Display a specified row total
    cout << "Total of row 3: " << getRowTotal(array2, 3) << endl;

    // Display a specified column total
    cout << "Total of column 2: " << getColumnTotal(array2, 2) << endl;

    // Display the highest number in row 6
    cout << "Highest in row 6: " << getHighestInRow(array2, 6) << endl;

    // Display the lowest number in row 6
    cout << "Highest in row 7: " << getLowestInRow(array2, 7) << endl;

    return 0;
}

/* --- Function displayArray Definition ---
This function displays contents of an array to the screen.
*/
void displayArray(const double arr[][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

/* --- Function getTotal Definition ---
This function should accept a two-dimensional array as its argument and
return the total of all the values in the array.
*/
double getTotal(const double arr[][COLS])
{
    double total = 0;

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            total += arr[row][col];
        }
    }

    return total;
}

/* --- Function getAverage Definition ---
This function should accept a two-dimensional array as its argument
and return the average of all the values in the array.
*/
double getAverage(const double arr[][COLS])
{
    double total = 0;
    int totalElements = 0;

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            totalElements++;
            total += arr[row][col];
        }
    }

    return (total / totalElements);
}

/* --- Function getRowTotal Definition ---
This function should accept a two-dimensional array as its first argument and
an integer as its second argument. The second argument should be the subscript
of a row in the array. The function should return the total of the values in the
specified row.
*/
double getRowTotal(const double arr[][COLS], int row)
{
    double rowTotal = 0;

    for (int col = 0; col < COLS; col++)
    {
        rowTotal += arr[(row-1)][col];
    }

    return rowTotal;
}

/* --- Function getColumnTotal Definition ---
This function should accept a two-dimensional array as its first
argument and an integer as its second argument. The second argument should be the
subscript of a column in the array. The function should return the total of the values
in the specified column.
*/
double getColumnTotal(const double arr[][COLS], int col)
{
    double colTotal = 0;

    for (int row = 0; row < ROWS; row++)
    {
        colTotal += arr[row][col - 1];
    }

    return colTotal;
}

/* --- Function getHighestInRow Definition ---
This function should accept a two-dimensional array as its first
argument and an integer as its second argument. The second argument should be the
subscript of a row in the array. The function should return the highest value in the
specified row of the array.
*/
double getHighestInRow(const double arr[][COLS], int row)
{
    double highest = arr[(row-1)][0];

    for (int col = 1; col < COLS; col++)
    {
        if (arr[(row-1)][col] > highest)
        {
            highest = arr[(row-1)][col];
        }
    }

    return highest;
}

/* --- Function getLowestInRow Definition ---
This function should accept a two-dimensional array as its first
argument and an integer as its second argument. The second argument should be the
subscript of a row in the array. The function should return the lowest value in the
specified row of the array.
*/
double getLowestInRow(const double arr[][COLS], int row)
{
    double lowest = arr[(row-1)][0];

    for (int col = 1; col < COLS; col++)
    {
        if (arr[(row-1)][col] < lowest)
        {
            lowest = arr[(row-1)][col];
        }
    }

    return lowest;
}
