#include <iostream>
using namespace std;

const int CAP = 10;

int main()
{
    int size;
    int list[CAP] = { 12, 34, 45, 2, 8, 10, 16, 180, 182, 22 };
    size = CAP;
    int i, delIndex, addIndex, newInt = 0;

    cout << "Your list is: " << endl;
    for (i = 0; i < size; i++)
    {
        cout << list[i] << endl;
    } 

    //Deleting an index

    cout << "\nPlease enter index to delete from: ";
    cin >> delIndex;

    for (i = delIndex; i < size; i++)
    {
        list[i] = list[i + 1];
    }
    size--;
    cout << "The index position you specified has been deleted." << endl;
    cout << "The new array is: " << endl;
    for (i = 0; i < size; i++)
    {
        cout << list[i] << endl;
    }

    //Adding an index

    cout << "\nNow, please enter the index position to add to: " << endl;
    cin >> addIndex;
    cout << "\nEnter the number to add to the index: " << endl;
    cin >> newInt;

    for (i = size - 1; i >= addIndex; i--)
    {
        list[i + 1] = list[i];
    }
    list[addIndex] = newInt;
    size++;

    cout << "The number has been added at the specified index position." <<endl;
    cout << "The new array is: " << endl;
    for (i = 0; i < size; i++)
    {
        cout << list[i] << endl;
    }
    return 0;
}