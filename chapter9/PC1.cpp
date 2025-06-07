// Page 544, Starting out with C++, 8th edition
// Program Challenge 1: Array Allocator
#include <iostream>
using namespace std;

// Function prototypes
int *arrayAllocator(int);

int main()
{
    // Variables declaration
    int size, *arrayPtr;

    // Prompt for the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamical allocating memory for the array
    arrayPtr = arrayAllocator(size);

    cout << "The address of the array: " << arrayPtr << endl;

    // Release the allocated array
    delete [] arrayPtr;

    return 0;
}

// *******************************************
//    Function arrayAllocator Definition     *
// *******************************************
// The function dynamically allocates an     *
// array with a specified number of elements *
// *******************************************
int *arrayAllocator(int arrSize)
{
    // Pointer variable declaration
    int *arrayPtr = nullptr;

    // Dynamically allocate memory for an array
    arrayPtr = new int[arrSize];

    // Return the address of the array
    return arrayPtr;
}
