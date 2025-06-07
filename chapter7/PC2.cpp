/* --- Rainfall Statistics ---
The program calculates and displays the total rainfall for
the year, the average monthly rainfall, and the months with
the highest and lowest amounts.
*/

#include <iostream>
using namespace std;

// Function prototypes
void getRainfall(double [], int);
void processData(double [], int);

// The main Function
int main()
{
    // Array declaration
    const int SIZE = 12;
    double rainfall[SIZE];

    // Prompt for the rainfall of each month
    getRainfall(rainfall, SIZE);

    // Calculate the total rainfall
    processData(rainfall, SIZE);

    return 0;
}

/* Function getRainfall Definition
The function prompts for the rainfall amount of 12 months
*/
void getRainfall(double rainfallArray[], int size)
{
    for (int month = 1; month <= size; month++)
    {
        do
        {
            cout << "Enter the rainfall amount of month " << month << ": ";
            cin >> rainfallArray[month - 1];
            if (rainfallArray[month - 1] < 0)
            {
                cout << "Invalid value. Enter a positive value.\n\n";
            }
        } while (rainfallArray[month - 1] < 0);
    }
}

/* Function processData Definition
The function calculates and displays the total rainfall for
the year, the average monthly rainfall, and the months with
the highest and lowest amounts.
*/
void processData(double rainfallArray[], int size)
{
    // Variable declaration
    double averageRainfall,
           lowest = rainfallArray[0],
           highest = rainfallArray[0];

    int lowestMonth = 1,
        highestMonth = 1;

    // Accumulator
    double totalRainfall = 0;

    for (int month = 1; month <= size; month++)
    {
        totalRainfall += rainfallArray[month - 1];
        if (rainfallArray[month - 1] < lowest)
        {
            lowest = rainfallArray[month - 1];
            lowestMonth = month;
        }
        if (rainfallArray[month - 1] > highest)
        {
            highest = rainfallArray[month - 1];
            highestMonth = month;
        }
    }

    // Calculate the average rainfall
    averageRainfall = totalRainfall / size;

    // Display results
    cout << "\nTotal rainfall: " << totalRainfall << endl;
    cout << "Average monthly rainfall: " << averageRainfall << endl;
    cout << "Month with the lowest rainfall: Month " << lowestMonth << " with " << lowest << endl;
    cout << "Month with the highest rainfall: Month " << highestMonth << " with " << highest << endl;
}
