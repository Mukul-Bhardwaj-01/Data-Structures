/*Find whether the element is present in the given list using Binary search.
Provide the user with options to either opt iterative or recursive searching method.*/

#include <iostream>
using namespace std;

void InputA(int n, int A[])
{
     cout<<"Enter "<<n<<" elements :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
        cout<<"\t";
    }
    cout<<endl;
}

void SortA(int n, int A[])
{
    cout<<"Corresponding Sorted Array is :"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (A[i]>A[j])
            {
                int temp;
                temp=A[j];
                A[j]=A[i];
                A[i]=temp;
            }   
        }   
    }

    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<"\t";
    }
}

int IterativeSearch(int n, int A[], int a)
{
    cout<<"Searching by Iterative Search Method, we get :\n";

    int left = 0;
    int right = n - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (A[mid] == a) 
        {
            return mid;
        }

        if (A[mid] < a)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    return -1;
    
}

int RecursiveSearch(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            return RecursiveSearch(arr, low, mid - 1, target);
        }

        return RecursiveSearch(arr, mid + 1, high, target);
    }

    return -1;
}

int main()
{
    int n,a,x,result;
    cout<<"Enter number of elements in your list : ";
    cin>>n;
    cout<<endl;
    int A[n];
    InputA(n,A);
    SortA(n,A);
    cout<<"\nEnter element you want to search : ";
    cin>>a;
    cout<<endl;
    cout<<"How do you wish to search it?\n";
    cout<<"1.Iterative Search Method\n2.Recursive Search Method\n";
    cin>>x;
    switch (x)
    {
    case 1:
        result=IterativeSearch(n,A,a);
        if (result!=-1)
        {
            cout<<a<<" Found in array at "<<result<<" index"<<endl;
        }

        else
        {
            cout<<a<<" Not found in array"<<endl;
        }
        break;
    
    case 2:
        result=RecursiveSearch(A, 0, n-1, a);
        if (result!=-1)
        {
            cout<<a<<" Found in array at "<<result<<" index"<<endl;
        }

        else
        {
            cout<<a<<" Not found in array"<<endl;
        }
        break;

    default:
        break;
    }

    return 0;
}