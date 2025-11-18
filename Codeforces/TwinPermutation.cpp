#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> re_order(vector<int> &arr)
{
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    int val = mini + maxi;
    vector<int> ans;
    for (auto x : arr)
    {
        ans.push_back(val - x);
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
        vector<int> res = re_order(arr);
        for (auto x : res)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}