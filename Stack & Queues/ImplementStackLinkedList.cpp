#include <bits/stdc++.h>
using namespace std;
class NodeStack
{
public:
    int data;
    NodeStack *next;
    NodeStack(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
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
class Stack
{
public:
    NodeStack *head;
    int stackSize;
    Stack()
    {
        head = nullptr;
        stackSize = 0;
    }
    void push(int val)
    {
        NodeStack *newNode = new NodeStack(val);
        newNode->next = head;
        head = newNode;
        cout << "Element " << val << " pushed to the stack" << endl;
        stackSize++;
    }
    void pop()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        NodeStack *temp = head;
        cout << "Element " << temp->data << " poped from the stack" << endl;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        stackSize--;
    }
    int view()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }
    int size()
    {
        return stackSize;
    }
    bool isEmpty()
    {
        if (head == nullptr)
            return true;
        return false;
    }
    void Print()
    {
        NodeStack *temp = head;
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
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
        cout << "Element " << data << " enqueued in the Queue" << endl;
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
        cout << "Element " << temp->data << " dequeued from the queue" << endl;
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
    Stack s1;
    Queue q1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.dequeue();
    cout << "Top of the stack " << s1.view() << endl;
    cout << "Front of the queue " << q1.view() << endl;
    return 0;
}