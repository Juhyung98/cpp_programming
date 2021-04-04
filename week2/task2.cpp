#include <iostream>
using namespace std;

int main()
{
    const double MI_TO_KM = 1.60934;
    double Soongsil_to_hyungNam = 184.6;
    double result;

    result = Soongsil_to_hyungNam * 0.001 / MI_TO_KM;
    
    cout << "The distance is " << result << " miles" << endl;

    return 0;
}
