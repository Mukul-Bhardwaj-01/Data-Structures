#include <iostream>
using namespace std;

void input(int n, int A[])
{
    cout << "Enter elements in the queue:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "Frontmost element is: " << A[0] << endl;
    cout << "Rearmost element is: " << A[n - 1] << endl;
}

void display(int n, int A[])
{
    cout << "Overall queue is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void InsertInQueue(int& n, int A[], int value)
{
    A[n] = value;
    n++;
    cout << "Element inserted successfully!\n";
    display(n, A);
}

void DeleteInQueue(int& n, int A[])
{
    if (n == 0)
    {
        cout << "Queue is empty, no elements to delete.\n";
        return;
    }
    cout << "Deleting frontmost element: " << A[0] << endl;
    for (int i = 0; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }
    n--;
    display(n, A);
}

void UpdateInQueue(int n, int A[], int index, int value)
{
    if (index < 0 || index >= n)
    {
        cout << "Invalid index. Update failed.\n";
        return;
    }
    cout << "Updating element at index " << index << " from " << A[index] << " to " << value << ".\n";
    A[index] = value;
    display(n, A);
}

void SortQueue(int n, int A[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }
    cout << "Queue sorted successfully.\n";
    display(n, A);
}

int main()
{
    int n;
    cout << "How many elements you want in your queue: ";
    cin >> n;
    cout << "\n";
    int A[n + 10]; // Extra space for additional insertions
    input(n, A);
    display(n, A);

    // Example usage of functions
    int choice;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert in Queue\n";
        cout << "2. Delete from Queue\n";
        cout << "3. Update an element in Queue\n";
        cout << "4. Sort the Queue\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            InsertInQueue(n, A, value);
            break;
        case 2:
            DeleteInQueue(n, A);
            break;
        case 3:
            int index, newValue;
            cout << "Enter index to update (0-based): ";
            cin >> index;
            cout << "Enter new value: ";
            cin >> newValue;
            UpdateInQueue(n, A, index, newValue);
            break;
        case 4:
            SortQueue(n, A);
            break;
        case 5:
            display(n, A);
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
