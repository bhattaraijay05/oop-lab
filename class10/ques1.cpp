// Write a C++ program to implement an array using class templates. Implement the following operations: Adding two arrays, finding the max and min in an array.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void addArray(T first[], T second[], int len)
{
    int sum[20];
    cout << "The sum of two array is " << endl;
    for (int i = 0; i < len; i++)
    {
        sum[i] = first[i] + second[i];
        cout << sum[i] << "\t";
    }
}

template <typename T>
void minVal(T arr[], int len)
{
    T res = arr[0];
    for (int i = 1; i < len; i++)
    {

        res = min(res, arr[i]);
    }
    cout << "Minimum value of array is " << res << endl;
}

template <typename T>
void maxVal(T arr[], int len)
{
    T res = arr[0];
    for (int i = 1; i < len; i++)
    {
        res = max(res, arr[i]);
    }
    cout << "Maximum value of array is " << res << endl;
}

int main()
{
    int arr1[20], arr2[20], sum[40], numOfElement;
    cout << "Enter number elements to be inserted in the array " << endl;
    cin >> numOfElement;
    cout << "Enter the elements for array 1 " << endl;
    for (int i = 0; i < numOfElement; i++)
        cin >> arr1[i];
    minVal(arr1, numOfElement);
    maxVal(arr1, numOfElement);
    cout << "Enter the elements for array 2 " << endl;
    for (int i = 0; i < numOfElement; i++)
        cin >> arr2[i];
    minVal(arr2, numOfElement);
    maxVal(arr2, numOfElement);
    addArray(arr1, arr2, numOfElement);
    return 0;
}