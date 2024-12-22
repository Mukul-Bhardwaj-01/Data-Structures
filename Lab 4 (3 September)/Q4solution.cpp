/*WAP to create arrays using calloc and malloc and display the values.*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr_malloc = (int*)malloc(n * sizeof(int));
    if (arr_malloc == NULL)
    {
        cout << "Memory allocation failed using malloc." << endl;
        return 1;
    }

    cout << "Enter " << n << " values for the malloc array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr_malloc[" << i << "]: ";
        cin >> arr_malloc[i];
    }

    cout << "\nValues in the malloc array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr_malloc[" << i << "] = " << arr_malloc[i] << endl;
    }

    int* arr_calloc = (int*)calloc(n, sizeof(int));
    if (arr_calloc == NULL)
    {
        cout << "Memory allocation failed using calloc." << endl;
        free(arr_malloc);
        return 1;
    }
    cout << "\nValues in the calloc array (initialized to zero):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr_calloc[" << i << "] = " << arr_calloc[i] << endl;
    }

    free(arr_malloc);
    free(arr_calloc);

    return 0;
}