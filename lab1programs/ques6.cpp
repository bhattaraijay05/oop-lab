// Write a C++ program to create a class called MATRIX using a two-dimensional array of integers. Implement the following operations by overloading the operator = = which checks the compatibility of two matrices m1 and m2 to be added and subtracted. Perform the addition and subtraction by overloading the operators + and – respectively. Display the results (sum matrix m3 and difference matrix m4).

#include <iostream>
using namespace std;

class Matrix
{
    int matrix[100][100];
    int rowSize, colSize;

public:
    void enterData();
    void displayData();
    friend bool operator==(Matrix, Matrix);
    friend Matrix operator+(Matrix, Matrix);
    friend Matrix operator-(Matrix, Matrix);
};

void Matrix::enterData()
{
    int i, j;
    cout << "\n Enter the number of rows in the matrix: " << endl;
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

void Matrix::displayData()
{
    int i, j;
    for (i = 0; i < rowSize; i++)
    {
        cout << "  " << endl;
        for (j = 0; j < colSize; j++)
            cout << "  " << matrix[i][j];
    }
}

bool operator==(Matrix m1, Matrix m2)
{
    return (m1.rowSize == m2.rowSize && m1.colSize == m2.colSize);
}

Matrix operator+(Matrix m1, Matrix m2)
{
    Matrix m3;
    cout << "\nSum of two matrix is :\n"
         << endl;
    for (int i = 0; i < m1.rowSize; i++)
    {
        cout << "  " << endl;
        for (int j = 0; j < m1.colSize; j++)
        {
            m3.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            cout << "   " << m3.matrix[i][j];
        }
    }
    return m3;
}
Matrix operator-(Matrix m1, Matrix m2)
{
    Matrix m4;
    cout << "\nDifference of two matrix is : \n"
         << endl;
    for (int i = 0; i < m1.rowSize; i++)
    {
        cout << "  " << endl;
        for (int j = 0; j < m1.colSize; j++)
        {
            m4.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];

            cout << "   " << m4.matrix[i][j];
        }
    }
    return m4;
}

int main()
{
    Matrix firstMatrix, secondMatrix;
    firstMatrix.enterData();
    secondMatrix.enterData();
    if (firstMatrix == secondMatrix)
    {
        (firstMatrix + secondMatrix);
        (firstMatrix - secondMatrix);
    }
    else
        cout << "\nThe matrix size donot match";
    return 0;
}