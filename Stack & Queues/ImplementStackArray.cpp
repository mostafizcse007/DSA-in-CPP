#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack Overflow" << endl;
    }
    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "Stack Underflow" << endl;
    }
    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
            return -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
    int totalSize()
    {
        return top + 1;
    }
    void printStack()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements from top to bottom: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack st(3);
    return 0;
}
