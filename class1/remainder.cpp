// 1. Demonstrate the remainder operator
#include <iostream>
using namespace std;
int main()
{
    int dividand, divisor, remainder;
    cout << "Enter the dividand ";
    cin >> dividand;
    cout << "Enter the divisor ";
    cin >> divisor;
    remainder = dividand % divisor;
    cout << "The remainder is " << remainder;
}