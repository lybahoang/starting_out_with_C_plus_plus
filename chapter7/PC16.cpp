/* --- World Series Champions ---
The program displays the number of times a team has won
the World Series in the period from 1903 to 2012
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void displayTeams(string);
string getTeam();
int countWinTimes(vector<string>, string);
void readWinTeams(vector<string> &, string);

// The main Function
int main()
{
    // Vector declaration
    vector<string> winTeams;

    // Display the contents of the Teams.txt
    string fileName = "Teams.txt";
    displayTeams(fileName);

    // Prompt for the baseball team
    string team = getTeam();

    // Read data of win teams into the vector winTeams
    string winFiles = "WorldSeriesWinners.txt";
    readWinTeams(winTeams, winFiles);

    // Calculate the number of times the team has won
    int numWin = countWinTimes(winTeams, team);

    // Display results
    cout << team << " has won " << numWin << " times.\n";

    return 0;
}

/* --- Function displayTeams Definition ---
The function displays the contents of the file Teams.txt on the screen
*/
void displayTeams(string fileName)
{
    // Open the file
    ifstream inputFile;
    inputFile.open(fileName);

    string team;
    while (getline(inputFile, team))
    {
        cout << team << endl;
    }

    // Closing the file
    inputFile.close();
}

/* --- Function getTeam Definition ---
The function prompts for a team and return it
*/
string getTeam()
{
    string team;

    cout << "\nEnter a baseball team: ";
    getline(cin, team);

    return team;
}

/* --- Function readWinTeams Definition ---
The function reads the contents of the WorldSeriesWinners.txt
file into an array or vector.
*/
void readWinTeams(vector<string> &winTeams, string file)
{
    // Open the file
    ifstream inputFile;
    inputFile.open(file);

    string team;
    while (getline(inputFile, team))
    {
        winTeams.push_back(team);
    }

    // Closing the file
    inputFile.close();
}

/* --- Function countWinTimes Definition ---
The function counts and returns the number of times
a team has won the World Series
*/
int countWinTimes(vector<string> winTeams, string team)
{
    int numWin = 0;

    for (int year = 0; year < winTeams.size(); year++)
    {
        if (winTeams[year] == team)
        {
            numWin++;
        }
    }

    return numWin;
}
