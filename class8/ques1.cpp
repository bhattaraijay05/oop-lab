// Design a class named PersonData with the following member variables lastName, firstName,  address, city, state and phone.  Write the appropriate constructor, accessor and mutator functions for these member variables. Next, design a class named CustomerData, which is derived from the PersonData class.  The CustomerData class should have the following member variables: customerNumber, email id. The customerNumber variable will be used to hold a unique integer for each customer.
// Write appropriate constructors, accessor and mutator functions for these member variables. Demonstrate an object of the CustomerData class in a simple program.

#include <iostream>
#include <string>
using namespace std;

class PersonData
{
public:
    string lastName, firstName, address, city, state;
    int phoneNumber;
    PersonData() : lastName("NULL"), firstName("NULL"), address("NULL"), city("NULL"), state("NULL"), phoneNumber(0){}; //Constructor
    void readData();                                                                                                    //Accessor
    void displayData();                                                                                                 //Mutator
};

void PersonData::readData()
{
    cout << "Enter the details of the customer: " << endl;
    cout << "First Name: " << endl;
    cin >> firstName;
    cout << "Last Name: " << endl;
    cin >> lastName;
    cout << "Address: " << endl;
    cin >> address;
    cout << "City: " << endl;
    cin >> city;
    cout << "State: " << endl;
    cin >> state;
    cout << "Phone Number: " << endl;
    cin >> phoneNumber;
}

void PersonData::displayData()
{
    cout << "\n\n\nThe details of the customer: " << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Address: " << address << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Phone Number: " << phoneNumber << endl;
}

class CustomerData : public PersonData
{
public:
    string email;
    int customerNumber;
    CustomerData() : email("NULL"), customerNumber(0){};
    void readCustomerData();
    void displayCustomerData();
};

void CustomerData::readCustomerData()
{
    readData();
    cout << "Email: " << endl;
    cin >> email;
    cout << "Customer Number: " << endl;
    cin >> customerNumber;
}

void CustomerData::displayCustomerData()
{
    displayData();
    cout << "Email: " << email << endl;
    cout << "Customer Number: " << customerNumber << endl;
}

int main()
{
    CustomerData c1;
    c1.readCustomerData();
    c1.displayCustomerData();
    return 0;
}