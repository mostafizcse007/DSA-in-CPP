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
        next = NULL;
        back = NULL;
    }
};
Node *arrToDLL(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = prev->next;
    }
    prev->next = NULL;
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
    vector<int> arr(10);
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    Node *head = arrToDLL(arr);
    Display(head);
    return 0;
}