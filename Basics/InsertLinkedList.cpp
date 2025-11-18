#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
Node *arrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
}