#include <iostream>
using namespace std;

class A{
    public:
        int temp;
        A(){
            cout << "Constructor in class A executed" << "\n" << endl;
        };
        ~A(){
            cout << "Destructor in class A executed" << "\n" << endl;
        };
};

class B : public A{
    public:
        int temp2;
        B(){
            cout << "Constructor in class B executed" << "\n" << endl;
        };
        ~B(){
            cout << "Destructor in class B executed" << "\n" << endl;
        };
};

class C : public B{
    public:
        int temp3;
        C(){
            cout << "Constructor in class C executed" << "\n" << endl;
        };
        ~C(){
            cout << "Destructor in class C executed" << "\n" << endl;
        };
};

int main()
{
    C* pc = new C;
    delete pc;

    return 0;
}