#include <bits/stdc++.h>
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

void levelOrderTraverse(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int a;
        cout << "Enter left child of " << curr->data << " (-1 for no child): ";
        cin >> a;
        if (a != -1)
        {
            curr->left = new Node(a);
            q.push(curr->left);
        }
        int b;
        cout << "Enter right child of " << curr->data << " (-1 for no child): ";
        cin >> b;
        if (b != -1)
        {
            curr->right = new Node(b);
            q.push(curr->right);
        }
    }
}

void reverseOddLevels(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        vector<Node *> currentLevel;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            currentLevel.push_back(curr);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (level % 2 == 1)
        {
            int left = 0, right = currentLevel.size() - 1;
            while (left < right)
            {
                swap(currentLevel[left]->data, currentLevel[right]->data);
                left++;
                right--;
            }
        }
        level++;
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
    cout << "Original tree:" << endl;
    print(root);
    reverseOddLevels(root);
    cout << "Tree after reversing odd levels:" << endl;
    print(root);
    return 0;
}