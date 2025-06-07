/* --- Larger than n ---
The program displays all numbers in an array that
are greater than the number n
*/

#include <iostream>
using namespace std;

// Function prototype
void displayLargerNumbers(const int arr[], int size, int n);

int main()
{
    // Array definition
    const int SIZE = 10;
    int numbers[SIZE] = { 2, 25, 9, 3, 7, 13, 18, 21, 43, 90 };

    // Prompt for the number n
    cout << "Enter a number: ";
    int n;
    cin >> n;

    // Display all numbers larger than n in the array
    displayLargerNumbers(numbers, SIZE, n);

    return 0;
}

/* ===> Function displayLargerNumbers Definition <===
The function display all numbers in the array that are
larger than the number n.
*/
void displayLargerNumbers(const int arr[], int size, int n)
{
    cout << "Numbers in the array that are larger than " << n << " are ";
    for (int number = 0; number < size; number++)
    {
        if (arr[number] > n)
        {
            cout << arr[number] << " ";
        }
    }
}
