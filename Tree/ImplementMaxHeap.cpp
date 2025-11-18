#include <iostream>
using namespace std;
class maxHeap
{
    int *arr;
    int size, totalSize;

public:
    maxHeap(int x)
    {
        totalSize = x;
        arr = new int[x];
        size = 0;
    }
    void insert(int val)
    {
        if (size == totalSize)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        int ind = size;
        arr[size] = val;
        size++;
        while (ind > 0 && arr[(ind - 1) / 2] < arr[ind])
        {
            swap(arr[(ind - 1) / 2], arr[ind]);
            ind = (ind - 1) / 2;
        }
        cout << arr[ind] << " pushed into maxHeap" << endl;
    }
    void Heapify(int ind)
    {
        int large = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        if (left < size && arr[left] > arr[large])
            large = left;
        if (right < size && arr[right] > arr[large])
            large = right;
        if (large != ind)
        {
            swap(arr[ind], arr[large]);
            Heapify(large);
        }
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        cout << arr[0] << " is deleted from heap" << endl;
        arr[0] = arr[size - 1];
        size--;
        if (size == 0)
            return;
        Heapify(0);
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    maxHeap h1(5);
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        h1.insert(n);
    }
    h1.Print();
    h1.Delete();
    h1.Print();
    return 0;
}