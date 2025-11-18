#include <bits/stdc++.h>
using namespace std;
#define ll long long
int min_ops(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
    {
        if (arr[0] == 0)
            return 0;
        return 1;
    }
    int cnt = 0, st = 0, i = 1;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            if (i - st > 1)
                cnt++;
            st = i;
        }
        i++;
    }
    if (cnt > 2)
        return 2;
    return cnt;
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
        vector<int> arr(n + 1);
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        arr.push_back(0);
        cout << min_ops(arr) << '\n';
    }
    return 0;
}