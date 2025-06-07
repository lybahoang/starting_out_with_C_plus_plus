#include <iostream>
using namespace std;

// Function prototypes
int *calcTotal(int, int);   // Function returns a pointer to an int

int main()
{
    int *ptrTotal = nullptr;
    int num1 = 25, num2 = 9;

    ptrTotal = calcTotal(num1, num2);

    cout << "Sum of " << num1 << " and " << num2 << " is " << *ptrTotal << endl;

    delete ptrTotal;

    return 0;
}

// Function return a pointer to a dynamically allocated chunk of memory
int *calcTotal(int num1, int num2)
{
    int *ptr = new int;
    *ptr = num1 + num2;

    return ptr;
}
