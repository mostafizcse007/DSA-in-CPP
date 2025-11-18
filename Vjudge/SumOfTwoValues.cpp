#include <bits/stdc++.h>
using namespace std;
#define ll long long
pair<int, int> findInd(vector<int> &arr, int x)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
        mpp[arr[i]] = i + 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = x - arr[i];
        if (mpp.find(val) != mpp.end() and i != mpp[val] - 1)
            return {i + 1, mpp[val]};
    }
    return {-1, -1};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pair<int, int> res = findInd(arr, x);
    if (res.first == -1)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << res.first << ' ' << res.second << '\n';
    return 0;
}