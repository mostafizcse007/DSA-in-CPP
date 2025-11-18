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
int main()
{
    Node *p1 = new Node(100);
    Node *p2 = new Node(200);
    Node *p3 = new Node(300);
    p1->prev = nullptr;
    p1->next = p2;
    p2->prev = p1;
    p2->next = p3;
    p3->prev = p2;
    p3->next = nullptr;
    cout << p1->data << " " << p2->data << " " << p3->data << endl;
    cout << p1->data << " " << p1->next->data << " " << p1->next->next->data << endl;
    cout << p3->prev->prev->data << " " << p3->prev->data << " " << p3->data << endl;
    return 0;
}