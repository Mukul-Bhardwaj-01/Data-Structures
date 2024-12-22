/*WAP to extract address and value of elements of 1-D array using pointers*/

#include <iostream>
using namespace std;

void inputA(int Arr[], int num)
{
    cout<<"\nStart entering elements into the list :\n";
    for (int i = 0; i < num; i++)
    {
        cin>>Arr[i];
        cout<<"\n";
    }
    cout<<endl;
    
}

void displayAddressAndValue(int *p[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout<<*p[i]<<"\t"<<p[i]<<"\n";
    }
    
}

int main()
{
    int n;
    cout<<"Number of elements in your list :";
    cin>>n;
    int A[n];
    int *p[n];
    inputA(A,n);
    for (int i = 0; i < n; i++)
    {
        p[i]=&A[i];
    }
    displayAddressAndValue(p,n);

    return 0;
}