#include <iostream>

using namespace std;

int main()
{
    int a[4][4] = {10, 20, 30, 40, 5, 4 ,3, 99, 55, 100, 42, 100, 0, 105, 2, 11};
    int max = a[0][0], max_2 = a[0][0];
 
    for (int row=0; row<4; row++){
        for (int col=0; col<4; col++){
            if (max < a[row][col])
            {
                max_2 = max;
                max = a[row][col];
            }
            else if (max_2 < a[row][col])
            {
                max_2 = a[row][col];
            }
        }
    }

    cout << "The largest number is " << max << endl;
    cout << "The second-largest number is " << max_2 << endl;

    return 0;
}