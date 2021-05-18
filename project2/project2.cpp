#include <iostream>
using namespace std;

class NComplex
{
public:
    NComplex(); 
    NComplex(double real_number);
    NComplex(double real_number, double imaginary_number);

    friend const NComplex operator +(const NComplex n1, const NComplex n2);
    friend const NComplex operator -(const NComplex n1, const NComplex n2);
    friend const NComplex operator *(const NComplex n1, const NComplex n2);
    friend const NComplex operator /(const NComplex n1, const NComplex n2);
    friend ostream& operator <<(ostream& outputStream, const NComplex complex_number);

private:
    double real_num;
    double imaginary_num;
};

int main()
{
    NComplex  n1 (5.1, 2.2), n2(2.0, 2.0), n3;
    double d1 = 3.0;

    cout << fixed;
    cout.precision(1);
    cout << "n1 : " << n1 << " / n2 : " << n2 << " / n3 : " << n3 << endl << endl;
    cout << "n1+n2: " << n1+n2 << endl;
    cout << "n1*n2: " << n1*n2 << endl;
    cout << "n1-d1: " << n1-d1 << endl;
    cout << "d1*n2: " << d1*n2 << endl;
    cout << "n1/n3: " << n1/n3 << endl;

    return 0;
}

// Constructor (a+bi)
NComplex::NComplex(double real_number, double imaginary_number) : real_num(real_number), imaginary_num(imaginary_number) {} 
// Constructor if only real part exists
NComplex::NComplex(double real_number) : real_num(real_number), imaginary_num(0) {}
// Default Constructor (Initialize to 0+0i)
NComplex::NComplex() : real_num(0), imaginary_num(0) {} 

// Addition overload
const NComplex operator +(const NComplex n1, const NComplex n2) 
{ 
    double real_part = (n1.real_num + n2.real_num);
    double imaginary_part = (n1.imaginary_num + n2.imaginary_num);
    return NComplex(real_part, imaginary_part);
}

// Subtraction overload
const NComplex operator -(const NComplex n1, const NComplex n2)  
{
    double real_part = (n1.real_num - n2.real_num);
    double imaginary_part = (n1.imaginary_num - n2.imaginary_num);
    return NComplex(real_part, imaginary_part);
}

// Multiplication overload
const NComplex operator *(const NComplex n1, const NComplex n2)  
{   
    double real_part = (n1.real_num * n2.real_num + (-1)*(n1.imaginary_num * n2.imaginary_num));
    double imaginary_part = (n1.real_num * n2.imaginary_num + n1.imaginary_num * n2.real_num);
    return NComplex(real_part, imaginary_part);
}

// Division overload
const NComplex operator /(const NComplex n1, const NComplex n2)
{
    double real_part;
    double imaginary_part;
    double denominator;

    // Multiply both sides (denominator and numerator) by complex conjugate of denominator
    if ((n2.real_num != 0) && (n2.imaginary_num != 0))
    {   
        denominator = n2.real_num * n2.real_num + n2.imaginary_num * n2.imaginary_num;
        // (n1.real_num + n1.imaginary_num i ) * (n2.real_num - n2.imaginary_num i)
        real_part = (n1.real_num * n2.real_num + n1.imaginary_num * n2.imaginary_num) / denominator; 
        imaginary_part = ((-1) * n1.real_num * n2.imaginary_num + n1.imaginary_num * n2.real_num) / denominator;
        return NComplex(real_part, imaginary_part);
    }
    // Multiply both sides (denominator and numerator) by a complex number (i)
    else if ((n2.real_num == 0) && (n2.imaginary_num != 0))
    {  
        denominator = (-1) * n2.imaginary_num;
        real_part = ((-1) * n1.imaginary_num) / denominator;
        imaginary_part = n1.real_num / denominator;
        return NComplex(real_part, imaginary_part);
    }
    // If the denominator is real_num (n2 : a + 0i)
    else if ((n2.real_num != 0) && (n2.imaginary_num == 0))
    {            
        real_part = n1.real_num / n2.real_num;
        imaginary_part = n1.imaginary_num / n2.real_num;
        return NComplex(real_part, imaginary_part);
    }
    // If the denominator is 0 (n2 : 0 + 0i) (if you want to divide by 0)
    else   
    {         
        cout << "Error: divide by zero" << "\n";
        exit(0);
    }
}

// 1. The case is divided by the presence or absence of a real or complex number. (4 types)
// 2. The case is divided by the sign of the complex number. (case 1)
ostream& operator <<(ostream& outputStream, const NComplex complex_number)   
{
    // case : a+bi 
    if ((complex_number.real_num != 0) && (complex_number.imaginary_num != 0))
    {
        double abs_imaginary_num = abs(complex_number.imaginary_num);
        if (complex_number.imaginary_num > 0)
            outputStream << complex_number.real_num << " + " << abs_imaginary_num << "i";
        else
            outputStream << complex_number.real_num << " - " << abs_imaginary_num << "i";
    }
    // case : bi 
    else if ((complex_number.real_num == 0) && (complex_number.imaginary_num != 0))
        outputStream << complex_number.imaginary_num << "i";
    // case : a
    else if ((complex_number.real_num != 0) && (complex_number.imaginary_num == 0))
        outputStream << complex_number.real_num;
    // case : 0 + 0i (0)
    else if ((complex_number.real_num == 0) && (complex_number.imaginary_num == 0))
        outputStream << "0";
        
    return outputStream;
}
