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
        next = nullptr;
    }
};
class Queue
{
    Node *front, *rear;
    int cnt;

public:
    Queue()
    {
        front = rear = nullptr;
        cnt = 0;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            front = rear = newNode;
            cnt++;
        }
        else
        {
            rear->next = newNode;
            rear = rear->next;
            cnt++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            cnt--;
            return;
        }
    }
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    int queueSize()
    {
        return cnt;
    }
};
int main()
{
    Queue q1;
    // q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    cout << q1.queueSize() << endl;
    cout << q1.start() << endl;
    return 0;
}