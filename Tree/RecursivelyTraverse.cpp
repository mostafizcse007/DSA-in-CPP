#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int data)
    {
        this->data = data;
        right = left = nullptr;
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
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    else
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    cout << "Enter root node: ";
    Node *root = binaryTree();
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl
         << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl
         << "Postorder Traversal: ";
    postorderTraversal(root);
    return 0;
}