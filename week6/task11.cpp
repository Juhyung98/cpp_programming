#include <iostream>
#include <string>

using namespace std;

int add(int i1, int i2)
{
    int result;
    result = i1+i2;
    return result;
}
double add(double d1, double d2)
{
    double result;
    result = d1+d2;
    return result;
}
string add(string s1, string s2)
{
    string result;
    result = s1+s2;
    return result;
}
int main(void)
{
   int i1 = 10, i2 = 30;
   double d1 = 0.5, d2 = 3.5;
   string s1 = "Hello", s2 = "World";

   cout << fixed;
   cout.precision(1);

   cout << add (i1, i2) << ", "
        << add (d1, d2) << ", "
        << add (s1, s2) << endl;

    return 0;
}
