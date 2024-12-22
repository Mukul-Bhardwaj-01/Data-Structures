/*Create a 2-D array and perform search operation on it based on user entered index and print the address of searched element based on ROW major and COLUMN major representation.*/

#include <iostream>
using namespace std;

int rowMajorAddress(int baseAddress, int row, int col, int totalCols, int elementSize)
{
    return baseAddress + (row * totalCols + col) * elementSize;
}

int columnMajorAddress(int baseAddress, int row, int col, int totalRows, int elementSize)
{
    return baseAddress + (col * totalRows + row) * elementSize;
}

int main()
{
    int rows, cols, baseAddress, elementSize;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>cols;

    int array[rows][cols];
    cout << "Enter the elements of the 2D array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << "Enter the base address of the array: ";
    cin >> baseAddress;
    cout << "Enter the size of each element (in bytes): ";
    cin >> elementSize;
    int searchRow, searchCol;
    cout << "Enter the row index (0-based): ";
    cin >> searchRow;
    cout << "Enter the column index (0-based): ";
    cin >> searchCol;

    if (searchRow >= rows || searchCol >= cols)
    {
        cout << "Invalid index. Exiting program." << endl;
        return 1;
    }

    int rowMajorAddr = rowMajorAddress(baseAddress, searchRow, searchCol, cols, elementSize);
    int columnMajorAddr = columnMajorAddress(baseAddress, searchRow, searchCol, rows, elementSize);

    cout << "Element at index (" << searchRow << ", " << searchCol << ") is: " 
         << array[searchRow][searchCol] << endl;
    cout << "Row-major address: " << rowMajorAddr << endl;
    cout << "Column-major address: " << columnMajorAddr << endl;

    return 0;
}