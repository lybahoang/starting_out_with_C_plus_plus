// Starting out with C++, 8th edition, page 545
// Program Challenge 8: Mode Function

#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
int *getMode(const int [], int);            // Function returns a pointer to int
void displayMode(const int *const);         // Function to displays the mode values

int main()
{
    const int SIZE = 15;
    int array1[SIZE] = { 1, 2, 3, 3, 5,
                          6, 1, 8, 3, 10,
                          1, 1, 3, 1, 15};

    int *modeValuesPtr = getMode(array1, SIZE);

    cout << "Mode value(s) of array1: ";
    displayMode(modeValuesPtr);

    delete [] modeValuesPtr;

    int array2[SIZE] = {  5, 100, 5, 25, 10,
                          5, 25, 5, 10, 100,
                          10, 15, 10, 5, 10 };

    modeValuesPtr = getMode(array2, SIZE);

    cout << "Mode value(s) of array2: ";
    displayMode(modeValuesPtr);

    delete [] modeValuesPtr;

    return 0;
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
            else
            {
                cout << "." << endl;
            }
        }
    }
}
