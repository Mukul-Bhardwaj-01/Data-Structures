/*Find the sum of elements of a given list recursively.*/

#include <iostream>
using namespace std;

int SumbyRecursion(int A[], int n, int sum, int index)
{
    if (index==n)
    {
        return sum;
    }
    
    else
    {
        sum=sum+A[index];
       
    }
     return SumbyRecursion(A,n,sum,index+1);
}

void InputA(int A[], int n)
{
    cout<<"\nEnter Elements into your list :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
        cout<<"\n";
    }
    cout<<endl;
}

int main()
{
    int n,Result,s;
    cout<<"Number of elements in your list are :";
    cin>>n;
    int A[n];
    cout<<endl;
    InputA(A,n);
    s=0;
    Result=SumbyRecursion(A,n,s,0);
    cout<<"Sum = "<<Result;
}