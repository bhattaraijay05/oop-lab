// 3. Write a C++ program to create a class called EXPRESSION. Using appropriate member functions accepts a valid arithmetic expression. Evaluate the expression and divide the result by another variable ‘d’. throw an exception “divide by zero” if the value of d=0. Call a read function to read the ‘d’ value again. Rethrow the exception if d still contains 0.
#include <iostream>
using namespace std;
class expression
{
    int d;
    int a, b, c;

public:
    void eval();
    void read();
    void disp();
};

void expression ::read()
{
    cout << "Enter values of a,b,c: " << endl;
    cin >> a >> b >> c;
    eval();
}

void expression ::eval()
{
    cout << "Enter d: " << endl;
    cin >> d;
    try
    {
        if (d == 0)
            throw(d);
    }
    catch (int d)
    {
        cout << "Divide by zero is not possible. Error. " << endl;
        eval();
    }
}

void expression ::disp()
{
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << "c : " << c << endl;
    cout << "d : " << d << endl;
    cout << "The final evaluated expression (a+b-c)/d is: " << (a + b - c) / d << endl;
}

int main()
{
    expression e;
    e.read();
    e.disp();
    return 0;
}