// Program to depict inline function for a class named MathWorks to add, sub, mul, div on two numbers.
#include <iostream>
using namespace std;

class MathWork
{
private:
    double a, b;

public:
    void ReadData();
    double add();
    double sub();
    double multi();
    double div();
};

void MathWork::ReadData()
{
    cout << "\nEnter any two numbers ";
    cin >> a >> b;
}

inline double MathWork::add()
{
    return a + b;
}
inline double MathWork::sub()
{
    return a - b;
}
inline double MathWork::multi()
{
    return a * b;
}
inline double MathWork::div()
{
    return a / b;
}

int main()
{
    MathWork data;
    data.ReadData();
    cout << "\n Addition       : " << data.add();
    cout << "\n Subtraction    : " << data.sub();
    cout << "\n Multiplication : " << data.multi();
    cout << "\n Division       : " << data.div();
    return 0;
}