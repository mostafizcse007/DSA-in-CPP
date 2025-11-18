#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
Node *insertTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if (head == nullptr)
        return newNode;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
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
Node *intersectNode(Node *head1, Node *head2)
{
    map<Node *, bool> mpp;
    Node *temp = head1;
    while (temp)
    {
        mpp[temp] = true;
        temp = temp->next;
    }
    temp = head2;
    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    for (int i = 1; i <= 5; i++)
    {
        int val;
        cin >> val;
        head1 = insertTail(head1, val);
    }
    for (int i = 1; i <= 8; i++)
    {
        int val;
        cin >> val;
        head2 = insertTail(head2, val);
    }
    Print(head1);
    Print(head2);
    Node *ans = intersectNode(head1, head2);
    if (ans != nullptr)
        cout << "Intersection at node with data: " << ans->data << endl;
    else
        cout << "No intersection found." << endl;
    return 0;
}