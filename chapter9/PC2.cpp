// Page 544, Starting out with C++, 8th edition
// Program Challenge 2: Test Scores #1
#include <iostream>
using namespace std;

// Function prototypes
double *arrayAllocator(int);
void getScores(double *, int);
void scoreSelectionSort(double *const, int);
double calcAverageScore(double *const, int);

int main()
{
    // Variables declaration
    int numOfTests;
    double *arrayScore = nullptr;                 // A pointer points to the address of the array of scores

    // Prompt for the size of the array
    cout << "Enter number of tests: ";
    cin >> numOfTests;

    // Dynamical allocating memory for the array
    arrayScore = arrayAllocator(numOfTests);

    // Get scores
    getScores(arrayScore, numOfTests);

    // Sort the elements of the array of pointers
    scoreSelectionSort(arrayScore, numOfTests);

    // Calculate average score
    double averageScore = calcAverageScore(arrayScore, numOfTests);

    // Display results
    cout << "\nAscending score list: ";
    for (int index = 0; index < numOfTests; index++)
    {
        cout << arrayScore[index] << " ";
    }

    cout << "\nAverage score: " << averageScore << endl;

    // Release the allocated array
    delete [] arrayScore;
    arrayScore = nullptr;

    return 0;
}

// *******************************************
//    Function arrayAllocator Definition     *
// *******************************************
// The function dynamically allocates an     *
// array with a specified number of elements *
// *******************************************
double *arrayAllocator(int size)
{
    // Pointer variable declaration
    double *arrayScore = nullptr;

    // Dynamically allocate memory for an array
    arrayScore = new double[size];

    // Return the address of the array
    return arrayScore;
}

// *******************************************
//       Function getScores Definition       *
// *******************************************
// The function prompts for the test scores  *
// and stores them in an array               *
// *******************************************
void getScores(double *arrayScore, int size)
{
    for (int index = 0; index < size; index++)
    {
        do
        {
            cout << "Enter the test score " << (index + 1) << ": ";
            cin >> *(arrayScore + index);
            if (*(arrayScore + index) < 0)
            {
                cout << "ERROR: Invalid score. Enter again.\n\n";
            }
        } while (*(arrayScore + index) < 0);
    }
}

// *******************************************
//   Function scoreSelectionSort Definition  *
// *******************************************
// The function sorts the test scores in     *
// ascending order                           *
// *******************************************
void scoreSelectionSort(double *const arrayPtr, int size)
{
    int start, minIndex;
    double minScore;

    for (start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minScore = *(arrayPtr + start);
        for (int index = start + 1; index < size; index++)
        {
            if (*(arrayPtr + index) < minScore)
            {
                minIndex = index;
                minScore = *(arrayPtr + index);
            }
        }
        *(arrayPtr + minIndex) = *(arrayPtr + start);
        *(arrayPtr + start) = minScore;
    }
}

// *******************************************
//    Function calcAverageScore Definition   *
// *******************************************
// The function calculates the average score *
// *******************************************
double calcAverageScore(double *const arrayPtr, int size)
{
    double totalScore = 0;

    for (int index = 0; index < size; index++)
    {
        totalScore = totalScore + *(arrayPtr + index);
    }

    return (totalScore / size);
}
