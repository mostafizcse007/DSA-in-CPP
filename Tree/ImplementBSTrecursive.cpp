#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
Node *insertBST(Node *root, int val)
{
    if (!root)
    {
        Node *temp = new Node(val);
        return temp;
    }
    else if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}
void Print(Node *root)
{
    if (!root)
        return;
    Print(root->left);
    cout << root->data << " ";
    Print(root->right);
}
int main()
{
    int n;
    cout << "Enter the number of elements in BST: ";
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        root = insertBST(root, a);
    }
    Print(root);
    return 0;
}