// Implementation file for the Rectangle class. 
# include "Rectangle.h"

//********************************************************* 
// setWidth sets the value of the member variable width.  * 
//*********************************************************

void Rectangle::setWidth(double w)
{
    if (w > 0)
        width = w;
    else
        // The throw statement’s argument, NegativeSize(), 
        // causes an instance of the NegativeSize class to 
        // be created and thrown as an exception. 
        throw NegativeWidth(w);
}

//*********************************************************** 
// setLength sets the value of the member variable length.  * 
//***********************************************************

void Rectangle::setLength(double l)
{
    if (l > 0)
        length = l;
    else
        throw NegativeLength(l);
}