#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int *arr;
    int front, rear, size;
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return rear == size - 1;
    }
    void push(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
        }
        else if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
            ++front;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
            return arr[front];
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(10);
    for (int i = 1; i <= 10; i++)
        q.push(i);
    q.print();
    return 0;
}