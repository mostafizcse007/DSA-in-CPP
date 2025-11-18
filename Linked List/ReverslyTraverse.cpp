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
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
void reverseTraverse(Node *&head)
{
    if (head == NULL)
        return;
    reverseTraverse(head->next);
    cout << head->data << "->";
}
int main()
{
    LinkedList ll;
    for (int i = 1; i <= 10; i++)
        ll.insertAtTail(i);
    ll.display();
    reverseTraverse(ll.head);
    return 0;
}