// Page 545, Starting out with C++, 8th edition
// Program Challenge 4: Test Scores #2
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
string *arrayAllocatorString(int);
double *arrayAllocatorDouble(int);
void getNameAndScore(string *, double *, int);
void nameScoreSelectionSort(string *const, double *const, int);
void displaySortedScores(const string *const, const double *const, int);
double calcAverageScore(const double *const, int);

int main()
{
    // Variables declaration
    int numOfTests;
    double *arrayScore = nullptr;                 // A pointer points to the address of the array of scores
    string *arrayName = nullptr;                  // A pointer points to the array of students' names

    // Prompt for the size of the array
    cout << "Enter number of tests: ";
    cin >> numOfTests;

    // Dynamically allocate memory for the arrays
    arrayScore = arrayAllocatorDouble(numOfTests);
    arrayName = arrayAllocatorString(numOfTests);

    // Get names and scores
    getNameAndScore(arrayName, arrayScore, numOfTests);

    // Sort the names and scores
    nameScoreSelectionSort(arrayName, arrayScore, numOfTests);

    // Display sorted names and scores
    displaySortedScores(arrayName, arrayScore, numOfTests);

    // Calculate average score
    double averageScore = calcAverageScore(arrayScore, numOfTests);
    cout << "\nAverage score: " << fixed << setprecision(2) << averageScore << endl;

    // Release dynamically allocated memory
    delete [] arrayScore;
    delete [] arrayName;

    return 0;
}

// *********************************************
//   Function arrayAllocatorDouble Definition  *
// *********************************************
// The function dynamically allocates a double *
// array with a specified number of elements   *
// and returns the pointer of this array       *
// *********************************************
double *arrayAllocatorDouble(int size)
{
    // Pointer variable declaration
    double *arrayScore = nullptr;

    // Dynamically allocate memory for an array
    arrayScore = new double[size];

    // Return the address of the array
    return arrayScore;
}

// *********************************************
//   Function arrayAllocatorString Definition  *
// *********************************************
// The function dynamically allocates a string *
// array with a specified number of elements   *
// and returns the pointer of this array       *
// *********************************************
string *arrayAllocatorString(int size)
{
    // Pointer variable declaration (Pointer to string array)
    string *arrayName = nullptr;

    // Dynamically allocate memory for an array
    arrayName = new string[size];

    // Return the address of the array
    return arrayName;
}

// *********************************************
//   Function getNameAndScore Definition       *
// *********************************************
// The function prompts for the test scores    *
// and the student's name                      *
// *********************************************
void getNameAndScore(string *arrayName, double *arrayScore, int size)
{
    for (int index = 0; index < size; index++)
    {
        // Get the name of student
        cout << "\nEnter the student's name taking the test " << (index + 1) << ": ";
        cin.ignore();
        getline(cin, *(arrayName + index));

        // Get the test scores
        do
        {
            cout << "Enter the test score of " << *(arrayName + index) << ": ";
            cin >> *(arrayScore + index);
            if (*(arrayScore + index) < 0)
            {
                cout << "ERROR: Test scores must be non-negative. Please try again.\n\n";
            }
        } while (*(arrayScore + index) < 0);
    }
}

// *********************************************
//  Function nameScoreSelectionSort Definition *
// *********************************************
// The function sorts the test scores in       *
// ascending order                             *
// *********************************************
void nameScoreSelectionSort(string *const arrayName, double *const arrayScore, int size)
{
    int start, minIndex;
    double minScore;
    string minName;

    for (start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minScore = *(arrayScore + start);
        minName = *(arrayName + start);
        for (int index = start + 1; index < size; index++)
        {
            if (*(arrayScore + index) < minScore)
            {
                minIndex = index;
                minScore = *(arrayScore + index);
                minName = *(arrayName + index);
            }
        }
        // Swap scores
        *(arrayScore + minIndex) = *(arrayScore + start);
        *(arrayScore + start) = minScore;
        // Swap names
        *(arrayName + minIndex) = *(arrayName + start);
        *(arrayName + start) = minName;
    }
}

// *********************************************
//    Function calcAverageScore Definition     *
// *********************************************
// The function calculates the average score   *
// *********************************************
double calcAverageScore(const double *const arrayScore, int size)
{
    double totalScore = 0;

    for (int index = 0; index < size; index++)
    {
        totalScore = totalScore + *(arrayScore + index);
    }

    return (totalScore / size);
}

// *********************************************
//    Function displaySortedScores Definition  *
// *********************************************
// The function display each student’s name    *
// along with his or her score.                *
// *********************************************
void displaySortedScores(const string *const arrayName, const double *const arrayScore, int size)
{
    cout << "\nSorted scores with names:\n";
    for (int index = 0; index < size; index++)
    {
        cout << left << setw(8) << *(arrayName + index) << *(arrayScore + index) << endl;
    }
}
