/*WAP to swap two numbers using pointers/reference to the numbers.*/

using namespace std;
#include <iostream>

void SwapByRef(int *&p,int *&q)
{
    int temp;
    temp= *p;
    *p= *q;
    *q= temp;

    cout<<"Values swapped and now :\n";
    cout<<"a = "<<*p<<"\nb = "<<*q<<endl;
}

int main()
{
    int a,b;
    cout<<"Enter value for a : ";
    cin>>a;
    cout<<"\nEnter value for b : ";
    cin>>b;
    int *p, *q;
    p=&a;
    q=&b;
    SwapByRef(p,q);
}