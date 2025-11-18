#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline bool is_possible(vector<int> &arr)
{
    int sum = 0;
    sum = accumulate(arr.begin(), arr.end(), 0);
    for (auto x : arr)
    {
        int temp = sum - x;
        if (((temp & 1) and (x & 1)) or ((temp % 2 == 0) and (x % 2 == 0)))
            return true;
    }
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