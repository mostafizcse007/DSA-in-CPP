#include <bits/stdc++.h>
using namespace std;
int findPivot(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= arr[0])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int binarySearch(vector<int> &arr, int left, int right, int target)
{
    int start = left, end = right;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int result(vector<int> &arr, int target)
{
    int pivot = findPivot(arr);
    int size = arr.size();
    if (target >= arr[pivot] && target <= arr[size - 1])
        return binarySearch(arr, pivot, size - 1, target);
    return binarySearch(arr, 0, pivot - 1, target);
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << result(arr, target);
    return 0;
}