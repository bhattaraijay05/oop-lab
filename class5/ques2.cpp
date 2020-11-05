// Write a C++ program to create a struct Distance with feet and inches. Implement the following overloading functions display i. display(Dist d) - d is an object of  Distance ii. display(Float f) - f is an input from the user

#include <iostream>
using namespace std;
<<<<<<< HEAD
=======

>>>>>>> e201131b283667ec5f49f756ae89138070436687
struct Distance
{
    float feet, inches;
};

void Display(Distance d)
{
    d.feet = 10;
    d.inches = 4;
    cout << "The distance is " << d.feet << '\'' << d.inches << '\"' << endl;
};
void Display(float feet, float inches)
{
    cout << "The distance is " << feet << '\'' << inches << '\"' << endl;
};

int main()
{
    Distance d;
    Display(d);
    float feet, inches;
    cout << "Enter the feet and inches " << endl;
    cin >> feet >> inches;
    Display(feet, inches);
    return 0;
}