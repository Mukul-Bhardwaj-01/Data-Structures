/*Given an array 'A' of n integers.
Generate an array 'B' of same size such that
B[i] contains product of all elements of array 'A'
except for the number at same index in the array
(i.e A[i]) and print array 'B'.*/

#include <iostream>
using namespace std;

void InputA(int n, int A[])
{
    cout<<"Start entering elements into first array (Don't Enter '0' in any input)\n";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
}

void Product(int n, int A[], int B[])
{
    int p=1;
    for (int i = 0; i < n; i++)
    {
        p=p*A[i];
    }
    for (int i = 0; i < n; i++)
        {
            B[i]=p/A[i];
        }
    
    cout<<"Required Array is :\n";
    for (int i = 0; i < n; i++)
    {
        cout<<B[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"Number of elements in first array : ";
    cin>>n;
    cout<<"\n";
    int A[n], B[n];
    InputA(n,A);
    Product(n,A,B);
    return 0;
}