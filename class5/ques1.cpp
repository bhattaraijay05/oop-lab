#include <iostream>
using namespace std;

class Complex
{
    int real_number, imaginary_number;

public:
    void read_data();
    void display_data();
    friend Complex ADD(int, Complex);
    friend Complex ADD(Complex, Complex);
};

void Complex::read_data()
{
    cout << "Enter the real value" << endl;
    cin >> real_number;
    cout << "Enter the imaginary value" << endl;
    cin >> imaginary_number;
}

void Complex::display_data()
{
    cout << real_number << "+" << imaginary_number << "i";
}

Complex ADD(int a, Complex s2)
{
    Complex calc;
    calc.real_number = a + s2.real_number;
    calc.imaginary_number = a + s2.imaginary_number;
    return calc;
}
Complex ADD(Complex s1, Complex s2)
{
    Complex calc;
    calc.real_number = s1.real_number + s2.real_number;
    calc.imaginary_number = s1.imaginary_number + s2.imaginary_number;
    return calc;
}

int main()
{
    Complex s1, s2, realAndComplexSum, twoComplexSum;
    int a;
    cout << "Enter the real number" << endl;
    cin >> a;
    cout << "Enter the data for  first complex number" << endl;
    s1.read_data();
    cout << "Enter the data for second complex number" << endl;
    s2.read_data();

    realAndComplexSum = ADD(a, s2);
    cout << endl
         << "Addition of real and complex number: " << endl;
    realAndComplexSum.display_data();
    twoComplexSum = ADD(s1, s2);
    cout << endl
         << "Addition of two complex number: " << endl;
    twoComplexSum.display_data();
    return 0;
}