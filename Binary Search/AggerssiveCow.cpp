#include <bits/stdc++.h>
using namespace std;
#define ll long long
int optimalCnt(vector<int> &arr, int n, int val)
{
    int low = arr[0], high = arr[n - 1];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int cnt = 1;
        int prev = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - prev >= mid)
            {
                prev = arr[i];
                cnt++;
            }
            if (cnt == n)
                break;
        }
        if (cnt = n)
            low = mid;
        else
            high = mid;
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << optimalCnt(arr, n, m) << '\n';
    }
    return 0;
}