// The program tests: "If an exception is thrown by the member
// function of a class object, then the class destructor is called."
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
    double width;
    double length;

    // Create a Rectangle object.

    // Get the width and length.
    cout << "Enter the rectangle's width: ";
    cin >> width;
    cout << "Enter the rectangle's length: ";
    cin >> length;

    // Store these values in the Rectangle object.
    try
    {
        Rectangle myRectangle(5, 10);    // A pointer to a Rectangle object.
        Rectangle secondRetangle(2, 5);

        myRectangle.setWidth(width);
        myRectangle.setLength(length);
        cout << "The area of the rectangle is ";
        cout << myRectangle.getArea() << endl;

        throw "An error occurs";
    }
    catch (Rectangle::NegativeLength e)
    {
        cout << "Error: Cannot assign " << e.getValue();
        cout << " for length.\n";
    }
    catch (Rectangle::NegativeWidth e)
    {
        cout << "Error: Cannot assign " << e.getValue();
        cout << " for width.\n";
    }
    catch(const char* exception)
    {
        cout << exception;
    }

    cout << "End of the program." << endl;

    return 0;
}