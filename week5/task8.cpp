#include <iostream>

using namespace std;

int iAdd(int numA, int numB)
{
    int res;
    res = numA + numB;
    return res;
}

int iSub(int numA, int numB)
{
    int res;
    res = numA - numB;
    return res;
}

int iMul(int numA, int numB)
{
    int res;
    res = numA * numB;
    return res;
}

double iDiv(int numA, int numB)
{
    double res;
    res = numA / static_cast<double>(numB);
    return res;
}

int main()
{
   int a = 20, b = 10;

   cout << "Add: " << iAdd(a,b) << endl;
   cout << "Sub: " << iSub(a,b) << endl;
   cout << "Mul: " << iMul(a,b) << endl;
   cout << "Div: " << iDiv(a,b) << endl;

   return 0;
}