#include <bits/stdc++.h>
using namespace std;
int lowHeight(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < k)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int upHeight(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > k)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        int low = lowHeight(arr, q);
        int up = upHeight(arr, q);
        if (low != -1)
            cout << low << " ";
        else
            cout << 'X' << " ";
        if (up != -1)
            cout << up << endl;
        else
            cout << 'X' << endl;
    }
    return 0;
}