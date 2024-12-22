/*Design a singly linked list using struct and perform
Search, Update, Insert, Sort and Delete operations on it
based on user specifications.*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertLL(Node *&N, int n)
{

}

void ValueForNodes(int A[], int n)
{
    cout<<"\nEnter values for nodes :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
        cout<<"\n";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Number of nodes in your Linked list :";
    cin>>n;
    Node *N = NULL;
    int A[n];
    
    ValueForNodes(A,n);
    
    insertLL(N,n);
}