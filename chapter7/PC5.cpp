/* --- Monkey Business ---
The program calculates and displays the average amount of food
eaten per day by a family of monkeys, the least and the greatest amounts
of food eaten by any one monkey.
*/

#include <iostream>
using namespace std;

// Global constants
const int NUM_MONKEYS = 3;
const int NUM_DAYS = 5;

// Function prototypes
void getData(double foodAmount[][NUM_DAYS], int size);
double calcAverage(const double foodAmount[][NUM_DAYS], int size);
double findLeastAmount(const double foodAmount[][NUM_DAYS], int size);
double findGreatestAmount(const double foodAmount[][NUM_DAYS], int size);

// The main Function
int main()
{
    // Array declaration and initialization
    double foodAmount[NUM_MONKEYS][NUM_DAYS];

    // Start of the program
    cout << "--- Welcome to Monkey Business Program ---\n";
    cout << "Enter how many pounds of food eaten by each monkey for each day in 5 days.\n\n";

    // Get the amount of food for each monkey;
    getData(foodAmount, NUM_MONKEYS);

    // Calculate the average amount of food
    double averageAmount = calcAverage(foodAmount, NUM_MONKEYS);

    // Calculate the least amount of food
    double leastAmount = findLeastAmount(foodAmount, NUM_MONKEYS);

    // Calculate the greatest amount of food
    double greatestAmount = findGreatestAmount(foodAmount, NUM_MONKEYS);

    // Display results
    cout << "\n--- Report ---\n";
    cout << "Average food eaten per day by the family: " << averageAmount << " pounds.\n";
    cout << "Least amount of food eaten during the week by any one monkey: " << leastAmount << " pound(s).\n";
    cout << "Greatest amount of food eaten during the week by any one monkey: " << greatestAmount << " pound(s)";

    return 0;
}

/* ===> Function getData Definition <===
The function prompts for the amount of food eaten by
each monkey in each day.
*/
void getData(double foodAmount[][NUM_DAYS], int num_monkey)
{
    for (int monkey = 0; monkey < num_monkey; monkey++)
    {
        cout << "Monkey " << (monkey + 1) << endl;
        for (int day = 0; day < NUM_DAYS; day++)
        {
            do
            {
                cout << "Day " << (day + 1) << ": ";
                cin >> foodAmount[monkey][day];
                if (foodAmount[monkey][day] < 0)
                {
                    cout << "Invalid value. Enter a non-negative number.\nEnter again.\n\n";
                }
            } while (foodAmount[monkey][day] < 0);
        }

        cout << endl;
    }
}

/* ===> Function calcAverage Definition <===
The function calculates and returns the average amount of
food eaten per day by the whole family of monkeys.
*/
double calcAverage(const double foodAmount[][NUM_DAYS], int num_monkey)
{
    double totalAmount = 0.0;

    for (int monkey = 0; monkey < num_monkey; monkey++)
    {
        for (int day = 0; day < NUM_DAYS; day++)
        {
            totalAmount += foodAmount[monkey][day];
        }
    }

    return (totalAmount / NUM_DAYS);
}

/* ===> Function findLeastAmount Definition <===
The function determines and returns the least amount of
food eaten during the week by any one monkey.
*/
double findLeastAmount(const double foodAmount[][NUM_DAYS], int num_monkey)
{
    double leastAmount = foodAmount[0][0];

    for (int monkey = 0; monkey < num_monkey; monkey++)
    {
        for (int day = 0; day < NUM_DAYS; day++)
        {
            if (foodAmount[monkey][day] < leastAmount)
                leastAmount = foodAmount[monkey][day];
        }
    }

    return leastAmount;
}

/* ===> Function findGreatestAmount Definition <===
The function determines and returns the greates amount of
food eaten during the week by any one monkey.
*/
double findGreatestAmount(const double foodAmount[][NUM_DAYS], int num_monkey)
{
    double greatesAmount = foodAmount[0][0];

    for (int monkey = 0; monkey < num_monkey; monkey++)
    {
        for (int day = 0; day < NUM_DAYS; day++)
        {
            if (foodAmount[monkey][day] > greatesAmount)
                greatesAmount = foodAmount[monkey][day];
        }
    }

    return greatesAmount;
}
