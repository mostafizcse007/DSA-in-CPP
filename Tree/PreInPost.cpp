#include <iostream>
#include <stack>
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
    cout << "Enter left child of " << x << " : ";
    temp->left = binaryTree();
    cout << "Enter right child of " << x << " : ";
    temp->right = binaryTree();
    return temp;
}
vector<vector<int>> PreInPost(Node *root)
{
    if (!root)
        return {};
    vector<vector<int>> ans;
    stack<pair<Node *, int>> st;
    vector<int> preOrder, inOrder, postOrder;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else
            postOrder.push_back(it.first->data);
    }
    ans.push_back(preOrder);
    ans.push_back(inOrder);
    ans.push_back(postOrder);
    return ans;
}
int main()
{
    Node *root = nullptr;
    cout << "Enter root node: ";
    root = binaryTree();
    vector<vector<int>> res = PreInPost(root);
    for (auto it : res)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}