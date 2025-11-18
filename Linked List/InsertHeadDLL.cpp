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
Node *insertHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
        return newNode;
    else
    {
        newNode->next = head;
        head->back = newNode;
        head = newNode;
    }
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
int main()
{
    Node *head = nullptr;
    for (int i = 1; i <= 10; i++)
        head = insertHead(head, i);

    Display(head);
    return 0;
}