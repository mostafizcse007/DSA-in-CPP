#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
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
}
vector<int> preOrder(Node *root)
{
    if (root == nullptr)
        return {};
    stack<Node *> st;
    st.push(root);
    vector<int> ans;
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the root of the tree: ";
    cin >> n;
    Node *root = new Node(n);
    levelOrder(root);
    vector<int> res = preOrder(root);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}