#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int> &arr, int n, int ind)
{
    int large = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    if (left < n && arr[left] > arr[large])
        large = left;
    if (right < n && arr[right] > arr[large])
        large = right;
    if (ind != large)
    {
        swap(arr[ind], arr[large]);
        Heapify(arr, n, large);
    }
}
void BuildMaxHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
}
void HeapSort(vector<int> &arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}
void PrintHeap(vector<int> &arr)
{
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    BuildMaxHeap(arr, n);
    HeapSort(arr, n);
    PrintHeap(arr);
    return 0;
}