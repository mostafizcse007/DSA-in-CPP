#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data1, data2;
    Node *next;
    Node(int data1, int data2)
    {
        this->data1 = data1;
        this->data2 = data2;
        next = nullptr;
    }
};
Node *arrtoLL(vector<int> &arr1, vector<int> &arr2)
{
    if (arr1.size() == 0)
        return NULL;
    Node *head = new Node(arr1[0], arr2[0]);
    Node *prev = head;
    for (int i = 1; i < arr1.size(); i++)
    {
        Node *temp = new Node(arr1[i], arr2[i]);
        prev->next = temp;
        prev = prev->next;
    }
    prev->next = nullptr;
    return head;
}
void Print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << "(" << temp->data1 << " , " << temp->data2 << ")" << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node *sortList(Node *head)
{
    if (!head || !head->next)
        return head;
    vector<tuple<int, int>> nodes;
    Node *temp = head;
    while (temp)
    {
        nodes.push_back(make_tuple(temp->data1, temp->data2));
        temp = temp->next;
    }
    sort(nodes.begin(), nodes.end(), [](const tuple<int, int> &a, const tuple<int, int> &b)
         { return get<1>(a) < get<1>(b); });
    Node *newHead = new Node(get<0>(nodes[0]), get<1>(nodes[0]));
    Node *current = newHead;
    for (size_t i = 1; i < nodes.size(); i++)
    {
        current->next = new Node(get<0>(nodes[i]), get<1>(nodes[i]));
        current = current->next;
    }
    return newHead;
}
int main()
{
    vector<int> arr1, arr2;
    for (int i = 0; i < 10; i++)
    {
        arr1.push_back(i + 1);
        arr2.push_back(10 - i);
    }
    Node *head = arrtoLL(arr1, arr2);
    Print(head);
    head = sortList(head);
    Print(head);
}