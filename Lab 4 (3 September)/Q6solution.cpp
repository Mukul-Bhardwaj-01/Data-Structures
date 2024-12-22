/*WAP to insert an element into a sorted 1-D array using pointers.*/

#include <iostream>
using namespace std;

void input(int Arr[], int num)
{
    cout<<"\nStart entering the elements :\n";
    for (int i = 0; i < num-1; i++)
    {
        cin>>Arr[i];
        cout<<"\n";
    }
    cout<<endl;    
}

void SortArr(int Arr[], int *P[], int num)
{
    int temp,k=0;;
    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num-1; j++)
        {
            if (Arr[i]>Arr[j])
            {
                temp=Arr[j];
                Arr[j]=Arr[i];
                Arr[i]=temp;
            }   
        }
    }

    for (int i = 0; i < num; i++)
    {
        P[i]=&Arr[i];
    }
    
    cout<<"Sorted Array is :\n";
    while (k<num-1)
    {
        cout<<*P[k]<<"\t";
        k++;
    }
    cout<<endl;

}

int main()
{
    int n,e;
    cout<<"Number of elements in your list :";
    cin>>n;
    int A[n+1];
    int *P[n+1];
    input(A,n+1);
    SortArr(A,P,n+1);

    cout<<"\nEnter element you want to insert :";
    cin>>e;
    int *p;
    p=&e;

    cout<<"New array is :\n";

    for (int i = 0; i < n+1; i++)
    {
        if ((*P[i]<e)&&(*P[i+1]>e))
        {
            for (int j = n; j > i+1; j--)
            {
                *P[j]=*P[j-1];
            }
            P[i+1]=p;
            break;
        }
    }
    cout<<"[ ";
    for (int i = 0; i < n+1; i++)
    {
        cout<<*P[i]<<"\t";
    }
    cout<<"]";
    cout<<endl;
    return 0;
}