/*WAP to extract address of row, element and value of elements of a 2-D array using pointers.*/

#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    int array[rows][cols];
    cout << "Enter the elements of the 2D array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }

    int (*ptr)[cols] = array;

    cout << "\nRow-wise information:\n";
    for (int i = 0; i < rows; i++)
    {
        cout << "Address of row " << i << ": " << (ptr + i) << endl;
        for (int j = 0; j < cols; j++)
        {
            cout << "\tElement [" << i << "][" << j << "]: ";
            cout << "Value = " << *(*(ptr + i) + j) << ", ";
            cout << "Address = " << (*(ptr + i) + j) << endl;
        }
    }
    return 0;
}