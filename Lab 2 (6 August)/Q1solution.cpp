/* Calculate value of a function given by f(x)=a0 + a1(x) + a2(x^2)....+an(x^n), where a is an array and x, n are integers.*/

#include <iostream>
using namespace std;

void InputA(int m, int A[])
{
    cout<<"Enter values into array \n";
    for (int i = 0; i <m; i++)
    {
        cin>>A[i];
        cout<<"\t";
    }
    cout<<"\n";
}

int power(int x, int i)
{
    int p=1;
    for (int j = 1; j <= i; j++)
    {
        p=p*x;
    }
    return p;
}

void ProductForSum(int A[], int B[], int x, int m)
{
    int i=0;
    while(i<m)
    {
        B[i]=A[i]*power(x,i);
        i++;
    } 
}

int SumAfterProduct(int B[], int m)
{
    int S=0;
    for (int i = 0; i < m; i++)
    {
        S=S+B[i];
    }
    return S;
}

int main()
{
    int n,m,x;
    cout<<"Number of elements you want in the array : ";
    cin>>m;
    n=m-1;
    cout<<"\n"<<"Corresponding value for n becomes : "<<n;
    cout<<endl;
    int A[m],B[m];
    InputA(m,A);
    cout<<"Enter value for x : ";
    cin>>x;
    ProductForSum(A,B,x,m);
    cout<<"The Desired Sum of A[i]*(x^i) from i = 0 to n is: "<<SumAfterProduct(B,m);

    return 0;
}