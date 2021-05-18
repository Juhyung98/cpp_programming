#include <string>
#include <iostream>
using namespace std;

class Employee{
    private:
        string name;
        string ssn;
        double netPay;
    public:
        Employee();
        Employee(const string& theName, const string& theSsn);
        string getName();
        string getSsN();
        double getNetPay();

        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(const double& newNetPay);
        void printCheck() const;
};

Employee::Employee() : name("No name"), ssn("No number"), netPay(0)
{}
Employee::Employee(const string& theName, const string& theNumber) : name(theName), ssn(theNumber), netPay(0)
{}
string Employee::getName(){
    return name;
}
string Employee::getSsN(){
    return ssn;
}
double Employee::getNetPay(){
    return netPay;
}
void Employee::setName(const string& newName){
    name = newName;
    return;
}
void Employee::setSsn(const string& newSsN){
    ssn = newSsN;
    return;
}
void Employee::setNetPay(const double& newNetPay){
    netPay = newNetPay;
    return;
}
void Employee::printCheck()const{
    cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n\n"
    << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n\n"
    << "Check with the author of the program about this bug.\n" << endl;
    exit(1);
    return;
}


class HourlyEmployee : public Employee{
    private:
        double wageRate;
        double hours;
    public:
        HourlyEmployee();
        HourlyEmployee(const string& theName, const string& theSsn, double theWageRate, double theHours);
        void setRate(double newWageRate);
        double getRate() const;
        void setHours(double hoursWorked);
        double getHours() const;
        void printCheck();
};

HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0)
{}
HourlyEmployee::HourlyEmployee(const string& theName, const string& theSsn, double theWageRate, double theHours)
                        : Employee(theName, theSsn), wageRate(theWageRate), hours(theHours)
                        {}
void HourlyEmployee::setRate(double newWageRate){
    wageRate = newWageRate;
    return;
}
double HourlyEmployee::getRate()const{
    return wageRate;
}
void HourlyEmployee::setHours(double hoursWorked){
    hours = hoursWorked;
    return;
}
double HourlyEmployee::getHours()const{
    return hours;
}
void HourlyEmployee::printCheck(){
    setNetPay(hours * wageRate);
    cout << "\n__________________________________________\n" << endl;
    cout << "Pay to the order of " << getName() << "\n" << endl;
    cout << "The sum of " << getNetPay( ) << " Dollars\n" << endl;
    cout << "__________________________________________\n" << endl;
    cout << "Check Stub: NOT NEGOTIABLE\n" << endl;
    cout << "Employee Number: " << getSsN() << "\n" << endl;
    cout << "Hourly Employee.\n"<< endl;
    cout << "Hours worked: " << hours << " Rate: " << wageRate << " Pay: " << getNetPay( ) << endl;
    cout << "__________________________________________\n";
    return;
}

class UnivHourlyEmployee : public HourlyEmployee{
    private:
        string univName;
    public:
        UnivHourlyEmployee();
        UnivHourlyEmployee(const string& theName, const string& theSsn, const string& theUnivName, double theWageRate, double theHours );
        void printInfo();
};
UnivHourlyEmployee::UnivHourlyEmployee(): HourlyEmployee(), univName("No univ")
{}
UnivHourlyEmployee::UnivHourlyEmployee(const string& theName, const string& theSsn, const string& theUnivName, double theWageRate, double theHours )
                                : HourlyEmployee(theName, theSsn, theWageRate, theHours), univName(theUnivName) {}
void UnivHourlyEmployee::printInfo(){
    cout <<"Employee name: " << getName() << ", Affliation: " << univName << endl;
    printCheck();
    return;
}



int main()
{
    UnivHourlyEmployee john("JohnDoe", "123456", "SSU", 10, 40);
    john.printInfo();
    return 0;
}