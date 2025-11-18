#include <iostream>
#include <queue>
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
void levelOrderTraverse(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int a;
        cout << "Enter left child of " << curr->data << ": ";
        cin >> a;
        if (a != -1)
        {
            curr->left = new Node(a);
            q.push(curr->left);
        }
        int b;
        cout << "Enter right child of: " << curr->data << ": ";
        cin >> b;
        if (b != -1)
        {
            curr->right = new Node(b);
            q.push(curr->right);
        }
    }
}
void print(Node *root)
{
    if (root == nullptr)
    {
        cout << "The tree is empty!" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }

    cout << endl;
}
int main()
{
    int x;
    cout << "Enter root of the tree: ";
    cin >> x;
    Node *root = new Node(x);
    levelOrderTraverse(root);
    print(root);
    return 0;
}