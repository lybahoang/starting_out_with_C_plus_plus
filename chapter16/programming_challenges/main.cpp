#include "SimpleVector.h"
#include <iostream>
using namespace std;

int main()
{
    // Create an object from SimpleVector object
    // that works with string data type.
    SimpleVector<string> sportList(4);

    // Initialize the object with some string literals.
    sportList[0] = "Soccer";
    sportList[1] = "Badminton";
    sportList[2] = "Basketball";
    sportList[3] = "Pickle ball";

    // Display the general information of sportList.
    cout << "There are " << sportList.getSize() << " sports.\n";
    // Display the values in the object.
    cout << "Here are sports in sportList.\n";
    for (int count = 0; count < 4; count++)
    cout << sportList[count] << endl;
    
    // Push a new sport to the back of sportList.
    cout << "\nPusing \"Tennis\" back.\n";
    sportList.push_back("Tennis");
    
    while (sportList.getSize() > 0)
    {
        // Display the values in the object.
        cout << "There are " << sportList.getSize() << " sports.\n";
        cout << "Here are sports in sportList.\n";
        sportList.displayArray();
        
        // Pop back the last element.
        cout << "\nPopping back the last element, ";
        cout << "which is ";
        cout << sportList.getElementAt(sportList.getSize() - 1);
        sportList.pop_back();
        cout << endl;
    }

    // Display the values in the object.
    sportList.displayArray();
    
    return 0;
}