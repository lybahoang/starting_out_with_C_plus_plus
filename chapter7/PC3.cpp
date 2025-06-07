/* --- Chips and Salsa ---
The program displays a report for sales of each salsa type,
total sales, and the names of the highest selling and lowest
selling products.
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void getSales(const string [], int [], int);
int calcTotalSales(int [], int);
string findHighestType(int [], const string [], int);
string findLowestType(int [], const string [], int);

int main()
{
    // Array declaration
    const int SIZE = 5;
    string salsaTypes[SIZE] = { "mild", "medium", "sweet", "hot", "zesty" }; // Array for the five salsa names
    int jarSales[SIZE]; // Array to hold the sale of each type of salsa

    // Prompt for the sales of each salsa type
    getSales(salsaTypes, jarSales, SIZE);

    // Display the total sale
    int totalSales = calcTotalSales(jarSales, SIZE);

    // Find the names of the best seller, and worst seller
    string bestSeller = findHighestType(jarSales, salsaTypes, SIZE);
    string worstSeller = findLowestType(jarSales, salsaTypes, SIZE);

    // Display the report
    cout << "\n--- Chips and Salsa Report ---\n";
    cout << "\tType\tSales\n";
    for (int type = 0; type < SIZE; type++)
    {
        cout << "\t" << salsaTypes[type] << "\t" << jarSales[type];
        cout << endl;
    }
    cout << "--------------------------------\n";
    cout << "Total sales: " << totalSales << endl;
    cout << "Highest selling product: " << bestSeller << endl;
    cout << "Lowest selling product: " << worstSeller << endl;

    return 0;
}

/* ===> Function getSales Definition <===
The function prompts for the number of jars sold of each salsa type
during the past month and store it into the jarSales array
*/
void getSales(const string names[], int sales[], int size)
{
    // Prompt for the sales
    for (int index = 0; index < size; index++)
    {
        do
        {
            cout << "Enter the number of jars of " << names[index] << " salsa sold: ";
            cin >> sales[index];
            if (sales[index] < 0)
            {
                cout << "Invalid value. Enter a non-negative number. Enter again.\n\n";
            }
        } while (sales[index] < 0);
    }
}

/* ===> Function calcTotalSales Definition <===
The function calculates and returns the total number of
jars sold of salsa types during the past month.
*/
int calcTotalSales(int sales[], int size)
{
    int total = 0;

    for (int type = 0; type < size; type++)
    {
        total += sales[type];
    }

    return total;
}

/* ===> Function findHighestSales Definition <===
The function finds and returns the name of the salsa type that
has the highest number of sales.
*/
string findHighestType(int saleFigures[], const string names[], int SIZE)
{
    int highestSale = saleFigures[0];
    string highestType = names[0];

    for (int index = 1; index < SIZE; index++)
    {
        if (saleFigures[index] > highestSale)
        {
            highestSale = saleFigures[index];
            highestType = names[index];
        }
    }

    return highestType;
}

/* ===> Function findLowestSales Definition <===
The function finds and returns the name of the salsa type that
has the lowest number of sales.
*/
string findLowestType(int saleFigures[], const string names[], int SIZE)
{
    int lowestSale = saleFigures[0];
    string lowestType = names[0];

    for (int index = 1; index < SIZE; index++)
    {
        if (saleFigures[index] < lowestSale)
        {
            lowestSale = saleFigures[index];
            lowestType = names[index];
        }
    }

    return lowestType;
}
