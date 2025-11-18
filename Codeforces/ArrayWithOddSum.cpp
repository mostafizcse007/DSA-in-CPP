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
        int even_cnt = 0, odd_cnt = 0;
        for (auto x : arr)
        {
            if (x & 1)
                odd_cnt++;
            else
                even_cnt++;
        }
        if (even_cnt and odd_cnt == 0)
            cout << "NO" << '\n';
        else if (odd_cnt % 2 == 0 and even_cnt == 0)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}