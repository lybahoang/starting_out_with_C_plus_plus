// Page 545, Starting out with C++, 8th edition
// Program Challenge 11: Array Expander

#include <iostream>
using namespace std;

// Function prototypes
int *doubleSizeArray(const int *const, int);       // Function returns the pointer to an array of ints
void displayArray(const int *const, int);

int main()
{
    const int SIZE = 8;

    int array1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // Increase array1 twice
    int *doubleArray1Ptr = doubleSizeArray(array1, SIZE);

    // Display array
    cout << "Original array: ";
    displayArray(array1, SIZE);
    cout << "Doubled array: ";
    displayArray(doubleArray1Ptr, SIZE * 2);

    delete [] doubleArray1Ptr;

    return 0;
}
// *******************************************
// Definition of function reverseArray       *
// This function makes a copy of an array in *
// which all elements are reversed           *
// *******************************************
int *doubleSizeArray(const int *const arr, int size)
{
    int *doubledArrayPtr = nullptr;
    int newSize = size * 2;

    // Dynamically allocate memory for the reversed array
    doubledArrayPtr = new int[newSize];

    // Double the array
    for (int index = 0; index < newSize; index++)
    {
        if (index < size)
            *(doubledArrayPtr + index) = *(arr + index );
        else
            *(doubledArrayPtr + index) = 0;
    }

    return doubledArrayPtr;
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

