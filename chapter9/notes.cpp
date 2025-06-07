#include <iostream>
using namespace std;
int main() {
    // The address operator (&) returns the memory
    // address of a variable.
    int var1 = 2005;
    cout << "Address of var1: " << &var1 << endl;

    // Pointers are special variables to hold memory
    // address
    // Pointer variable, can point to an int
    int *ptr = nullptr;
    ptr = &var1;
    cout << "Address of var1: " << ptr << endl;

    // Pointers can be used to changed the contents of
    // the variable they are pointing to by
    // 'indirection operator' (*)
    cout << endl;
    cout << "Here is the content of var1: " << var1 << endl;
    cout << "Here is the content of var1: " << *ptr << endl;

    // Modify the content of var1 by using pointers
    *ptr = 2008;
    cout << "Here is the new content of var1: " << var1 << endl;
    cout << "Here is the new content of var1: " << *ptr << endl;

    // Array name is a pointer
    // Name of array is the address of the first element
    int numbers[5] = {2, 9, 5, 3, 8};
    cout << endl;
    cout << "Array address: " << numbers << endl;
    cout << "Array first element: " << *numbers << endl;
    cout << "Array first element: " << *(numbers + 0) << endl;
    cout << "Array second element: " << *(numbers + 1) << endl;         // (numbers + 1) means numbers + 1 * sizeof(short)
    cout << "Array second element: " << numbers[1] << endl;

    cout << "Array content (Line 38): ";
    for (int index = 0; index < 5; index++)
    {
        cout << *(numbers + index) << " ";                              // numbers[index] <=> *(numbers + index) <=> ptr[index]
    }

    cout << endl;
    ptr = numbers;
    cout << "Array content (Line 46): ";
    for (int index = 0; index < 5; index++)
    {
        cout << ptr[index] << " ";
    }

    cout << endl;
    cout << "Array content (Line 53): ";
    for (int index = 0; index < 5; index++)
    {
        ptr = &numbers[index];
        cout << *ptr << " ";
    }

    return 0;
}
