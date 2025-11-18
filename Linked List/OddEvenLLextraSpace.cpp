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
    Node *temp = head;
    vector<int> arr;
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
        arr.push_back(temp->data);
    temp = head->next;
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
        arr.push_back(temp->data);
    temp = head;
    int i = 0;
    while (temp)
    {
        temp->data = arr[i];
        i++;
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
    head = OddEvenLL(head);
    Print(head);
    return 0;
}