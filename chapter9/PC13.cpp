// Page 545, Starting out with C++, 8th edition
// Program Challenge 13: Movie Statistics

#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
int *intArrayAllocator(int);                // Function returns pointer to an int array
double calcAverage(const int *const, int);  // Function returns the average number of movies
void getMovies(int *const, int);            // Function prompts for the number of movies
void arraySelectionSort(int *const, int);   // Function sorts the array of number of movies
double getMedian(const int *const, int);    // Function gets the median
int *getMode(const int arr[], int);         // Function gets the mode
void displayArray(const int *const, int);   // Function displays an array
void displayMode(const int *const);         // Function to displays the mode values

int main()
{
    // Variable declaration
    int numOfStudents;

    // A. Prompt for number of students
    do
    {
        cout << "Enter the number of students: ";
        cin >> numOfStudents;
        if (numOfStudents < 0)
        {
            cout << "ERROR: Enter a non-negative number. Try again.\n\n";
        }
    } while (numOfStudents < 0);

    // Dynamically allocate memory for the array of movies
    int *moviesPtr = intArrayAllocator(numOfStudents);

    // B. Get the number of movies
    getMovies(moviesPtr, numOfStudents);

    // C. Calculate and display the average, median, and mode
    double average = calcAverage(moviesPtr, numOfStudents);
    arraySelectionSort(moviesPtr, numOfStudents);
    double median = getMedian(moviesPtr, numOfStudents);
    int *modePtr = getMode(moviesPtr, numOfStudents);

    // Display result
    cout << "\nThe number of movies watched by students: ";
    displayArray(moviesPtr, numOfStudents);

    cout << "\nAverage: " << average << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: ";
    displayMode(modePtr);

    delete [] modePtr;
    delete [] moviesPtr;

    return 0;
}



// *******************************************
//    Function intArrayAllocator Definition  *
// *******************************************
// The function dynamically allocates an     *
// array with a specified number of elements *
// *******************************************
int *intArrayAllocator(int size)
{
    // Pointer variable declaration
    int *arrayPtr = nullptr;

    // Dynamically allocate memory for an array
    arrayPtr = new int[size];

    // Return the address of the array
    return arrayPtr;
}

// ********************************************
// Definition of function getMovies           *
// The function prompts for number of movies  *
// ********************************************
void getMovies(int *const arr, int size)
{
    for (int count = 0; count < size; count++)
    {
        do
        {
            cout << "Enter the number of movies watched by student " << (count + 1) << ": ";
            cin >> *(arr + count);
            if (*(arr + count) < 0)
            {
                cout << "ERROR: Enter a non-negative number. Try again.\n\n";
            }
        } while (*(arr + count) < 0);
    }
}

// ******************************************************
// Definition of function calcAverage                   *
// The function calculates the average number of movies *
// ******************************************************
double calcAverage(const int *const arrayPtr, int size)
{
    double total = 0;

    for (int index = 0; index < size; index++)
    {
        total = total + *(arrayPtr + index);
    }

    return (total / size);
}

// ****************************************************
// Definition of function getMedian                   *
// This function determines the median of an array    *
// ****************************************************
double getMedian(const int *const arr, int size)
{
    // If the array contains an even number of elements
    if (size % 2 == 0)
    {
        int middleIndex = (size / 2) - 1;

        return (*(arr + middleIndex) + *(arr + middleIndex + 1)) / static_cast<double>(2);
    }
    else
    {
        int middleIndex = (size / 2);

        return *(arr + middleIndex);
    }
}

// ****************************************************
// Definition of function arraySelectionSort          *
// This function sorts the array in ascending order   *
// ****************************************************
void arraySelectionSort(int *const arrayPtr, int size)
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

// ****************************************************
// Definition of function getMode                     *
// This function determines which value in the array  *
// occurs most often. If the array has no mode, the   *
// function returns -1.                               *
// ****************************************************
int *getMode(const int arr[], int size)
{
    vector<int> uniqueValues;             // A vector to hold unique values of the array
    bool isValueChecked;

    // Get the distinct values of the array and push it to the vector
    for (int index = 0; index < size; index++)
    {
        isValueChecked = false;

        // Check if the value is in the vector
        for (int count = 0; count < uniqueValues.size(); count++)
        {
            if (*(arr + index) == uniqueValues[count])
            {
                isValueChecked = true;
            }
        }

        // If the value is not in the vector
        if (!isValueChecked)
        {
            uniqueValues.push_back(*(arr + index));
        }
    }

    int frequencySize = uniqueValues.size();
    int frequencyArray[frequencySize];                  // An array to hold the frequency of values
    int *frequencyArrayPtr = frequencyArray;

    // Determine the frequency of each value
    for (int value : uniqueValues)
    {
        int frequency = 0;

        for (int index = 0; index < size; index++)
        {
            if (value == *(arr + index))
            {
                frequency += 1;
            }
        }
        *frequencyArrayPtr = frequency;
        frequencyArrayPtr++;
    }

    // Determine the largest frequency
    int largestFrequency = *frequencyArray;

    for (int index = 1; index < frequencySize; index++)
    {
        if (largestFrequency <= *(frequencyArray + index))
        {
            largestFrequency = *(frequencyArray + index);
        }
    }

    // Determine the mode value(s)
    int numOfModeValues = 0;

    if (largestFrequency == 1)
        numOfModeValues = -1;           // No mode if all values have frequency 1
    else
    {
        for (int count = 0; count < frequencySize; count++)
        {
            if (*(frequencyArray + count) == largestFrequency)
            {
                numOfModeValues++;
            }
        }
    }

    int *modeValuesPtr = nullptr;
    modeValuesPtr = new int[numOfModeValues + 1];   // +1 for storing the count of modes
    int *tempPtr = modeValuesPtr;

    *modeValuesPtr = numOfModeValues;
    modeValuesPtr++;            // Move to the next location for storing mode values

    for (int count = 0; count < frequencySize; count++)
    {
        if (*(frequencyArray + count) == largestFrequency)
        {
            *modeValuesPtr = uniqueValues[count];
            modeValuesPtr++;
        }
    }

    return tempPtr; // Return the pointer to the mode values
}

// ****************************************************
// Definition of function displayArray                *
// This function displays the content of an array     *
// ****************************************************
void displayArray(const int *const arrPtr, int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << *(arrPtr + count);
        if (count < size - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ".";
        }
    }
}

void displayMode(const int *const modeValuesPtr)
{
    if (*modeValuesPtr == -1)
    {
        cout << *modeValuesPtr << endl;
    }
    else
    {
        for (int count = 0; count < *modeValuesPtr; count++)
        {
            cout << *(modeValuesPtr + count + 1);
            if (count + 1 < *modeValuesPtr)
            {
                cout << ", ";
            }
        }
    }
}
