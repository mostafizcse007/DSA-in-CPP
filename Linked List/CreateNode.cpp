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
        this->next = nullptr;
    }
};
int main()
{
    Node *n1 = new Node(454);
    cout << n1->data << " " << n1->next << endl;
    return 0;
}