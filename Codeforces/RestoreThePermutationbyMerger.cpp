#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> restorePermute(vector<int> &arr, int n)
{
    unordered_map<int, int> mpp;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mpp.find(arr[i]) == mpp.end())
            ans.push_back(arr[i]);
        mpp[arr[i]]++;
        if (ans.size() == n)
            break;
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
        int n;
        cin >> n;
        vector<int> arr(2 * n);
        for (int i = 0; i < 2 * n; i++)
            cin >> arr[i];
        vector<int> ans = restorePermute(arr, n);
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}