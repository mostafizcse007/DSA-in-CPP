#include <bits/stdc++.h>
using namespace std;
int NumberOfRotation(const vector<int> &arr, int n)
{
    int low = 0, high = n - 1, ans = INT_MAX, index = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low++;
            high--;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        v.emplace_back(el);
    }
    cout << NumberOfRotation(v, n) << endl;
    return 0;
}