/* --- Largest/Smallest Array Values ---
The program displays the largest and smallest values
in an array of 10 elements given by user.
*/

#include <iostream>
using namespace std;

// Function prototypes
void getElements(double [], int);
void findLargestSmallest(double [], int, double &, double &);

// The main Function
int main()
{
    // Constant for array size
    const int SIZE = 10;

    // Array declaration
    double number[SIZE];

    // Prompt for the values of the array
    getElements(number, SIZE);

    // Find and display the largest and smallest number
    double largestValue, smallestValue;
    findLargestSmallest(number, SIZE, largestValue, smallestValue);
    cout << "\nLargest Value: " << largestValue << endl;
    cout << "Smallest Value: " << smallestValue << endl;

    return 0;
}

/* *************************************************
 *         Function getElement Definition          *
 * The function prompts for 10 values in the array *
 * *************************************************/

void getElements(double nums[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << "Enter number #" << (index + 1) << ": ";
        cin >> nums[index];
    }
}

/* ***************************************************************
 *            Function findLargestSmallest Definition            *
 * The function finds and returns the largest and smallest value *
 * ***************************************************************/
void findLargestSmallest(double nums[], int size, double &largest, double &smallest)
{
    largest = smallest = nums[0];

    for (int index = 1; index < size; index++)
    {
        if (nums[index] > largest)
            largest = nums[index];
        if (nums[index] < smallest)
            smallest = nums[index];
    }
}
