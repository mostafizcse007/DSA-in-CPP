#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool rearrange(vector<char> &arr, int k)
{
    bool flag = false;
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        if (arr[i] != arr[j])
        {
            flag = true;
            break;
        }
        i++;
        j--;
    }
    if (!flag)
        return 1;
    unordered_map<char, int> mpp;
    for (auto x : arr)
        mpp[x]++;
    int cnt_odd = 0;
    for (auto x : mpp)
    {
        if (x.second & 1)
            cnt_odd++;
    }
    if (cnt_odd <= k + 1)
        return 1;
    return 0;
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
        vector<char> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (rearrange(arr, k))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}