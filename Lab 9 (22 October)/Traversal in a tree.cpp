#include <iostream>
using namespace std;

class tree
{
public:
    int data;
    tree* left_node;
    tree* right_node;
    tree (int val)
    {
        data=val;
        left_node=nullptr;
        right_node=nullptr;
    }
};

void Create(tree* &node)
{
    char v,w;
    cout<<"Do you want a left child of "<<node->data<<" (y/n)?";
    cin>>v;
    if ((v=='y')||(v=='Y'))
    {
        int left;
        cout<<"Enter value of left child: ";
        cin>>left;
        tree* left_ = new tree(left);
        node->left_node = left_;
        Create(left_);
    }
    cout<<"Do you want a right child of "<<node->data<<" (y/n)?";
    cin>>w;
    if ((w=='y')||(w=='Y'))
    {
        int right;
        cout<<"Enter value of right child: ";
        cin>>right;
        tree* right_ = new tree(right);
        node->right_node = right_;
        Create(right_);
    }
}

void preorderTraversal(tree*& node)
{
    cout<<node->data<<"\t";
    preorderTraversal(node->left_node);
    preorderTraversal(node->right_node);
}

void inorderTraversal(tree*& node)
{
    inorderTraversal(node->left_node);
    cout<<node->data<<"\t";
    inorderTraversal(node->right_node);
}

void postorderTraversal(tree*& node)
{
    postorderTraversal(node->left_node);
    postorderTraversal(node->right_node);
    cout<<node->data<<"\t";
}

int main()
{
    int a;
    cout<<"Enter value at root: ";
    cin>>a;
    tree* root=new tree(a);
    Create(root);
    cout<<"\nPreorder Traversal is: ";
    preorderTraversal(root);
    cout<<"\nInorder Traversal is: ";
    inorderTraversal(root);
    cout<<"\nPostorder Traversal is: ";
    postorderTraversal(root);
}