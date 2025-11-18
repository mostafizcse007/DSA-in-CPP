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
void insertatHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
void deleteatHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}
void deleteatTail(Node *&head)
{
    Node *sec_last = head;
    while (sec_last->next->next != NULL)
    {
        sec_last = sec_last->next;
    }
    Node *temp = sec_last->next;
    sec_last->next = NULL;
    free(temp);
}
void deleteatPosition(Node *&head, int pos)
{
    if (pos == 0)
    {
        deleteatHead(head);
        return;
    }
    int prev = 0;
    Node *mover = head;
    while (prev != pos - 1)
    {
        mover = mover->next;
        prev++;
    }
    Node *temp = mover->next;
    mover->next = mover->next->next;
    free(temp);
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
    insertatHead(head, 5);
    insertatHead(head, 4);
    insertatHead(head, 3);
    insertatHead(head, 2);
    insertatHead(head, 1);
    display(head);
    deleteatPosition(head, 2);
    display(head);
    return 0;
}