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
        int a, b;
        cin >> a >> b;
        int val = abs(a - b);
        val = ceil(double(val) / 10);
        cout << val << '\n';
    }
    return 0;
}