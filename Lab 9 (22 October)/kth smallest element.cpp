#include <iostream>
using namespace std;

class tree
{
public:
    int data;
    tree* left_node;
    tree* right_node;

    tree(int val)
    {
        data = val;
        left_node = nullptr;
        right_node = nullptr;
    }
};

void Create(tree*& node)
{
    char v, w;
    cout << "Do you want a left child of " << node->data << " (y/n)? ";
    cin >> v;
    if ((v == 'y') || (v == 'Y'))
    {
        int left;
        cout << "Enter value of left child: ";
        cin >> left;
        tree* left_ = new tree(left);
        node->left_node = left_;
        Create(left_);
    }

    cout << "Do you want a right child of " << node->data << " (y/n)? ";
    cin >> w;
    if ((w == 'y') || (w == 'Y'))
    {
        int right;
        cout << "Enter value of right child: ";
        cin >> right;
        tree* right_ = new tree(right);
        node->right_node = right_;
        Create(right_);
    }
}

void kthSmallestUtil(tree* node, int& count, int k)
{
    if (node == nullptr || count >= k) return;
    kthSmallestUtil(node->left_node, count, k);
    count++;
    if (count == k)
    {
        cout << "The " << k << "th smallest element is: " << node->data << endl;
        return;
    }
    kthSmallestUtil(node->right_node, count, k);
}

void findKthSmallest(tree* root, int k)
{
    int count = 0;
    kthSmallestUtil(root, count, k);
}

int main()
{
    int a,k;
    cout << "Enter value at root: ";
    cin >> a;
    tree* root = new tree(a);
    Create(root);
    cout << "Enter the value of k: ";
    cin >> k;
    findKthSmallest(root, k);
    return 0;
}
