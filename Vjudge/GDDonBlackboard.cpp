#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int odd_cnt = 0, even_cnt = 0;
    for (auto x : arr)
    {
        if (x & 1)
            odd_cnt++;
        else
            even_cnt++;
    }
    if (n == 2 and arr[0] == arr[1])
        cout << arr[0] << '\n';
    else if (abs(odd_cnt - even_cnt) > 1)
        cout << 1 << '\n';
    else if (odd_cnt == 1)
    {
        int gcd = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                gcd = __gcd(gcd, arr[i]);
        }
        cout << gcd << '\n';
    }
    else if (even_cnt == 1)
    {
        int gcd = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & 1)
                gcd = __gcd(gcd, arr[i]);
        }
        cout << gcd << '\n';
    }
    return 0;
}