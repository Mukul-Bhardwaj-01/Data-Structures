/*Create a binary Tree*/

#include <iostream>
using namespace std;

class bt
{
public:
    int data;
    bt* left;
    bt* right;

    bt(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void create(bt*& node)
{
    char W, X;
    cout << "Do you want a left node for " << node->data << "? (y/n): ";
    cin >> W;
    if (W == 'y')
    {
        int Left_val;
        cout << "Enter Value for left node: ";
        cin >> Left_val;
        bt* left_node = new bt(Left_val);
        node->left = left_node;
        create(left_node);
    }

    cout << "Do you want a right node for " << node->data << "? (y/n): ";
    cin >> X;
    if (X == 'y')
    {
        int Right_val;
        cout << "Enter Value for right node: ";
        cin >> Right_val;
        bt* right_node = new bt(Right_val);
        node->right = right_node;
        create(right_node);
    }
}

void display(bt* node, int depth = 0)
{
    if (!node) return;

    display(node->right, depth + 1);

    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << node->data << endl;

    display(node->left, depth + 1);
}

int main()
{
    int a;
    cout << "Enter the root element for the tree: ";
    cin >> a;
    bt* root = new bt(a);
    create(root);
    cout << "\nThe binary tree structure is:\n";
    display(root);
    return 0;
}