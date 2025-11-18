#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int front, rear, size;

public:
    Queue(int size)
    {
        this->size = size;
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
    void enqueue(int val)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = val;
        }
        else if (isFull())
        {
            cout << "Queue is overflow" << endl;
            return;
        }
        else
        {
            rear++;
            arr[rear] = val;
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
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    void Print()
    {
        int cpy = front;
        while (cpy <= rear)
        {
            if (isEmpty())
            {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << arr[cpy] << " ";
            cpy++;
        }
        cout << endl;
    }
    int stackSize()
    {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.enqueue(6);

    return 0;
}