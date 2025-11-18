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
        for (int i = 0; i < n; i++)
            ++arr[i];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] % arr[i - 1] == 0)
                ++arr[i];
        }
        for (auto x : arr)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}