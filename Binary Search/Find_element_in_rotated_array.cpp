#include <bits/stdc++.h>
using namespace std;
int getPivot(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int binarySearch(vector<int> &arr, int s, int e, int k)
{
    int st = s, en = e;
    while (st <= en)
    {
        int mid = st + (en - st) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            st = mid + 1;
        else
            en = mid - 1;
    }
    return -1;
}

int search(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr);
    if (k >= arr[pivot] && k <= arr[n - 1])
        return binarySearch(arr, pivot, n - 1, k);
    return binarySearch(arr, 0, pivot - 1, k);
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << search(arr, n, k);
    return 0;
}