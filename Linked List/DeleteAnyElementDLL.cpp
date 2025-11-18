#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
Node *arrToDLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *yesterday = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = yesterday;
        yesterday->next = temp;
        yesterday = yesterday->next;
    }
    yesterday->next = nullptr;
    return head;
}
Node *Print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node *removekthElement(Node *&head, int x)
{
    if (head == nullptr || x <= 0)
        return nullptr;
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == x)
            break;
        temp = temp->next;
    }
    if (x > cnt)
        return head;
    Node *yesterday = temp->prev;
    Node *front = temp->next;
    if (yesterday == nullptr && front == nullptr)
    {
        delete temp;
        return nullptr;
    }
    else if (yesterday == nullptr)
    {
        front->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        head = front;
        return head;
    }
    else if (front == nullptr)
    {
        yesterday->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }
    else
    {
        yesterday->next = front;
        front->prev = yesterday;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }
    return head;
}
int main()
{
    vector<int> arr(10);
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    Node *head = arrToDLL(arr);
    Print(head);
    head = removekthElement(head, 10);
    Print(head);
    return 0;
}