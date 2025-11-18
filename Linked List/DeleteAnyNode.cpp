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
void insertTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    return;
}
void PrintList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node *delAnyPos(Node *&head, int pos)
{
    Node *temp = head;
    if (head == nullptr || pos < 1)
        return nullptr;
    else if (pos == 1)
    {
        head = temp->next;
        delete temp;
        return head;
    }
    Node *prev = nullptr;
    int curr_pos = 1;
    while (temp != nullptr && curr_pos < pos)
    {
        prev = temp;
        temp = temp->next;
        curr_pos++;
    }
    prev->next = temp->next;
    return head;
}
int main()
{
    Node *head = nullptr;
    for (int i = 1; i <= 10; i++)
    {
        insertTail(head, i);
    }
    PrintList(head);
    head = delAnyPos(head, 10);
    PrintList(head);
}