// Write a program to find the transpose of a matrix using friend function and with member functions to read and display the matrix.

#include <iostream>
using namespace std;
int i, j;
class Transpose
{
    int matrix[100][100];
    int rowSize, colSize;

public:
    void enterData();
    void displayData();
    void displayTransposedData();
    friend Transpose displayTranspose(Transpose);
};

void Transpose::enterData()
{

    cout << "Enter the number of rows in the matrix: " << endl;
    cin >> rowSize;
    cout << "Enter the number of columns in the matrix: " << endl;
    cin >> colSize;
    cout << "Enter the data for rows and columns: " << endl;
    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
            cin >> matrix[i][j];
    }
}

void Transpose::displayData()
{
    cout << "The given matrix is " << endl;
    for (i = 0; i < rowSize; i++)
    {
        cout << "  " << endl;
        for (j = 0; j < colSize; j++)
            cout << "  " << matrix[i][j];
    }
}

void Transpose::displayTransposedData()
{
    cout << endl
         << "The transpose fo the matrix is " << endl;
    for (i = 0; i < colSize; i++)
    {
        cout << "  " << endl;
        for (j = 0; j < rowSize; j++)
            cout << "  " << matrix[i][j];
    }
}

Transpose displayTranspose(Transpose transposedMatrix)
{
    Transpose temp;
    for (i = 0; i < transposedMatrix.colSize; i++)
    {
        for (j = 0; j < transposedMatrix.rowSize; j++)
        {
            temp.matrix[i][j] = transposedMatrix.matrix[j][i];
        }
    }
    temp.rowSize = transposedMatrix.rowSize;
    temp.colSize = transposedMatrix.colSize;
    return temp;
}

int main()
{
    Transpose newMatrix, matrixTranspose;
    newMatrix.enterData();
    newMatrix.displayData();
    matrixTranspose = displayTranspose(newMatrix);
    matrixTranspose.displayTransposedData();
    return 0;
}