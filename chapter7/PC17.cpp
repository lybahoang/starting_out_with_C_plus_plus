/* --- Name search ---
The program determines if a boy's name, a girl's name is a popular name.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Global constant for user choices
const int BOY_NAME = 1,
          GIRL_NAME = 2,
          BOTH = 3,
          QUIT = 4;

// Function prototypes
void readData(string fileName, vector<string> &arr);
int getChoice();
string getBoyName();
string getGirlName();
void checkPopularName(vector<string> arr, string name);
void showMenu();

// The main Function
int main()
{
    // Vector declaration
    vector<string> popularBoyNames;
    vector<string> popularGirlNames;

    // Read the boy's names into array
    string boyNameFile = "BoyNames.txt";
    readData(boyNameFile, popularBoyNames);

    // Read the girl's names into array
    string girlNameFile = "GirlNames.txt";
    readData(girlNameFile, popularGirlNames);

    // Prompt for a choice
    showMenu();
    int userChoice = getChoice();

    while (userChoice != QUIT)
    {
        // Get the names from user
        if (userChoice == BOY_NAME)
        {
            string boyName = getBoyName();
            checkPopularName(popularBoyNames, boyName);
        }
        else if (userChoice == GIRL_NAME)
        {
            string girlName = getGirlName();
            checkPopularName(popularGirlNames, girlName);
        }
        else
        {
            string boyName = getBoyName();
            checkPopularName(popularBoyNames, boyName);

            string girlName = getGirlName();
            checkPopularName(popularGirlNames, girlName);
        }

        cout << endl;
        showMenu();
        userChoice = getChoice();
    }

    return 0;
}

/* --- Function readData Definition ---
The function reads names into an array
*/
void readData(string fileName, vector<string> &arr)
{
    // Open the file
    ifstream inputFile;
    inputFile.open(fileName);

    if (inputFile.fail())
    {
        cout << "Error: Could not open the file.\n";
    }
    else
    {
        string name;

        while (getline(inputFile, name))
        {
            arr.push_back(name);
        }

        // Closing the file
        inputFile.close();
    }
}

/* --- Function getChoice Definition --- */
int getChoice()
{
    // Get user's choice
    int userChoice;

    do
    {
        cout << "Enter your choice (0 - 4): ";
        cin >> userChoice;
        cin.ignore();

        if (userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid choice. Enter again.\n\n";
        }
    } while (userChoice < 1 || userChoice > 4);

    return userChoice;
}

/* --- Function getBoyName Definition ---
The function prompts for a boy name from user.
*/
string getBoyName()
{
    string boyName;

    cout << "Enter a boy name: ";
    getline(cin, boyName);

    return boyName;
}

/* --- Function getGirlName Definition ---
The function prompts for a girl name from user.
*/
string getGirlName()
{
    string girlName;

    cout << "Enter a girl name: ";
    getline(cin, girlName);

    return girlName;
}

/* --- Function showMenu Definition ---
The function displays the menu to get input from user
*/

void showMenu()
{
    cout << "Would you like to enter a boy's name, a girl's name, or both?\n";
    cout << "Press 1 for a boy's name.\n";
    cout << "Press 2 for a girl's name.\n";
    cout << "Press 3 for both.\n";
    cout << "Press 4 to quit the program.\n\n";
}

/* --- checkPopularName Definition ---
The function check if the name is popular or not,
and display result to the screen
*/
void checkPopularName(vector<string> popularNames, string name)
{
    for (int index = 0; index < popularNames.size(); index++)
    {
        if (name == popularNames[index])
        {
            cout << "The name " << name << " is popular.\n";
            return;
        }
    }
    cout << "The name " << name << " is not popular.\n";
}
