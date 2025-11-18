#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int size, front, rear, cnt;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
        cnt = 0;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % size == front;
    }
    void enqueue(int val)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = val;
            cnt++;
        }
        else if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = val;
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
            if (front == rear)
            {
                front = rear = -1;
                cnt = 0;
            }
            else
            {
                front = (front + 1) % size;
                cnt--;
            }
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
        int cpy = cnt;
        while (cpy--)
        {
            int temp = start();
            cout << temp << " ";
            dequeue();
            enqueue(temp);
        }
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
    q.Print();
    return 0;
}