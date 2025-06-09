#include "IntegerList.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an object from the IntegerList class.
    IntegerList myList;

    // Add some values to the list.
    for (int count = 0; count < 100; count += 10)
        myList.appendNode(count);

    // Display the values in the list.
    cout << "There are " << myList.countNode() << " values ";
    cout << "in the list, which are\n";
    myList.displayList();

    return 0;
}