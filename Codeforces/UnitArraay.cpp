#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int minOp(vector<int> &arr)
{
    int n = arr.size(), pos_cnt = 0, neg_cnt = 0;
    for (auto x : arr)
    {
        if (x == 1)
            pos_cnt++;
        else
            neg_cnt++;
    }
    if (pos_cnt == n)
        return 0;
    int ans = 0;
    if (pos_cnt < neg_cnt)
        ans = ceil((double)n / 2) - pos_cnt;
    neg_cnt -= ans;
    if (neg_cnt & 1)
        return ans + 1;
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
        cout << minOp(arr) << '\n';
    }
    return 0;
}