// Page 545, Starting out with C++, 8th edition
// Program Challenge 12: Element Shifter

#include <iostream>
using namespace std;

// Function prototypes
int *elementShifter(const int *const, int);       // Function returns the pointer to an array of ints
void displayArray(const int *const, int);

int main()
{
    const int SIZE = 8;

    int array1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // Shifting the array1
    int *shiftedArrayPtr = elementShifter(array1, SIZE);

    // Display array
    cout << "Original array: ";
    displayArray(array1, SIZE);
    cout << "Shifted array: ";
    displayArray(shiftedArrayPtr, SIZE + 1);

    delete [] shiftedArrayPtr;

    return 0;
}
// *******************************************
// Definition of function reverseArray       *
// This function makes a copy of an array in *
// which all elements are reversed           *
// *******************************************
int *elementShifter(const int *const arr, int size)
{
    int *shiftedArrayPtr = nullptr;
    int newSize = size + 1;

    // Dynamically allocate memory for the reversed array
    shiftedArrayPtr = new int[newSize];

    // Shifting the array
    for (int index = 0; index < newSize; index++)
    {
        if (index == 0)
            *(shiftedArrayPtr + index) = 0;
        else
            *(shiftedArrayPtr + index) = *(arr + index - 1);
    }

    return shiftedArrayPtr;
}

// ************************************************
// Definition of function displayArray            *
// This function displays the content of an array *
// ************************************************
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
    cout << endl;
}


