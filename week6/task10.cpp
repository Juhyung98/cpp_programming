#include <iostream>

using namespace std;

void fillArray(int arr[], int size)
{
    cout << "Put array elements: ";
    for (int i=0; i < size; i++)
        cin >> arr[i];
    return;
}

void printArray(int arr[], int size)
{
    cout << "Array elements are ";
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return;
}

int main()
{
    int arr[5];
    fillArray (arr, 5);
    printArray (arr, 5);

    return 0;
}