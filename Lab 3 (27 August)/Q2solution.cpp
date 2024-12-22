/*Create an unsorted array,
Perform Search, Update, Insert and Delete operations
based on user specifications.*/

#include <iostream>
using namespace std;

void input(int A[], int n)
{
    cout<<"\nStart Entering the Elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
        cout<<"\n";
    }
    cout<<endl;
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<<endl;
}

void search(int A[], int n)
{
    int t;
    cout<<"What element do you want to search? : ";
    cin>>t;
    cout<<"\n Starting to search the element in the input array:\n";
    int i=0;
    while (i<n)
    {
        if (A[i]==t)
        {
          cout<<"Found at index : "<<i<<endl;
        }
        i++;
    }
}

void update(int A[], int n)
{
    cout<<"\nOn what basis do you want to update?\n";
    cout<<"1. Index\n2. Element\n";
    int x;
    cin>>x;
    cout<<endl;

    switch (x)
    {
    case 1:
        int i,e;
        cout<<"\nEnter index whose element you want to update : ";
        cin>>i;
        cout<<"\nEnter new element to place at this index : ";
        cin>>e;
        cout<<endl;
        A[i]=e;
        cout<<"Element Updated.\nNow list becomes:\n";
        display(A, n);
        break;
    
    

    case 2:
        int p,q;
        cout<<"\nEnter element that has to be replaced : ";
        cin>>p;
        cout<<"\nEnter new element to be placed : ";
        cin>>q;
        for (int j = 0; j < n; j++)
        {
            if (A[j]==p)
            {
                A[j]=q;
            }
        }

        cout<<"\nElement Updated.\nNow list becomes:\n";
        display(A, n);
        break;

    default:
        break;
    }
}

void insert(int A[], int n)
{
    int i,e;
    cout<<"\nEnter Index at which you wish to insert : ";
    cin>>i;
    cout<<"\nEnter element to insert : ";
    cin>>e;
    cout<<endl;
    
    for (int j = n; j >= i; j--)
    {
        A[j+1]=A[j];
    }
    A[i]=e;
    cout<<"\nNow the list becomes :\n";
    display(A,n+1);
}

void Delete(int A[], int n)
{
    string x;
    int e;
    cout<<"\nEnter element to delete : ";
    cin>>e;

    cout<<"\nDo you want to remove all its occurances or only first occurance?(all/first) : ";
    cin>>x;
    if ((x =="all")||(x=="All"))
    {
        int m=0,i=0;
        for (i = 0; i < n; i++)
        {
            if (A[i]==e)
            {
                m++;
            }
            
        }

        while (i<n)
        {
            if (A[i]==e)
            {
                for (int a = i; a < n-1; A++)
                {
                    A[a]=A[a+1];
                }
                
            }
            
            i++;
        }
        
        display(A,n-m);

    }

    if ((x=="First")||(x=="first"))
    {
        int i=0;
        while (i<n)
        {
            if (A[i]==e)
            {
                for (int a = i; a < n-1; A++)
                {
                    A[a]=A[a+1];
                }
                break;
            }
            
            i++;
        }

        display(A,n-1);
    }

    else
    {
        cout<<"Invalid choice.";
    }
    
}

int main()
{
    int n,p;
    char x;
    cout<<"Number of elements in your list : ";
    cin>>n;
    int A[n];
    input(A,n);

    do
    {
        cout<<"What operation do you want to perform?\n";
        cout<<"1. Search\n2. Update\n3. Insert\n4. Delete\n";
        cin>>p;
        
        switch (p)
        {
        case 1:
            search(A,n);
            break;
        
        case 2:
            update(A,n);
            break;
        
        case 3:
            insert(A,n);
            break;

        case 4:
            Delete(A,n);
            break;

        default:
          break;
        }

        cout<<"Want to do other operations?(y/n) : ";
        cin>>x;

    } while (x=='y');

    if (x=='n')
    {
        cout<<"Program Executed!!";
    }

return 0;

}