#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        back = nullptr;
    }
};
Node *arrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = prev->next;
    }
    prev->next = nullptr;
    return head;
}
void Display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node *reverseDLL(Node *head)
{
    Node *temp1 = head;
    stack<int> st;
    while (temp1)
    {
        st.push(temp1->data);
        temp1 = temp1->next;
    }
    Node *temp2 = head;
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
    Node *head = arrToDLL(arr);
    Display(head);
    head = reverseDLL(head);
    Display(head);
    return 0;
}