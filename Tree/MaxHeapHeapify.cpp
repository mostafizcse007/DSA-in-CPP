#include <iostream>
#include <vector>
using namespace std;
// void Heapify(vector<int> &arr, int n, int ind)
// {
//     int large = ind;
//     int left = 2 * ind + 1;
//     int right = 2 * ind + 2;
//     if (left < n && arr[left] > arr[large])
//         large = left;
//     if (right < n && arr[right] > arr[large])
//         large = right;
//     if (ind != large)
//     {
//         swap(arr[large], arr[ind]);
//         Heapify(arr, n, large);
//     }
// }
void Heapify(vector<int> &arr, int n, int ind)
{
    int large = ind;

    while (true)
    {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        if (left < n && arr[left] > arr[large])
            large = left;
        if (right < n && arr[right] > arr[large])
            large = right;
        if (large != ind)
        {
            swap(arr[ind], arr[large]);
            ind = large;
        }
        else
        {
            break;
        }
    }
}

void buildHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
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
    buildHeap(arr, n);
    PrintHeap(arr);
    return 0;
}