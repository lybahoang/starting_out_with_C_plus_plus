/* --- Number Analysis Program ---
The program reads data from a file whose name is specified by
user. The program displays the lowest number, highest number,
total of numbers, and average of numbers in the file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void readData(vector<double> &);
double findLowest(vector<double>);
double findHighest(vector<double>);
double calcTotal(vector<double>);

// The main Function
int main()
{
    // Vector declaration
    vector<double> numbers;

    // Read data into the vector numbers
    readData(numbers);

    // Find the lowest number
    double lowestNum = findLowest(numbers);

    // Find the highest number
    double highestNum = findHighest(numbers);

    // Calculate the total and the average of all numbers
    double total = calcTotal(numbers);
    double average = total / numbers.size();

    // Display results
    cout << "Lowest number: " << lowestNum << endl;
    cout << "Highest number: " << highestNum << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;

    return 0;
}

/* ===> Function readData Definition <===
The function reads numbers from a file into an array
*/
void readData(vector<double> &vect)
{
    string fileName;

    // Get the file name from user
    cout << "Enter a file name: ";
    cin >> fileName;

    // Read data into the array from the file
    ifstream inputFile;
    inputFile.open(fileName.c_str());

    double number;
    if (inputFile.fail())
    {
        cout << "Error: Could not open the file.\n";
    }
    else
    {
        while (inputFile >> number)
        {
            vect.push_back(number);
        }
    }

    // Close the file
    inputFile.close();
}

/* ===> Function findLowest Definition <===
The function determines and returns the lowest number
in the file.
*/
double findLowest(vector<double> vect)
{
    double lowest = vect[0];

    for (int index = 1; index < vect.size(); index++)
    {
        if (lowest > vect[index])
            lowest = vect[index];
    }

    return lowest;
}

/* ===> Function findHighest Definition <===
The function determines and returns the highest number
in the file.
*/
double findHighest(vector<double> vect)
{
    double highest = vect[0];

    for (int index = 1; index < vect.size(); index++)
    {
        if (highest < vect[index])
            highest = vect[index];
    }

    return highest;
}

/* ===> Function calcTotal Definition <===
The function calculates and returns the total of all
numbers in the file.
*/
double calcTotal(vector<double> vect)
{
    double total = 0;

    for (int index = 0; index < vect.size(); index++)
        total += vect[index];

    return total;
}
