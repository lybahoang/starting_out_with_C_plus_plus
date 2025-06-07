/* --- Grade Book ---
The program calculates and displays five students'
average test score and letter grades based on the average.
*/

#include <iostream>
#include <string>
using namespace std;

// Global constants
const int NUM_STUDENTS = 5, NUM_TESTS = 4;
const double A_THRESHOLD = 90,
             B_THRESHOLD = 80,
             C_THRESHOLD = 70,
             D_THRESHOLD = 60;
const double MIN_SCORE = 0,
             MAX_SCORE = 100;

// Function Prototypes
void getStudentName(string studentName[], int size);
void getStudentScores(string studentName, double stuTest[], int numTests);
double calcAverageScore(const double stuTest[], int numTests);
void getLetterGrade(const double averageScore[], char grade[], int size);
void displayReport(const string studentName[], const double averageScore[], const char grades[], int numStudents);
// The main Function
int main()
{
    // Array declaration
    string studentName[NUM_STUDENTS];
    double stu1Test[NUM_TESTS],
           stu2Test[NUM_TESTS],
           stu3Test[NUM_TESTS],
           stu4Test[NUM_TESTS],
           stu5Test[NUM_TESTS];
    char grades[NUM_STUDENTS];
    double averageScore[NUM_STUDENTS];

    // Get the student name
    getStudentName(studentName, NUM_STUDENTS);

    // Get the first student scores
    getStudentScores(studentName[0], stu1Test, NUM_TESTS);
    // Get the second student scores
    getStudentScores(studentName[1], stu2Test, NUM_TESTS);
    // Get the third student scores
    getStudentScores(studentName[2], stu3Test, NUM_TESTS);
    // Get the fourth student scores
    getStudentScores(studentName[3], stu4Test, NUM_TESTS);
    // Get the fifth student scores
    getStudentScores(studentName[4], stu5Test, NUM_TESTS);


    // Calculate the average score of each student
    averageScore[0] = calcAverageScore(stu1Test, NUM_TESTS);
    averageScore[1] = calcAverageScore(stu2Test, NUM_TESTS);
    averageScore[2] = calcAverageScore(stu3Test, NUM_TESTS);
    averageScore[3] = calcAverageScore(stu4Test, NUM_TESTS);
    averageScore[4] = calcAverageScore(stu5Test, NUM_TESTS);

    // Convert into letter grade
    getLetterGrade(averageScore, grades, NUM_STUDENTS);

    // Display report
    displayReport(studentName, averageScore, grades, NUM_STUDENTS);

    return 0;
}


/*  --- Function getStudentName Definition ---
The function prompts for the student's name and store them into an array
*/
void getStudentName(string stuName[], int numStu)
{
    for (int stu = 0; stu < numStu; stu++)
    {
        cout << "Name of Student " << (stu + 1) << ": ";
        getline(cin, stuName[stu]);
    }
}
/*  --- Function getStudentScores Definition ---
The function prompts for the student's scores for the 4
tests and store them into an array
*/
void getStudentScores(string stuName, double stuTest[], int size)
{
    cout << "\nEnter scores of student: " << stuName << endl;
    for (int test = 0; test < NUM_TESTS; test++)
    {
        do
        {
           cout << "Score " << (test + 1) << ": ";
           cin >> stuTest[test];
           if (stuTest[test] < 0 || stuTest[test] > 100)
           {
               cout << "Invalid score. Enter again.\n\n";
           }
        } while (stuTest[test] < 0 || stuTest[test] > 100);
    }
}

/* --- Function calcAverageScore Definition ---
The function calculates and returns the average score
of a student
*/
double calcAverageScore(const double stuTest[], int numTests)
{
    double totalScore = 0;

    for (int test = 0; test < numTests; test++)
    {
        totalScore += stuTest[test];
    }

    return totalScore / numTests;
}

/* --- Function getLetterGrade() Definition ---
The function converts student average score in to letter grade
and stores it into an array
*/
void getLetterGrade(const double averageScore[], char grade[], int numStu)
{
    for (int stu = 0; stu < numStu; stu++)
    {
        if (averageScore[stu] >= A_THRESHOLD)
            grade[stu] = 'A';
        else if (averageScore[stu] >= B_THRESHOLD)
            grade[stu] = 'B';
        else if (averageScore[stu] >= C_THRESHOLD)
            grade[stu] = 'C';
        else if(averageScore[stu] >= D_THRESHOLD)
            grade[stu] = 'D';
        else
            grade[stu] = 'F';
    }
}

/* --- Function displayReport Definition ---
The function displays each student's average test score and
a letter grade based on the average.
*/
void displayReport(const string studentName[], const double averageScore[], const char grades[], int numStudents)
{
    cout << "\nName\tAverage Score\tGrade\n";
    for (int stu = 0; stu <numStudents; stu++)
    {
        cout << studentName[stu] << "\t" << averageScore[stu] << "\t\t" << grades[stu] << endl;
    }
}
