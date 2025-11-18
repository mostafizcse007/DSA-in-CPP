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

Node *reverseLL(Node *&head)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    while (currptr != NULL)
    {
        Node *next_ptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = next_ptr;
    }
    Node *new_head = prevptr;
    return new_head;
}
Node *reverseLLRecursion(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *new_head = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main()
{
    LinkedList ll;
    for (int i = 1; i <= 10; i++)
        ll.insertAtTail(i);
    ll.display();
    ll.head = reverseLLRecursion(ll.head);
    ll.display();
    ll.head = reverseLL(ll.head);
    ll.display();
    return 0;
}
