
// 4. Consider two structures : Distance (feet and inches) and Room(length and width). For a dining room instance, calculate the area in square feet.

#include <iostream>
using namespace std;

struct area
{
    int feet;
    float inch;
} length, width;

int main()
{
    float totalLength, totalWidth;
    cout << "Enter the length of room in feet and inch \n";
    cin >> length.feet;
    cin >> length.inch;
    totalLength = length.feet + (12 * length.inch);
    cout << "Enter the width of room in feet and inch \n";
    cin >> width.feet;
    cin >> width.inch;
    totalWidth = width.feet + (12 * width.inch);
    cout << "The area of the room is " << totalLength * totalWidth << " square feet";
}