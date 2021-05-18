#include <iostream>
using namespace std;

int *allocArray(int len){
    int *ary;
    ary = new int [len];
    return ary;
}
void printArray(int *ary, int len){
    int i = 0;
    cout << "Array elements are: ";
    for (i=0; i<len; i++){
    cout << ary[i] << " ";
    }
}
void freeArray(int *ary){
    delete [] ary;
    ary = nullptr;
}

int main()
{
    int* arr;
    int size;

    cout << "Enter the array size: ";
    cin >> size;
    arr = allocArray (size);

    for (int i=0; i<size; i++){
        cout << "Put an array element: ";
        cin >> arr[i];
    }

    printArray(arr, size);
    freeArray(arr);
    return 0;
}