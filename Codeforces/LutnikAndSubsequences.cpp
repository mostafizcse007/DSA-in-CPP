#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll max_seq(vector<int> &arr)
{
    int cnt_zero = 0, cnt_one = 0;
    for (auto x : arr)
    {
        if (x == 0)
            cnt_zero++;
        else if (x == 1)
            cnt_one++;
    }
    if (cnt_one == 0 or cnt_zero == arr.size())
        return 0;
    if (cnt_zero == 0)
        return cnt_one;
    ll val = pow(2, cnt_zero);
    --val;
    return (val * cnt_one) + cnt_one;
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
        cout << 1ll * max_seq(arr) << '\n';
    }
    return 0;
}