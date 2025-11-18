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
    cout << "Enter left node of " << x << " : ";
    temp->left = binaryTree();
    cout << "Enter right node of " << x << " : ";
    temp->right = binaryTree();
    return temp;
}
int maxHeight(Node *root)
{
    if (!root)
        return 0;
    int cnt = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cnt++;
    }
    return cnt;
}
int main()
{
    cout << "Enter root of the tree: ";
    Node *root = binaryTree();
    cout << maxHeight(root) << endl;
    return 0;
}