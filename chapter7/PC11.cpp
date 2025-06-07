/* --- Exam Grader ---
The program grades the exam of a student and displays
correct answers for each missed answers, the total number
of questions missed, the percentage of questions answered
correctly.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Constants for answers' choices
const char A = 'A',
           B = 'B',
           C = 'C',
           D = 'D';
const int NUM_COLS = 2;

// Function prototypes
void readFile(char arr[], int size, string);
void processAnswers(const char correctAns[], const char studentAns[], char missedAnsInfor[][NUM_COLS], int numQues, vector<int> &);
double gradingStudent(int, int);

// The main Function
int main()
{
    // Constant initialization
    const int NUM_QUES = 20;
    const double PASS_PERCENT = 70;

    // Variable declaration
    int totalMissedQues, totalCorrectAns;
    double grade;

    // Array declaration
    char correctAns[NUM_QUES];
    char studentAns[NUM_QUES];
    vector<int> missedAns;
    char missedAnsInfor[NUM_QUES][NUM_COLS];

    // Read correct answer into the correctAns array
    readFile(correctAns, NUM_QUES, "CorrectAnswers.txt");

    // Read student answers into the student Ans array
    readFile(studentAns, NUM_QUES, "StudentAnswers.txt");

    // Evaluating the student attempt
    processAnswers(correctAns, studentAns, missedAnsInfor, NUM_QUES, missedAns);
    totalMissedQues = missedAns.size();
    totalCorrectAns = NUM_QUES - totalMissedQues;
    grade = gradingStudent(totalCorrectAns, NUM_QUES);

    // Display report of student's exam:
    // Display the list of the missed questions
    cout << "--- Student's Result ---\n";
    cout << "Missed\tIncorrect Ans\tCorrect Ans\n";
    for (int ques = 0; ques < missedAns.size(); ques++)
    {
        cout << missedAns[ques] << "\t" << missedAnsInfor[ques][0] << "\t\t" << missedAnsInfor[ques][1] << endl;
    }
    // Grading the student exam
    cout << "\nTotal missed questions: " << totalMissedQues << endl;
    cout << "Correct Percentage: " << grade << endl;
    if (grade < PASS_PERCENT)
        cout << "Sorry, you fail!\n";
    else
        cout << "Congratulations! You pass.\n";

}

/* --- Function readFile Definition ---
This is a void function used to read answers from a file into the array
*/
void readFile(char arr[], int size, string fileName)
{
    // File stream object
    ifstream inputFile;

    // Open the file
    inputFile.open(fileName);

    // Read data
    if (inputFile.fail())
    {
        cout << "Error: Could not open the file CorrectAnswers.txt\n\n";
    }
    else
    {
        int index = 0;

        while (index < size && inputFile >> arr[index])
            index++;

        // Closing the file
        inputFile.close();
    }
}

/* --- Function processAns Definition ---
The function compares the student’s answers with correct answers, and calculates
the number of missed questions, stores the missed questions with its incorrect answers
and correct answer in a 2 dimensional arrays; and returns the number of missed questions.
*/
void processAnswers(const char correctAns[], const char studentAns[], char missedAnsInfor[][NUM_COLS], int numQues, vector<int> &missedAns)
{
    int row = 0;

    for (int ques = 0; ques < numQues; ques++)
    {
        if (studentAns[ques] != correctAns[ques])
        {
            missedAns.push_back(ques + 1);
            missedAnsInfor[row][0] = studentAns[ques];
            missedAnsInfor[row][1] = correctAns[ques];
            row++;
        }
    }
}

/* --- Function gradingStudent Definition ---
This function used to calculate and returns grade percentage
*/
double gradingStudent(int numCorrectAns, int totalQues)
{
    // Constant declaration
    const int HUNDRED = 100;

    // Calculate the grade
    return (static_cast<double>(numCorrectAns) / totalQues) * HUNDRED;
}
