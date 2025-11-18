#include <bits/stdc++.h>
using namespace std;
#define ll long long
int bSearch(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
            return true;
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--)
    {
        int k;
        cin >> k;
        if (bSearch(arr, k))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}