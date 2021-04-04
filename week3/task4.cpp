#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int discretMath;
    int programmingLanguage;
    int dataStructure;

    double average;
    string grade;

    cout << "Put the discrete math score: ";
    cin >> discretMath;

    cout << "Put the programming language score: ";
    cin >> programmingLanguage;

    cout << "Put the data structure score: ";
    cin >> dataStructure;

    average = (discretMath + programmingLanguage + dataStructure) / 3.0;

    if (average > 95)
        grade = "A+";
    else if (average > 90)
        grade = "A0";
    else if (average > 85)
        grade = "B+";
    else if (average > 80)
        grade = "B0";
    else if (average > 75)
        grade = "C+";
    else if (average > 70)
        grade = "C0";
    else
        grade = "F";

    cout << fixed;
    cout.precision(2);
    cout << "The average score is " << average << " and the grade is " << grade << endl;

    return 0;
}