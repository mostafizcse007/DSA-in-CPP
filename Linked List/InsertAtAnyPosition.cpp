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
        this->next = NULL;
    }
};
void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
void insertAtPosition(Node *&head, int val, int pos)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }
    Node *prev = nullptr;
    int curr_pos = 1;
    while (temp != nullptr && curr_pos < pos)
    {
        prev = temp;
        temp = temp->next;
        curr_pos++;
    }
    if (temp == nullptr)
    {
        cout << "Out of range" << endl;
        return;
    }
    new_node->next = temp;
    prev->next = new_node;
    return;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);
    insertAtPosition(head, 100, 6);
    display(head);
    return 0;
}