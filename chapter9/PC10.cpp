// Page 545, Starting out with C++, 8th edition
// Program Challenge 10: Reverse Array

#include <iostream>
using namespace std;

// Function prototypes
int *reverseArray(const int *const, int);       // Function returns the pointer to an array of ints
void displayArray(const int *const, int);

int main()
{
    const int SIZE = 8;

    int array1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // Reverse array1
    int *reversedArray1Ptr = reverseArray(array1, SIZE);

    // Display array
    cout << "Original array: ";
    displayArray(array1, SIZE);
    cout << "Reversed array: ";
    displayArray(reversedArray1Ptr, SIZE);

    delete [] reversedArray1Ptr;

    return 0;
}
// *******************************************
// Definition of function reverseArray       *
// This function makes a copy of an array in *
// which all elements are reversed           *
// *******************************************
int *reverseArray(const int *const arr, int size)
{
    int *reversedArrayPtr = nullptr;

    // Dynamically allocate memory for the reversed array
    reversedArrayPtr = new int[size];

    // Reverse the array
    for (int index = 0; index < size; index++)
    {
        *(reversedArrayPtr + index) = *(arr + size - 1 - index );
    }

    return reversedArrayPtr;
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
