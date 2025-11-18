#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
Node *binaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
        return nullptr;
    Node *temp = new Node(x);
    cout << "Enter left child of " << x << ": ";
    temp->left = binaryTree();
    cout << "Enter right child of " << x << ": ";
    temp->right = binaryTree();
    return temp;
}
void preOrder(Node *root, int &cnt)
{
    if (root == nullptr)
        return;
    cnt++;
    preOrder(root->left, cnt);
    preOrder(root->right, cnt);
}
int treeSize(Node *root)
{
    int cnt = 0;
    preOrder(root, cnt);
    return cnt;
}
int main()
{
    cout << "Enter root node: ";
    Node *root = binaryTree();
    cout << treeSize(root);
    return 0;
}