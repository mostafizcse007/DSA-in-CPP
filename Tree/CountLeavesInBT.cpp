#include <iostream>
#include <queue>
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
    cout << "Enter left child of " << x << " : ";
    temp->left = binaryTree();
    cout << "Enter right child of " << x << " : ";
    temp->right = binaryTree();
    return temp;
}
void levelOrder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}
int countLeaves(Node *root)
{
    if (!root)
        return 0;
    int cnt = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp->left && !temp->right)
            cnt++;
        else
        {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return cnt;
}
int main()
{
    cout << "Enter root of the tree: ";
    Node *root = binaryTree();
    levelOrder(root);
    cout << countLeaves(root) << endl;
    return 0;
}