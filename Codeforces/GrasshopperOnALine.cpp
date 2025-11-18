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
        int n, k;
        cin >> n >> k;
        if (n % k == 0)
        {
            cout << 2 << '\n'
                 << --n << ' ' << 1 << '\n';
        }
        else
            cout << 1 << '\n'
                 << n << '\n';
    }
    return 0;
}