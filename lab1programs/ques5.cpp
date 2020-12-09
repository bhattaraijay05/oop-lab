// Create a vehicle having a non-static data member registration number and a static data member count. Non-static member functions setregno() and getregno() are used to get and set the registration number. A static member function getVehiclecount() is used to return the number of vehicles in the garage. Use a constructor to increment the vehicle count when a vehicle is created and the destructor to decrement the count when the vehicle is destroyed.
#include <iostream>
using namespace std;

//static int globalCount = 0;
class vehicle
{
private:
    static int count;
    string regno;

public:
    void set();
    void get();
    void getCount();
    vehicle()
    {
        //++globalCount;
        count++;
    }
    ~vehicle()
    {
        //--globalCount;
        count--;
        cout << "\n " << count;
    }
    static int getVehiclecount()
    {
        return count;
    }
};
void vehicle::set()
{
    cout << "\n Enter register number : ";
    cin >> regno;
}
void vehicle::get()
{
    cout << "\n Register number -- " << regno << endl;
}
void vehicle::getCount()
{
    cout << "\n Total vehicle = " << count;
}

int vehicle::count = 0;

int main()
{
    vehicle v1, v2;
    v1.getCount();
    vehicle v3;
    v2.getCount();
    cout << "\n Vehicles in garage = " << v3.getVehiclecount();

    return 0;
}