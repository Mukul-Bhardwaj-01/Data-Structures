/*WAP to perform binary search on elements of an array using pointer or call by reference.*/

#include <iostream>
#include <cstdlib>
using namespace std;

void BinarySearchby_Ref(int low,int high, int A[], int* &ptr)
{
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (A[mid]==*ptr)
        {
            cout<<"Element found at : "<<mid<<" index";
            return;
        }
        else if (A[mid]>*ptr)
        {
            high=mid-1;
        }   
        else
        {
            low=mid+1;
        }
    }
    cout<<"\nElement not found in array!";
}

void sortA(int A[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j =0; j < n-i-1; j++)
        {
            if (A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
            }   
        }   
    }
}

void inputA(int A[], int n)
{
    cout<<"\nEnter elements into the array : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<i+1<<". ";
        cin>>A[i];
        cout<<"\n";
    }
    cout<<endl;
    sortA(A,n);
}

int main()
{
    int n,t;
    int *A, *ptr;
    cout<<"Number of elements in your array : ";
    cin>>n;
    A= (int*) calloc(n, sizeof(int));
    inputA(A,n);
    cout<<"Which element do you want to search : ";
    cin>>t;
    ptr=&t;
    BinarySearchby_Ref(0,n,A,ptr);
    return 0;
}