//           Shape

// Triangle           Quadrilateral
// Right Triangle     Rectangle
//                    Square

#include <iostream>
using namespace std;

class Shape
{
public:
    float x, y;
    void readInput()
    {
        cout << "Enter the value for length and breadth: " << endl;
        cin >> x;
        cin >> y;
    }
};

class Triangle : public Shape
{
public:
    void calcTri()
    {
        readInput();
        cout << "The area of triangle is: " << 0.5 * x * y << endl;
    };
};
class RightTriangle : public Triangle
{
public:
    void calcRTri()
    {
        readInput();
        cout << "The area of right angle triangle is: " << 0.5 * x * y << endl;
    };
};
class Quadrilateral : public Shape
{
public:
    void Draw()
    {
        readInput();
        cout << "The area of quadrilateral is: " << x * y << endl;
    };
};
class Rectangle : public Quadrilateral
{
public:
    void calcRect()
    {
        readInput();
        cout << "The area of rectangle is: " << x * y << endl;
    };
    void calcSquare()
    {
        cout << "Enter the length : " << endl;
        cin >> Shape::x;
    };
};
class Square : public Rectangle
{
public:
    void Draw()
    {
        cout << "\nCalculation of Square" << endl;
        Rectangle::calcSquare();
        cout << "The area of square is: " << Rectangle::x * Rectangle::x << endl;
    };
};

int main()
{
    Rectangle r1;
    Square s1;
    r1.calcRect();
    s1.Draw();
    return 0;
}