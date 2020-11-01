// A person is at location (10,10), moves stepwise to directions based on (N, W, E, S). If the person reaches location (7,11) treasure is found, at location (5,11) a maneater is found . Use a switch case.
#include <iostream>
using namespace std;
int main()
{
    int x_cordinate = 10, y_cordinate = 10, steps;
    char direction, repeat = 'y';
    cout << "Enter the DIRECTION in North, South, East and West \n";

    while (repeat == 'y' || repeat == 'Y')
    {
        cin >> direction;
        cout << "Enter steps \n";
        switch (direction)
        {
        case 'N':
            cin >> steps;
            x_cordinate = x_cordinate + steps;
            break;

        case 'S':
            cin >> steps;
            x_cordinate = x_cordinate - steps;
            break;

        case 'E':
            cin >> steps;
            y_cordinate = y_cordinate + steps;
            break;

        case 'W':
            cin >> steps;
            y_cordinate = y_cordinate - steps;
            break;

        default:
            break;
        }
        if (x_cordinate == 7 && y_cordinate == 11)
        {
            cout << "You have found the treasure";
            break;
        }
        else if (x_cordinate == 5 && y_cordinate == 11)
        {
            cout << "Maneater is found";
            break;
        }
        cout << "Not reached to destination? Wanna walk more? ";
        cin >> repeat;
    }

    return 0;
}