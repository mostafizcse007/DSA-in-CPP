#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int lower_bound(vector<int> &arr, int val)
{
    int low = 0, high = arr.size() - 1, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= val)
        {
            ans = mid + 1;
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int q;
    cin >> q;
    while (q--)
    {
        int val;
        cin >> val;
        cout << lower_bound(arr, val) << '\n';
    }
    return 0;
}