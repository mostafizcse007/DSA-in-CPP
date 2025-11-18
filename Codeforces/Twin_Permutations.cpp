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
        int n, a, b;
        cin >> n >> a >> b;

        if ((a + b + 2 <= n) || (a == b && b == n))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}