#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *y1 = new Node(arr[0]);
    cout << y1 << endl;
    cout << y1->data << " " << y1->next << endl;
    return 0;
}