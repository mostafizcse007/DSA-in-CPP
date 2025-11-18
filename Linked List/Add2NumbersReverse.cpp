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
Node *arr2LL(vector<int> &arr)
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
Node *add2LL(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);
    Node *temp1 = head1;
    Node *temp2 = head2;
    int carry = 0;
    while (temp1 || temp2)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2)
        {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        Node *newNode = new Node(sum % 10);
        curr->next = newNode;
        curr = curr->next;
        carry = sum / 10;
    }
    if (carry)
    {
        Node *extra = new Node(carry);
        curr->next = extra;
    }
    Node *head = dummy->next;
    head = reverseLL(head);
    return head;
}
int main()
{
    vector<int> arr1(2);
    vector<int> arr2(3);
    for (int i = 0; i < 2; i++)
        cin >> arr1[i];
    for (int i = 0; i < 3; i++)
        cin >> arr2[i];
    Node *head1 = arr2LL(arr1);
    Node *head2 = arr2LL(arr2);
    Node *head = add2LL(head1, head2);
    Print(head);
    return 0;
}