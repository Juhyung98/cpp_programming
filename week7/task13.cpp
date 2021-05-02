#include <iostream>
using namespace std;

class DayOfYear
{
public:
    void output();
    void adjustDay(int day);
    int month;
    int day;
};

int main ()
{
    DayOfYear d1;
    d1.month = 8;
    d1.day = 20;
    d1.adjustDay(20);    /* add 20 days to d1 */

    cout << "Adjusted date is ";
    d1.output();
    cout << "\n";
    
    return 0;
}

void DayOfYear::output()
{
    switch(month)
    {
        case 1:
            cout << "January "; break;
        case 2:
            cout << "February "; break;
        case 3:
            cout << "March "; break;
        case 4:
            cout << "April "; break;
        case 5:
            cout << "May "; break;
        case 6:
            cout << "June "; break;
        case 7:
            cout << "July "; break;
        case 8:
            cout << "August "; break;
        case 9:
            cout << "September "; break;
        case 10:
            cout << "October "; break;
        case 11:
            cout << "November "; break;
        case 12:
            cout << "December "; break;    
        default:
            cout << "Error in DayOfYear::output. Const software vendor.";
    }
    cout << day;
    return;
}

void DayOfYear::adjustDay(int operand)
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int calcDay = 0;

    for (int i = 1; i < 13; i++){
        days[i] += days[i-1];
    }
    calcDay = days[month-1] + day + operand;
    
    // if calcDay is negative : return to the previous year
    if (calcDay <= days[0]){
        calcDay = days[12] - (abs(calcDay)%days[12]);
    }
    // if calcDay is over days[12] : move on to next year
    else if (calcDay > days[12]){
        calcDay = calcDay % days[12];
    }
    
    // adjust the month and the day
    if (calcDay <= days[1]){
        month = 1;
        day = calcDay;
    }
    else if (calcDay <= days[2]){
        month = 2;
        day = calcDay - days[1];
    }
    else if (calcDay <= days[3]){
        month = 3;
        day = calcDay - days[2];
    }
    else if ( calcDay <= days[4]){
        month = 4;
        day = calcDay - days[3];
    }
    else if (calcDay <= days[5]){
        month = 5;
        day = calcDay - days[4];
    }
    else if (calcDay <= days[6]){
        month = 6;
        day = calcDay - days[5];
    }
    else if (calcDay <= days[7]){
        month = 7;
        day = calcDay - days[6];
    }
    else if (calcDay <= days[8]){
        month = 8;
        day = calcDay - days[7];
    }
    else if (calcDay <= days[9]){
        month = 9;
        day = calcDay - days[8];
    }
    else if (calcDay <= days[10]){
        month = 10;
        day = calcDay - days[9];
    }
    else if (calcDay <= days[11]){
        month = 11;
        day = calcDay - days[10];
    }
    else if (calcDay <= days[12]){
        month = 12;
        day = calcDay - days[11];
    }
    return;
}