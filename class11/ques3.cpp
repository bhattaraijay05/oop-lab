// 3. Design a Ship class with member variables name and year with constructors and appropriate accessors and mutators.
// Virtual print function that displays the ship’s name and the year it was built.
// Design a CruiseShip class that is derived from the Ship class. The CruiseShip class should have the following members a variable for the maximum number of passengers and appropriate accessors, mutators and constructor. A print function that overrides the print function in the base class. The CruiseShip class’s print function should display only the ship’s name and the maximum number of passengers.
// Design a CargoShip class that is derived from the Ship class. The CargoShip class should have the following members a member variable for the cargo capacity, constructor, accessors and mutators. A print function that overrides the print function in the base class. The CargoShip class’s print function should display only the ship’s name and the ship’s cargo capacity. Demonstrate the classes in a program that has an array of Ship pointers. The array elements should be initialized with the addresses of dynamically allocated Ship. The program should then step through the array, calling each object’s print function.

#include <iostream>
#include <string>
using namespace std;

class Ship
{

public:
    string nameOfShip;
    int builtYear;
    Ship(string sname, int syear)
    {
        nameOfShip = sname;
        builtYear = syear;
    } //Constructor
    Ship() : nameOfShip("NULL"), builtYear(0){};
    void readData();    //accessor
    void displayData(); //mutator
    virtual void print()
    {
        cout << endl
             << "The name of the ship is:" << nameOfShip;
        cout << endl
             << "The year of built of the ship is:" << builtYear;
    }
};

void Ship::readData()
{
    cout << "Enter the details of the ship: " << endl;
    cout << "Name: " << endl;
    cin >> nameOfShip;
    cout << "Built Year: " << endl;
    cin >> builtYear;
}

void Ship::displayData()
{
    cout << "The details of the ship: " << endl;
    cout << "Name: " << nameOfShip << endl
         << "Built Year: " << builtYear << endl;
}

class CruiseShip : public Ship
{

public:
    int numberOfPassengers;
    CruiseShip(string sname, int syear, int num) : Ship(sname, syear)
    {
        numberOfPassengers = num;
    }
    CruiseShip() : numberOfPassengers(0){};
    void readData()
    {
        Ship::readData();
        cout << "Enter the number of passengers: " << endl;
        cin >> numberOfPassengers;
    }

    void displayData()
    {
        Ship::displayData();
        cout << "Details of Cruise Ship: " << endl;
        cout << "Name: " << nameOfShip << endl
             << "Built Year: " << builtYear << endl
             << "Number of Passengers: " << numberOfPassengers << endl;
    }

    void print()
    {
        cout << endl
             << "The name of the ship is:" << nameOfShip;
        cout << endl
             << "The number of passengers in the ship are:" << numberOfPassengers;
    }
};
class CargoShip : public Ship
{

public:
    int cargoCapacity;
    CargoShip(string sname, int syear, int num) : Ship(sname, syear)
    {
        cargoCapacity = num;
    }

    CargoShip() : cargoCapacity(0){};
    void readData()
    {
        Ship::readData();
        cout << "Enter the capacity of Cargo: " << endl;
        cin >> cargoCapacity;
    }

    void displayData()
    {
        Ship::displayData();
        cout << "Details of Cruise Ship: " << endl;
        cout << "Name: " << nameOfShip << endl
             << "Built Year: " << builtYear << endl
             << "Cargo Capacity: " << cargoCapacity << endl;
    }

    void print()
    {
        cout << endl
             << "The name of the ship is:" << nameOfShip;
        cout << endl
             << "The capacity of cargo is:" << cargoCapacity;
    }
};

int main()
{
    // s1.readData();
    // cs.readData();
    // cs1.readData();
    // Ship *s = &cs;
    // s->readData();
    // s->print();
    Ship *ships[3] = {
        new Ship("NewShip", 1880),
        new CruiseShip("Cruise Ship", 1998, 2400),
        new CargoShip("Cargo Ship", 2000, 5000)};
    for (int index = 0; index < 3; index++)
    {
        ships[index]->print();
        cout << endl;
    }
    return 0;
}