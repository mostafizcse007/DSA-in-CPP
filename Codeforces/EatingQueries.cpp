#include <bits/stdc++.h>
using namespace std;
#define ll long long
int findInd(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid + 1;
        else if (arr[mid] > x)
        {
            ans = mid + 1;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        while (q--)
        {
            int x;
            cin >> x;
            cout << findInd(arr, x) << endl;
        }
    }
    return 0;
}
