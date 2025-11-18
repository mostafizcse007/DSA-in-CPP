#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> reArrange(vector<int> &arr)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            ans.push_back(arr[i]);
        ans.push_back(arr[i]);
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> res = reArrange(arr);
        cout << res.size() << '\n';
        for (auto x : res)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}