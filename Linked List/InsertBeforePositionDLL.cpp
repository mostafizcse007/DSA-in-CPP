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
    if (arr.empty())
        return nullptr;
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
Node *insertBeforeHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        newNode->next = nullptr;
        newNode->back = nullptr;
        head = newNode;
        return head;
    }
    else
    {
        newNode->next = head;
        head->back = newNode;
        newNode->back = nullptr;
        head = newNode;
    }
    return head;
}
Node *insertBeforeTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        newNode->next = nullptr;
        newNode->back = nullptr;
        head = newNode;
        return head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->back = temp;
        newNode->next = nullptr;
    }
    return head;
}
Node *insertBeforePosition(Node *&head, int val, int k)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    if (k == 1 || head == nullptr)
    {
        return insertBeforeHead(head, val);
    }
    if (temp == nullptr)
    {
        return head;
    }
    Node *prev = temp->back;
    if (prev == nullptr)
    {
        head = insertBeforeHead(head, val);
        return head;
    }
    else
    {
        prev->next = newNode;
        newNode->back = prev;
        newNode->next = temp;
        temp->back = newNode;
    }
    return head;
}
int main()
{
    vector<int> arr(10, 100);
    Node *head = arrToDLL(arr);
    Print(head);
    head = insertBeforePosition(head, 500, 5);
    Print(head);
    return 0;
}