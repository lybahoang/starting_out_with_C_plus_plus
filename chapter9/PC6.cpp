// Page 545, Starting out with C++, 8th edition
// Program Challenge 6: Case Study Modification #1
// The program adds a new function to dynamically allocate the
// donations array.

// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
using namespace std;

// Function prototypes
int *donationsArrayAllocator(int);
void getDonations(int *, int);
void arrSelectSort(int *const, int);
void showArray(const int *const, int);
void showArrPtr(int *[], int);

int main()
{
    // Variable declaration
    int numOfDonations;

    // Prompt for the number of donations
    cout << "Enter the number of donations: ";
    cin >> numOfDonations;

    // Dynamically allocate memory for the donations array
    int *donationsArrayPtr = donationsArrayAllocator(numOfDonations);

    // Get donations
    getDonations(donationsArrayPtr, numOfDonations);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donationsArrayPtr, numOfDonations);

    // Sort the elements of the array of donations.
    arrSelectSort(donationsArrayPtr, numOfDonations);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: \n";
    showArray(donationsArrayPtr, numOfDonations);

    delete [] donationsArrayPtr;

    return 0;
}

//**************************************************************
// Definition of function donationsArrayAllocator.             *
// This function dynamically allocates memory for the          *
// donations array and returns its address                     *
//**************************************************************

int *donationsArrayAllocator(int size)
{
    return new int[size];
}

//**************************************************************
// Definition of function getDonations.                        *
// This function prompts for the donations                     *
//**************************************************************

void getDonations(int *donationsArray, int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << "Enter the donation " << (index + 1) << ": ";
        cin >> *(donationsArray + index);
    }
}

//****************************************************************
// Definition of function arrSelectSort.                         *
// This function performs an ascending order selection sort on   *
// arr, which is an array of pointers. Each element of array     *
// points to an element of a second array. After the sort,       *
// arr will point to the elements of the second array in         *
// ascending order.                                              *
//****************************************************************

void arrSelectSort(int *const arr, int size)
{
   int startScan, minIndex;
   int minElem;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minElem = *(arr + startScan);
      for(int index = startScan + 1; index < size; index++)
      {
         if (*(arr + index) < minElem)
         {
            minElem = *(arr + index);
            minIndex = index;
         }
      }
      *(arr + minIndex)= *(arr + startScan);
      *(arr + startScan) = minElem;
   }
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements.                     *
//**************************************************************

void showArray(const int *const arr, int size)
{
   for (int count = 0; count < size; count++)
      cout << *(arr + count) << " ";
   cout << endl;
}
