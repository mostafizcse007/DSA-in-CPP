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
        ll n;
        cin >> n;
        if (n & 1)
            cout << 1 << '\n';
        else
        {
            int i = 1;
            while (n % i == 0)
                i++;
            cout << --i << '\n';
        }
    }
    return 0;
}