// Starting out with C++, 8th edition, page 545
// Program Challenge 9: Median Function

#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
double getMedian(const int *const, int);                  // Function returns a pointer to int
void arraySelectionSort(int *const, int);
void displayArray(const int *const, int);

int main()
{
    // Example 1:
    const int SIZE1 = 10;

    int array1[SIZE1] = {1, 4, 8, 20, 13,
                        0, 25, 9, 90, 3};

    // Display the original array
    cout << "Original array 1: ";
    displayArray(array1, SIZE1);

    // Sort the array in ascending order
    arraySelectionSort(array1, SIZE1);
    cout << "\nSorted array 1: ";
    displayArray(array1, SIZE1);

    // Get the median of the array1
    double median = getMedian(array1, SIZE1);

    cout << "\nMedian 1: " << median << endl;


    // Example 2:
    const int SIZE2 = 11;
    int array2[SIZE2] = {1, 4, 8, 20, 13,
                        0, 25, 9, 90, 3, 6};

    // Display the original array
    cout << "\nOriginal array 2: ";
    displayArray(array2, SIZE2);

    // Sort the array in ascending order
    arraySelectionSort(array2, SIZE2);
    cout << "\nSorted array 2: ";
    displayArray(array2, SIZE2);

    // Get the median if the array2
    median = getMedian(array2, SIZE2);
    cout << "\nMedian 2: " << median << endl;

    return 0;
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
