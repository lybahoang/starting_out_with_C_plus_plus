/* --- Driver's License Exam ---
The program is used by the local Driver's License Office to
grade the driver's license exam of 20 multiple choice answers.
*/

#include <iostream>
#include <vector>
using namespace std;

// Constants for answers' letters
const char A = 'A',
           B = 'B',
           C = 'C',
           D = 'D';


// Function prototypes
void getAnswers(char userAns[], int size);
int getWrongAns(const char userAns[], const char correctAns[], vector<int> &, int NUM_QUES);

// The main function
int main()
{
    // Constant for number of questions
    const int NUM_QUES = 20,
              PASS_GRADES = 15;

    // Array declaration and initialization
    char correctAns[NUM_QUES] = { A, D, B, B, C,
                                  B, A, B, C, D,
                                  A, C, D, B, D,
                                  C, C, A, D, B };
    char userAns[NUM_QUES];
    vector<int> wrongAns;

    // Get the answer from user
    getAnswers(userAns, NUM_QUES);

    // Get the number of wrong answers
    int numWrongAns = getWrongAns(userAns, correctAns, wrongAns, NUM_QUES);

    // Check if the candidate passes or fails
    int numCorectAns = NUM_QUES - numWrongAns;
    if (numCorectAns >= PASS_GRADES)
    {
        cout << "\nPASS!" << endl;
        cout << "The number of correct answers is " << numCorectAns << endl;
        cout << "The number of wrong answers is " << numWrongAns << endl;
        cout << "Wrong answer(s): ";
        for (int index = 0; index < wrongAns.size(); index++)
        {
            cout << wrongAns[index] << ", ";
        }
    }
    else
    {
        cout << "\nFAIL!" << endl;
        cout << "The number of correct answers is " << numCorectAns << endl;
        cout << "The number of wrong answers is " << numWrongAns << endl;
        cout << "Wrong answer(s): ";
        for (int index = 0; index < wrongAns.size(); index++)
        {
            cout << wrongAns[index] << ", ";
        }
    }

    return 0;
}

/* --- Function getAnswers Definition ---
The function prompts for the answers of 20 questions,
and store them into the "answers" array.
*/
void getAnswers(char userAns[], int NUM_QUES)
{
    cout << "Enter the answer for each question\n";
    for (int ans = 0; ans < NUM_QUES; ans++)
    {
        do
        {
            cout << "Question " << (ans + 1) << ": ";
            userAns[ans] = cin.get();
            cin.ignore();
            if (userAns[ans] != A && userAns[ans] != B && userAns[ans] != C && userAns[ans] != D)
            {
                cout << "Invalid answer. Enter A, B, C, or D. Enter again.\n\n";
            }
        } while (userAns[ans] != A && userAns[ans] != B && userAns[ans] != C && userAns[ans] != D);
    }
}

/* --- Function getWrongAns Definition ---
The function counts and returns the number of wrong answers,
and store wrong answers into the vector wrongAns.
*/
int getWrongAns(const char userAns[], const char correctAns[], vector<int> &wrongAns, int NUM_QUES)
{
    int numWrongAns = 0;

    // Comparing the user's answer with correct answers
    for (int ques = 0; ques < NUM_QUES; ques++)
    {
        if (userAns[ques] != correctAns[ques])
        {
            // Count the wrong answers
            numWrongAns++;

            // Store the wrong answers
            wrongAns.push_back(ques + 1);
        }
    }

    return numWrongAns;
}
