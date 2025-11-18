#include <iostream>
using namespace std;
class NodeQueue
{
public:
    int data;
    NodeQueue *next;

    NodeQueue(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{
public:
    NodeQueue *front;
    NodeQueue *rear;
    int size;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {
        NodeQueue *newNode = new NodeQueue(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        int data = front->data;
        NodeQueue *temp = front;
        front = front->next;
        delete temp;
        size--;
        if (isEmpty())
        {
            rear = nullptr;
        }
        return data;
    }

    int view()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        NodeQueue *current = front;
        cout << "Queue: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    return 0;
}
