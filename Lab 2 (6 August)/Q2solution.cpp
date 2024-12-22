/*Find whether the element is present in given list using Linear search.
Provide the user with options to either opt iterative or recursive approach.*/

#include <iostream>
using namespace std;

void input(int A[], int n) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        cout << "Enter element: ";
        cin >> A[i];
    }

    cout << "Input Array is: ";
    for (i = 0; i < n; i++) 
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void IterativeSearch(int A[],int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i]==a)
        {
          cout<<a<<" Found at index "<<i<<endl;
        }
    }
}

int RecursiveSearch(int A[], int a, int index, int n, int flag)
{
  if (index>=n)
  {
    if (flag=0)
    {
      cout<<"Element not found!";
    }
    return -1;
  }
  if (A[index]==a)
  {
    cout<<"Element Found at index "<<index<<endl;
    flag=1;
  }
  
  return RecursiveSearch(A,a,index+1,n,flag);
}

int main() 
{ 
    int n,a,x,flag=0;
    cout<<"Number of elements in list : ";
    cin>>n;
    int A[n];
    input(A,n);
    cout<<"Enter Element to search \n";
    cin>>a;

    cout<<"How do you want to search it?\n";
    cout<<"1. Iterative Method\n";
    cout<<"2. Recursive Method\n";

    cin>>x;

    switch (x)
    {
    case 1:
      cout<<"Checking by iteration method on array \n";
      IterativeSearch(A,n,a);
      break;

    case 2:
      cout<<"Checking by recursive method on array \n";
      RecursiveSearch(A,a,0,n,flag);  
      break;
    
    default:
      cout<<"Invalid type of Choice...";
      break;
    }
}

   