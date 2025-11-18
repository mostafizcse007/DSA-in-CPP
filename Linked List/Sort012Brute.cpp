#include <iostream>
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
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
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
Node *Sort012(Node *head)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        int nodeVal;
        cin >> nodeVal;
        head = insertTail(head, nodeVal);
    }
    Print(head);
    head = Sort012(head);
    Print(head);
    return 0;
}