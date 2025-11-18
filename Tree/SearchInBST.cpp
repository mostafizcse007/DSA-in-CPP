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
bool findVal(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    else if (root->data > val)
        return findVal(root->left, val);
    else
        return findVal(root->right, val);
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
    cout << findVal(root, 120) << endl;
    return 0;
}