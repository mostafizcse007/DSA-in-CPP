#include <bits/stdc++.h>
using namespace std;
#define ll long long
int lowerBound(vector<int> &arr, int val, map<int, int> &mpp)
{
    int low = 0, high = arr.size() - 1, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= val and mpp[arr[mid]])
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n), brr(m);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> brr[i];
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
        mpp[arr[i]]++;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < m; i++)
    {
        int val = lowerBound(arr, brr[i], mpp);
        if (val == 0)
            cout << -1 << '\n';
        else if (mpp[val])
        {
            cout << val << '\n';
            --mpp[arr[i]];
        }
        else
            cout << -1 << '\n';
    }
    return 0;
}