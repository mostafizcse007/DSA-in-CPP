#include <bits/stdc++.h>
using namespace std;
#define ll long long
int min_fuel(vector<int> &arr, int x)
{
    if (arr.size() == 1)
        return max(arr[0], (x - arr[0]) * 2);
    int val1 = arr[0];
    for (int i = 1; i < arr.size(); i++)
        val1 = max(val1, arr[i] - arr[i - 1]);
    val1 = max(val1, (x - arr[arr.size() - 1]) * 2);
    return val1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << min_fuel(arr, x) << '\n';
    }
    return 0;
}