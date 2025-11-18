#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int min_val(vector<int> &arr)
{
    int min_gcd = INT_MAX;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = __gcd(arr[i], arr[j]);
            min_gcd = min(min_gcd, temp);
        }
    }
    return min_gcd;
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
        if (min_val(arr) <= 2)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}