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
    // void insertAtHead(int val)
    // {
    //     if (head == NULL)
    //         head = new Node(val);
    //     else
    //     {
    //         Node *new_node = new Node(val);
    //         new_node->next = head;
    //         head = new_node;
    //     }
    // }
    void insertAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
            head = new_node;
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void Display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
Node *deleteHead(Node *&head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
int main()
{
    LinkedList ll;
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.Display();
    ll.head = deleteHead(ll.head);
    ll.Display();
}