#include <iostream>
using namespace std;
class Rectangle
{
     int length;
     int breadth;

public:
     void calc(int, int);
};
void Rectangle::calc(int l, int b)
{
     int area;
     area = l * b;
     cout << "Area = " << area << "\n";
}
int main()
{
     int l, b;
     Rectangle r;
     cout << "Enter length of rectangle ";
     cin >> l;
     cout << "Enter breadth of rectangle ";
     cin >> b;
     r.calc(l, b);
     return 0;
}