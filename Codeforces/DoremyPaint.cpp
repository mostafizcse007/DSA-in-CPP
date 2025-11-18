#include <bits/stdc++.h>
using namespace std;
#define ll long long
int is_possible(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    for (auto x : arr)
        mpp[x]++;
    if (mpp.size() > 2)
        return false;
    if (mpp.size() == 1)
        return true;
    auto it = mpp.begin();
    int cnt1 = it->second;
    it++;
    int cnt2 = it->second;
    if (abs(cnt1 - cnt2) <= 1)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (is_possible(arr))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}