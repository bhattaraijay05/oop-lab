
// 1)
// Class A  - member variable int a, member function – void geta(int)
// Class B – member variable int b, member function – void getb(int)
// Class D : Public A, Public B
// Class D – member function void display() – displays a and b
// Main method create object of D. Invoke all the three methods.
// 2) Same program include display() function in class A and Class B – ambiquity

#include <iostream>
using namespace std;

class A
{
public:
    int a;
    void geta(int a)
    {
        cout << a << endl;
    }
};
class B
{
public:
    int b;
    void getb(int b)
    {
        cout << b << endl;
    }
};

class D : public A, public B
{
public:
    void Display()
    {
        A::geta(5);
        B::getb(10);
    }
};
int main()
{
    D d1;
    d1.Display();
    return 0;
}