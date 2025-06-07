// Page 545, Starting out with C++, 8th edition
// Program Challenge 5: Pointer Rewrite
#include <iostream>
using namespace std;

// Function prototypes
int doSomething(int *, int *);

int main()
{
    int x = 25, y = 9;
    int result = doSomething(&x, &y);

    cout << result << endl;

    return 0;
}

int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}
