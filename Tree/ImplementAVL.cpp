#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        height = 1;
        left = right = nullptr;
    }
};
int getHeight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node *insertAVL(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insertAVL(root->left, key);
    else if (key > root->data)
        root->right = insertAVL(root->right, key);
    else
        return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }
    else if (balance < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    else if (balance < -1 && key < root->right->data)
    {
        root->right = leftRotation(root->right);
        return leftRotation(root);
    }
    return root;
}
void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void levelOrder(Node *root)
{
    if (!root)
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
int main()
{
    Node *root = nullptr;
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        if (i >= 1 && i <= 3)
        {
            if (i == 1)
            {
                cout << "Enter " << i << "st node: ";
                cin >> temp;
            }
            else if (i == 2)
            {
                cout << "Enter " << i << "nd node: ";
                cin >> temp;
            }
            else
            {
                cout << "Enter " << i << "rd node: ";
                cin >> temp;
            }
        }
        else
        {
            cout << "Enter " << i << "th node: ";
            cin >> temp;
        }
        root = insertAVL(root, temp);
        levelOrder(root);
    }
    // cout << "Inorder: ";
    // inOrder(root);
    // cout << endl;
    // cout << "Level order: ";
    return 0;
}