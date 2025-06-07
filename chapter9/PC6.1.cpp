// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
using namespace std;

// Function prototypes
int *donationsArrayAllocator(int);          // A function returns a pointer to an array of ints
void getDonations(int *, int);
void arrSelectSort(int *const, int);
void showArray(const int *const, int);

int main()
{
    // Variable declaration
    int numOfDonations;

    // Prompt for number of donations
    cout << "Enter the number of donations: ";
    cin >> numOfDonations;

    // Dynamically allocate memory for the donations array
    int *donationsArrayPtr = donationsArrayAllocator(numOfDonations);

    // Get the donations
    getDonations(donationsArrayPtr, numOfDonations);

    // Display the donations in their original order.
    cout << "\nThe donations, in their original order are: \n";
    showArray(donationsArrayPtr, numOfDonations);

    // Sort the elements of the array of pointers.
    arrSelectSort(donationsArrayPtr, numOfDonations);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "\nThe donations, sorted in ascending order are: \n";
    showArray(donationsArrayPtr, numOfDonations);

    delete [] donationsArrayPtr;
    return 0;
}

// ***************************************************************
// Definition of function donationsArrayAllocator                *
// This function dynamically allocates memory for an array used  *
// to store the donations                                        *
// ***************************************************************
int *donationsArrayAllocator(int size)
{
    int *arrayPtr = nullptr;

    arrayPtr = new int[size];

    return arrayPtr;
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
        cin >> donationsArray[index];
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
      minElem = arr[startScan];
      for(int index = startScan + 1; index < size; index++)
      {
         if (arr[index] < minElem)
         {
            minElem = arr[index];
            minIndex = index;
         }
      }
      arr[minIndex] = arr[startScan];
      arr[startScan] = minElem;
   }
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of arr. size is the    *
// number of elements.                                        *
//*************************************************************

void showArray(const int *const arr, int size)
{
   for (int count = 0; count < size; count++)
      cout << arr[count] << " ";
   cout << endl;
}
