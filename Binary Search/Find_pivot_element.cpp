#include <bits/stdc++.h>
using namespace std;
int findPivot(vector<int> &arr)
{
    int st = 0, end = arr.size() - 1;
    while (st < end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] >= arr[0])
            st = mid + 1;
        else
            end = mid;
    }
    return st;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr.emplace_back(element);
    }
    cout << findPivot(arr);
}