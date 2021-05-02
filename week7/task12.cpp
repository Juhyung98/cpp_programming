#include <iostream>

using namespace std;

// Structure for a bank certificate of deposit
struct CDAccountV1
{
    double balance;
    double interestRate;
    int term;   // months untill maturity
};

void swap(CDAccountV1& v1, CDAccountV1& v2)
{
   double temp_b;
   double temp_interest;
   int temp_term;

   temp_b = v1.balance;
   v1.balance = v2.balance;
   v2.balance = temp_b;

   temp_interest = v1.interestRate;
   v1.interestRate = v2.interestRate;
   v2.interestRate = temp_interest;

   temp_term = v1.term;
   v1.term = v2.term;
   v2.term = temp_term;
   
   return;
}

int main()
{
    struct CDAccountV1 v1 = {10.0, 0.01, 60};
    struct CDAccountV1 v2 = {50.0, 0.02, 30};

    swap (v1, v2);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "balance: " << v1.balance
            << ", interest: " << v1.interestRate
            << ", terms: " << v1.term << endl;

     cout << "balance: " << v2.balance
             << ", interest: " << v2.interestRate
             << ", terms: " << v2.term << endl;
    
    return 0;
}

