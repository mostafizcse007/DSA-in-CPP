#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int min_op(vector<int> &arr)
{
    int mini = INT_MAX;
    for (int i = 1; i < arr.size(); i++)
    {
        mini = min(mini, arr[i] - arr[i - 1]);
    }
    if (mini == 0)
        return 1;
    if (mini < 0)
        return 0;
    return mini / 2 + 1;
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
        cout << min_op(arr) << '\n';
    }
    return 0;
}