#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
        int mini = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
            mini = min(mini, arr[i] - arr[i - 1]);
        cout << mini << '\n';
    }
    return 0;
}