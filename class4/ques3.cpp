// 3.  Program to depict default arguments (without class) to calculate volume of a cylinder. Consider all types of functions to show characteristics of trailing arguments.
#include <iostream>
using namespace std;

inline double volume(float r = 1, float h = 1)
{
    return (3.14 * r * r * h);
}

int main()
{
    float x, y;
    cout << "Enter the radius and Height: ";
    cin >> x >> y;
    cout << "\n Volume with no default values = " << volume(x, y);
    cout << "\n Volume if the radius is default    = " << volume(y);
    cout << "\n Volume if the height is default    = " << volume(x);
    cout << "\n Volume with default height and radius    = " << volume();

    return 0;
}