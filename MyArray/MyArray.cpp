#include <iostream>
#include "MyArray.h"
using namespace std;

int main()
{
    MyArray<int> arr(10);
    cout << "Random(): ";
    arr.Random();
    arr.Print();

    cout << "SetSize(11, 5): ";
    arr.SetSize(11, 5);
    arr.Print();

    cout << "arr2(arr): ";
    MyArray<int> arr2(arr);
    arr2.Print();

    cout << "GetSize(): " << arr.GetSize() <<
        endl << endl << endl;

    cout << "GetUpperBound(): " << arr.GetUpperBound() <<
        endl << endl << endl;

    if (arr.IsEmpty()) {
        cout << "Array is empty" <<
            endl << endl << endl;
    } else {
        cout << "Array is NOT empty" <<
            endl << endl << endl;
    }

    arr.FreeExtra();

    cout << "RemoveAll(): ";
    arr.RemoveAll();
    arr.Print();

    cout << "New array: ";
    arr.SetSize(5, 5);
    arr.Random();
    arr.Print();

    cout << "index 2: " << arr.GetAt()[2] << endl;
    arr.SetAt(2, 1);
    cout << "index 2: " << arr[2] <<
        endl << endl << endl;

    cout << "Add(3): ";
    arr.Add(3);
    arr.Print();
    
    arr2.Random();
    cout << "arr2: ";
    arr2.Print();
    arr2.Append(arr);
    cout << "arr2: ";
    arr2.Print();

    cout << "arr3 = arr: ";
    MyArray<int> arr3 = arr;
    arr3.Print();

    cout << "GetData(): " << arr.GetData() << 
        endl << endl << endl;

    cout << "array 3: ";
    MyArray<int> arr4(2);
    arr4.Random();
    arr4.Print();
    cout << "InsertAt(arr4, 2): ";
    arr.InsertAt(arr4, 2);
    arr.Print();

    cout << "RemoveAt(3, 5): ";
    arr.RemoveAt(3, 5);
    arr.Print();
}