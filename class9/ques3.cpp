
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
    void geta(int a)
    {
        cout << a;
    }
};
class B : public A
{
public:
    void getb(int b)
    {
        cout << b;
    }
};

class D : public A, public B
{
public:
    void Display()
    {
        A::geta(5);
    }
};
int main()
{
    A d1;
    return 0;
}