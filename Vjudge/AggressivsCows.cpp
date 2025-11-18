#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_possible(vector<int> &arr, int cows, int dist)
{
    int cnt = 1, last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= dist)
        {
            cnt++;
            last = arr[i];
        }
        if (cnt >= cows)
            return true;
    }
    return false;
}
int bin_search(vector<int> &arr, int cows)
{
    int n = arr.size();
    int low = arr[0], high = arr[n - 1], ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (is_possible(arr, cows, mid))
        {
            ans = mid;
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

    int t;
    cin >> t;
    while (t--)
    {
        int n, cows;
        cin >> n >> cows;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << bin_search(arr, cows) << '\n';
    }
    return 0;
}