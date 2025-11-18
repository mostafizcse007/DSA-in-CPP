#include <bits/stdc++.h>
using namespace std;
#define ll long long
int find_val(vector<int> &arr)
{
    int n = arr.size();
    int val = 0;
    for (auto x : arr)
        val ^= x;
    if (n % 2 == 0)
    {
        if (val == 0)
            return 69;
        return -1;
    }
    return val;
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
        cout << find_val(arr) << '\n';
    }
    return 0;
}