#include <bits/stdc++.h>
using namespace std;
#define ll long long
int min_removal(vector<int> &arr, int k)
{
    int size = arr.size();
    if (size == 1)
        return 0;
    int maxi = -1, cnt = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] - arr[i - 1] <= k)
            cnt++;
        else
            cnt = 1;
        maxi = max(maxi, cnt);
    }
    return arr.size() - maxi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << min_removal(arr, k) << '\n';
    }
    return 0;
}