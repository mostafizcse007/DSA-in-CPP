#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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
Node *implement(Node *root)
{
    if (!root)
        return nullptr;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int a;
        cout << "Enter left child of " << temp->data << " : ";
        cin >> a;
        if (a != -1)
        {
            temp->left = new Node(a);
            q.push(temp->left);
        }
        int b;
        cout << "Enter right child of " << temp->data << " : ";
        cin >> b;
        if (b != -1)
        {
            temp->right = new Node(b);
            q.push(temp->right);
        }
    }
    return root;
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
vector<int> postOrder(Node *root)
{
    if (!root)
        return {};
    stack<Node *> st1, st2;
    vector<int> ans;
    st1.push(root);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter root of the tree: ";
    cin >> n;
    Node *root = new Node(n);
    root = implement(root);
    print(root);
    cout << endl;
    vector<int> res = postOrder(root);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}