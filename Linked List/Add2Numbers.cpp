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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node *sum2LL(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    Node *temp1 = head1;
    Node *temp2 = head2;
    int carry = 0;
    while (temp1 != nullptr || temp2 != nullptr)
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
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
    }
    if (carry)
    {
        Node *extra = new Node(carry);
        curr->next = extra;
    }
    return dummy->next;
}
int main()
{
    vector<int> arr1(5);
    vector<int> arr2(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cin >> arr2[i];
    }
    Node *head1 = arr2LL(arr1);
    Node *head2 = arr2LL(arr2);
    Print(head1);
    Print(head2);
    Node *ans = sum2LL(head1, head2);
    Print(ans);
    return 0;
}