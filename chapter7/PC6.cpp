/* --- Rain or Shine ---
The program reads weather data in three-month summer season
(June, July, August) from a file, and then create a report that
displays the number of rainy, cloudy, sunny days.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Global constants for array
const int NUM_ROWS = 3,
          NUM_COLS = 30,
          JUNE = 0,
          JULY = 1,
          AUGUST = 2;

// Function prototypes
void readData(char weatherData[][NUM_COLS], int rows);
int getRainyDays(const char weatherData[][NUM_COLS], int rows, int month);
int getCloudyDays(const char weatherData[][NUM_COLS], int rows, int month);
int getSunnyDays(const char weatherData[][NUM_COLS], int rows, int month);
string getLargestRainyMonth(int, int, int);

// The main Function
int main()
{
    // Array declaration
    char weatherData[NUM_ROWS][NUM_COLS];
    // Variable declaration
    int numRainyDays, numCloudyDays, numSunnyDays;

    // Reading data into the array from the file RainOrShines.txt
    readData(weatherData, NUM_ROWS);

    // Count the number of rainy, cloudy, and sunny days for June
    int juneRainyDays = getRainyDays(weatherData, NUM_ROWS, JUNE);
    int juneCloudyDays = getCloudyDays(weatherData, NUM_ROWS, JUNE);
    int juneSunnyDays = getSunnyDays(weatherData, NUM_ROWS, JUNE);

    // Count the number of rainy, cloudy, and sunny days for July
    int julyRainyDays = getRainyDays(weatherData, NUM_ROWS, JULY);
    int julyCloudyDays = getCloudyDays(weatherData, NUM_ROWS, JULY);
    int julySunnyDays = getSunnyDays(weatherData, NUM_ROWS, JULY);

    // Count the number of rainy, cloudy, and sunny days for August
    int augustRainyDays = getRainyDays(weatherData, NUM_ROWS, AUGUST);
    int augustCloudyDays = getCloudyDays(weatherData, NUM_ROWS, AUGUST);
    int augustSunnyDays = getSunnyDays(weatherData, NUM_ROWS, AUGUST);

    // Totals
    int totalRainyDays = juneRainyDays + julyRainyDays + augustRainyDays;
    int totalCloudyDays = juneCloudyDays + julyCloudyDays + augustCloudyDays;
    int totalSunnyDays = juneSunnyDays + julySunnyDays + augustSunnyDays;

    // Display the report
    cout << "--- Rain or Shine Report ---\n\n";
    cout << left;
    cout << setw(8) << "" << setw(8) << "Rainy" << setw(8) << "Cloudy" << setw(8) << "Sunny";
    cout << "\n--------------------------------\n";
    cout << setw(8) << "June" << setw(8) << juneRainyDays << setw(8) << juneCloudyDays << setw(8) << juneSunnyDays << endl;
    cout << setw(8) << "July" << setw(8) << julyRainyDays << setw(8) << julyCloudyDays << setw(8) << julySunnyDays<< endl;
    cout << setw(8) << "August" << setw(8) << augustRainyDays << setw(8) << augustCloudyDays << setw(8) << augustSunnyDays << endl;
    cout << "--------------------------------\n";
    cout << setw(8) << "Total" << setw(8) << totalRainyDays << setw(8) << totalCloudyDays << setw(8) << totalSunnyDays << endl;
    cout << "The month that has the largest number of rainy days is: " << getLargestRainyMonth(juneRainyDays, julyRainyDays, augustRainyDays) << endl;

    return 0;
}

/* ===> Function readData Definition <===
The function reads weather data from the file RainOrShines.txt
into the array named weatherData.
*/
void readData(char weatherData[][NUM_COLS], int rows)
{
    // Declare an input file stream object
    ifstream inputFile;

    // Open the file
    inputFile.open("RainOrShines.txt");

    // Check if the file is successfully opened or not
    if (inputFile.fail())
    {
        cout << "Error: Could not open the file 'RainOrShines.txt'." << endl;
    }
    else
    {
        // Read weather data from the file into the array
        char data;

        for (int row = 0; row < NUM_ROWS; row++)
        {
            int col = 0;

            while (col < NUM_COLS && inputFile >> data)
            {
                weatherData[row][col] = data;
                col++;
            }
        }
    }
}

/*===> Function getRainyDays Function <===
The function counts the number of rainy days in each month
*/
int getRainyDays(const char weatherData[][NUM_COLS], int rows, int month)
{
    int numRainyDays = 0;

    for (int col = 0; col < NUM_COLS; col++)
    {
        if (weatherData[month][col] == 'R')
            numRainyDays++;
    }

    return numRainyDays;
}

/*===> Function getCloudyDays Function <===
The function counts the number of cloudy days in each month
*/
int getCloudyDays(const char weatherData[][NUM_COLS], int rows, int month)
{
    int numCloudyDays = 0;

    for (int col = 0; col < NUM_COLS; col++)
    {
        if (weatherData[month][col] == 'C')
            numCloudyDays++;
    }

    return numCloudyDays;
}

/*===> Function getSunnyDays Function <===
The function counts the number of sunny days in each month
*/
int getSunnyDays(const char weatherData[][NUM_COLS], int rows, int month)
{
    int numSunnyDays = 0;

    for (int col = 0; col < NUM_COLS; col++)
    {
        if (weatherData[month][col] == 'S')
            numSunnyDays++;
    }

    return numSunnyDays;
}

/*===> Function getLargestRainyMonth Function <===
The function determines and returns the month that has
the largest number of rainy days
*/
string getLargestRainyMonth(int juneRainyDays, int julyRainyDays, int augustRainyDays)
{
    if (juneRainyDays >= julyRainyDays && juneRainyDays >= augustRainyDays)
        return "June";
    else if (julyRainyDays >= augustRainyDays)
        return "July";
    else
        return "August";
}
