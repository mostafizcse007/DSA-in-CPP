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
Node *insertTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
        return newNode;
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
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
Node *OddEvenLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = odd->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main()
{
    Node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        int nodeVal;
        cin >> nodeVal;
        head = insertTail(head, nodeVal);
    }
    Print(head);
    head = OddEvenLL(head);
    Print(head);
    return 0;
}