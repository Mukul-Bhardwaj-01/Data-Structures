/*Create a sorted array and perform search, update, insert and delete opearations on it based on user specifications and maintaining the order of elements.*/

#include <iostream>
using namespace std;

void InputA(int n, int A[])
{
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << endl;
}

void SortA(int n, int A[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int search(int A[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int n, target, x;
    cout << "Number of elements in your list: ";
    cin >> n;
    cout << endl;
    int A[n];
    InputA(n, A);
    SortA(n, A);
    cout << "What do you want to do?\n1. Search\n2. Update\n3. Insert\n4. Delete\n";
    cin >> x;

    switch (x)
    {
    case 1:
        cout << "Enter the element you want to search: ";
        cin >> target;
        cout << endl;
        int result;
        result = search(A, 0, n - 1, target);
        if (result != -1)
            cout << "Element found at index " << result << endl;
        else
            cout << "Element not found" << endl;
        break;

    default:
        cout << "Invalid option selected. Please choose a valid operation (1-4)." << endl;
        break;
    }
    return 0;
}