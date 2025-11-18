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
        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; i++)
            cin >> arr[i];
        int sum = accumulate(arr.begin(), arr.end(), 0);
        cout << -1 * sum << '\n';
    }
    return 0;
}