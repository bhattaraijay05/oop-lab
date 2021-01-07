// 1. Create a vehicle having a non-static data member registration number and a static data member count. Non-static member functions seRreNno() and getRegNo() are used to get and set the registration number. A static member function getVehiclecount() is used to return the number of vehicles in the garage. Use a constructor to increment the vehicle count when a vehicle is created and the destructor to decrement the count when the vehicle is destroyed

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
    static int count;
    string regno;

public:
    void setRegNo();
    void getRegNo();
    Vehicle()
    {
        count++;
    }
    static void getVehicleCount()
    {
        cout << "The number of vehicle is: " << count << endl;
    }
    ~Vehicle()
    {
        count--;
        cout << "Number of vehicle after destructing: " << count << endl;
    }
};

void Vehicle::setRegNo()
{
    cout << "\nEnter the registeration number: " << endl;
    cin >> regno;
}

void Vehicle::getRegNo()
{
    cout << "\nRegistered vehicle is: " << regno << endl;
}

int Vehicle::count = 0;

int main()
{
    Vehicle v1;
    v1.setRegNo();
    v1.getRegNo();
    v1.getVehicleCount();
    Vehicle v2;
    v2.setRegNo();
    v2.getRegNo();
    v2.getVehicleCount();
    Vehicle v3;
    v3.setRegNo();
    v3.getRegNo();
    v3.getVehicleCount();
    return 0;
}