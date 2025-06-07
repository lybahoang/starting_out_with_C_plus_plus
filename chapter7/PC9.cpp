/* --- Payroll ---
The program calculates and displays the gross wage of
employees in a company.
*/

#include <iostream>
using namespace std;

// Global constant
const double MIN_PAY_RATE = 15.00;

// Function prototypes
void getData(const long empId[], int hours[], double payRate[], int size);
void calcWages(int hours[], double payRate[], double wages[], int size);
void displayWages(const long empId[], const double wages[], int size);

// The main Function
int main()
{
    // Array declaration and initialization
    const int SIZE = 7;
    long empId[SIZE] = { 5658845, 4520125, 7895122, 8777541,
                         8451277, 1302850, 7580489 };
    int hours[SIZE];
    double payRate[SIZE];
    double wages[SIZE];

    // Get hours and pay rate for each employee and
    // store them in "hours" and "payRate" arrays.
    getData(empId, hours, payRate, SIZE);

    // Calculate the gross wages for each employee
    // and store it into the "wages" array
    calcWages(hours, payRate, wages, SIZE);

    // Display the employee's ID and their gross wages
    displayWages(empId, wages, SIZE);

    return 0;
}

/* --- Function getData Definition ---
The function prompts for employee's hours and pay rate,
and store them into the "hours" and "payRate" arrays.
*/
void getData(const long empID[], int hours[], double payRate[], int size)
{
    for (int id = 0; id < size; id++)
    {
        cout << "Employee " << empID[id] << ":\n";
        // Get the worked hours and input validation
        do
        {
            cout << "Enter the worked hours: ";
            cin >> hours[id];
            if (hours[id] < 0)
            {
                cout << "Invalid value for hours. Enter again.\n\n";
            }
        } while (hours[id] < 0);
        // Get the pay rate and input validation
        do
        {
            cout << "Enter the pay rate: ";
            cin >> payRate[id];
            if (payRate[id] < MIN_PAY_RATE)
            {
                cout << "Invalid value for pay rate. Enter again.\n\n";
            }
        } while (payRate[id] < MIN_PAY_RATE);

        cout << endl;
    }
}

/* --- Function calcWages Definition ---
The function calculates the gross wages of each employee
and store it into the "wages" array.
*/
void calcWages(int hours[], double payRate[], double wages[], int size)
{
    for (int index = 0; index < size; index++)
    {
        wages[index] = hours[index] * payRate[index];
    }
}

/* --- Function displayWages Definition ---
The function displays the report that shows each
employees ID number and gross wages.
*/
void displayWages(const long empID[], const double wages[], int size)
{
    cout << "\n--- Gross Wages Report ---\n";
    cout << "Employee ID\tGross wages\n";
    for (int emp = 0; emp < size; emp++)
    {
        cout << empID[emp] << "\t\t$" << wages[emp] << endl;
    }
}
