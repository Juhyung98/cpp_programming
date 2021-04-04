#include <iostream>
using namespace std;

void sort_three (int& a, int& b, int& c)
{
    int temp;
   /* Fill-up here with your codes */
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (b < c)
    {
        if (a < c) {
            temp = c;
            c = b;
            b = a;
            a = temp;
        }
        else {
            temp = b;
            b = c;
            c = temp;
        }
    }
    return;
}

int main ()
{
   int i1 = 100, i2 = 90, i3 = 500;
   sort_three (i1, i2, i3);
   cout << "Three numbers are: "
        << i1 << " , " << i2 << " , " << i3 << endl;
    return 0;
}