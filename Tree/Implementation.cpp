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
int main()
{
    queue<Node *> q;
    cout << "Enter root of the tree: ";
    int x;
    cin >> x;
    Node *root = new Node(x);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int a;
        cout << "Enter left child of " << temp->data << ": ";
        cin >> a;
        if (a != -1)
        {
            temp->left = new Node(a);
            q.push(temp->left);
        }
        int b;
        cout << "Enter right child of: " << temp->data << ": ";
        cin >> b;
        if (b != -1)
        {
            temp->right = new Node(b);
            q.push(temp->right);
        }
    }
    return 0;
}