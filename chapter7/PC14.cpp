/* --- Lottery Application ---
The program simulates a lottery. It creates an array of
five random digits, and get user's five digits. The program
then displays the number of matching digits.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global constant
const int SIZE = 5;
const int MIN_DIGIT = 0,
          MAX_DIGIT = 9;

// Function prototypes
void randomizeLottery(int lottery[], int size);
void getLottery(int user[], int size);
int getMatchingDigits(const int lottery[], const int user[], int size);

// The main Function
int main()
{
    // Array declaration
    const int SIZE = 5;
    int lottery[SIZE];
    int user[SIZE];

    // Create a random lottery
    randomizeLottery(lottery, SIZE);

    // Get the user's lottery ticket
    getLottery(user, SIZE);

    // Count how many matching digits
    int numMatchingDigits = getMatchingDigits(lottery, user, SIZE);

    // Display the results
    cout << "\nLottery digits: ";
    for (int digit = 0; digit < SIZE; digit++)
    {
        cout << lottery[digit] << " ";
    }
    cout << "\nNumber of matching digits: " << numMatchingDigits << endl;
    if (numMatchingDigits == SIZE)
    {
        cout << "You award a grand prize winner.\n";
    }

    return 0;
}

/* --- Function randomizeLottery Definition ---
The function  generate a random number in the range of 0
through 9 for each element in the array.
*/
void randomizeLottery(int lottery[], int size)
{
    unsigned seed = time(0);
    srand(seed);

    for (int index = 0; index < size; index++)
    {
        lottery[index] = rand() % (MAX_DIGIT - MIN_DIGIT + 1) + MIN_DIGIT;
    }
}

/* --- Function getLotter Definition ---
The function prompts for 5 digits of user's lottery ticket
*/
void getLottery(int user[], int size)
{
    for (int index = 0; index < size; index++)
    {
        do
        {
            cout << "Enter the digit " << (index + 1) << ": ";
            cin >> user[index];
            if (user[index] < 0 || user[index] > 9)
            {
                cout << "Invalid digit. Enter again.\n\n";
            }
        } while (user[index] < 0 || user[index] > 9);
    }
}

/* --- Function getMatchingDigits Definition ---
The function determines the number of matching digits between the
lottery and the user's lottery, and returns it.
*/
int getMatchingDigits(const int lottery[], const int user[], int size)
{
    int numMatchingDigits = 0;

    for (int index = 0; index < size; index++)
    {
        if (lottery[index] == user[index])
        {
            numMatchingDigits++;
        }
    }

    return numMatchingDigits;
}
