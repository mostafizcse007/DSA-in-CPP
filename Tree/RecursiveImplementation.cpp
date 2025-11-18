#include <iostream>
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
void helper(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->data);
    helper(root->left, ans);
    helper(root->right, ans);
}
vector<int> preOrder(Node *root)
{
    if (!root)
        return {};
    vector<int> ans;
    helper(root, ans);
    return ans;
}
int main()
{
    cout << "Enter root node: ";
    Node *root = nullptr;
    root = binaryTree();
    vector<int> res = preOrder(root);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}