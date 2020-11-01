// 1. Program to depict inline function (without class) for calculating area of a circle.
#include <iostream>
using namespace std;

inline float Area(float radius)
{
    return 3.1415 * radius * radius;
}
int main()
{

    float radius;
    cout << "Enter the radius of circle: ";
    cin >> radius;
    cout << "The required area of circle is  : " << Area(radius);
    return 0;
}