// 2. Create a base class called SHAPE. Use this class to store two double type values that could be used to compute the area of figures. Derive two specific classes called Triangle and Rectangle from the class SHAPE. Add to the base class, a member function get_data() to initialize base class data member and other member function display_area() to compute and display the area of figure. Make display_area() as a virtual function and redefine this function in the derived classes to suit their requirements.

#include <iostream>
using namespace std;
class Shape
{
public:
    double a, b;
    void get_data()
    {
        cin >> a >> b;
    }
    virtual void display_area() = 0;
};

class Triangle : public Shape
{
public:
    void display_area()
    {
        cout << "Area of triangle is: " << 0.5 * a * b << endl;
    }
};

class Rectangle : public Shape
{
public:
    void display_area()
    {
        cout << "Area of rectangle is: " << a * b << endl;
    }
};

int main()
{
    Triangle T1;
    Shape *st = &T1;
    cout << "\nEnter base and height of the triangle: ";
    st->get_data();
    st->display_area();

    Rectangle R1;
    Shape *sr = &R1;
    cout << "\nEnter length and breadth of the rectangle: ";
    sr->get_data();
    sr->display_area();
    return 0;
}