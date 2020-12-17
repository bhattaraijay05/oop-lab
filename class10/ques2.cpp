
// 2. Write a program to sort using bubbleSort sort by applying function templates.

#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                T b;
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }
}

template <typename T>
void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}

int main()
{

    int arr[20], numOfElement;
    cout << "Enter number elements to be insetred in the array" << endl;
    cin >> numOfElement;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < numOfElement; i++)
        cin >> arr[i];

    cout << "Elements after sorting are" << endl;
    bubbleSort(arr, numOfElement);
    PrintArray(arr, numOfElement);
    return 0;
}