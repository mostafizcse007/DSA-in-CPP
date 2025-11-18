#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
Node *arrToLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = prev->next;
    }
    prev->next = nullptr;
    return head;
}
void Print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node *reverseLL(Node *head)
{
    Node *temp1 = head;
    Node *temp2 = head;
    stack<int> st;
    while (temp1)
    {
        st.push(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2)
    {
        temp2->data = st.top();
        st.pop();
        temp2 = temp2->next;
    }
    return head;
}
int main()
{
    vector<int> arr(10);
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    Node *head = arrToLL(arr);
    Print(head);
    head = reverseLL(head);
    Print(head);
    return 0;
}