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
        next = NULL;
    }
};
// class LinkedList
// {
// public:
//     Node *head;
//     LinkedList()
//     {
//         head = NULL;
//     }
//     void insertTail(int val)
//     {
//         Node *newNode = new Node(val);
//         if (head == NULL)
//             head = newNode;
//         else
//         {
//             Node *temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }
//     void Display()
//     {
//         Node *temp = head;
//         while (temp)
//         {
//             cout << temp->data << "->";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// };
void insertTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
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
Node *insertKthPosition(Node *&head, int val, int pos)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        return NULL;
    }
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        if (cnt == pos - 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *head = NULL;
    for (int i = 1; i <= 10; i++)
        insertTail(head, i);
    Display(head);
    head = insertKthPosition(head, 4574, 5);
    Display(head);
    return 0;
}