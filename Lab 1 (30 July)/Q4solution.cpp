/*Given two numbers a and n. Calculate a^n 
with number of iterations strictly less than 'n'.*/

#include <iostream>
using namespace std;

void aPOWERn(int a, int n)
{
    int p=1;
    for (int i = 1; i <= n/2; i++)
    {
        p=p*a;
    }
    if (n%2==0)
    {
        cout<<"The value of "<<a<<"^"<<n<<" is :"<< p*p;
    }
    else
    {
        cout<<"The value of "<<a<<"^"<<n<<" is :"<<p*p*a;
    }
}

int main()
{
    int a,n;
    cout<<"Enter number : ";
    cin>>a;
    cout<<"\n";
    cout<<"Enter power to which you want to raise it : ";
    cin>>n;
    cout<<"\n";
    aPOWERn(a,n);
}