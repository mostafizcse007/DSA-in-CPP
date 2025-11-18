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
Node *deleteDLLtail(Node *&head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return head;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
int main()
{
    vector<int> arr(10);
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    Node *head = arrToDLL(arr);
    Display(head);
    head = deleteDLLtail(head);
    Display(head);
    return 0;
}