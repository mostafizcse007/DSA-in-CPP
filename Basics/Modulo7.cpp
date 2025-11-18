#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x;
    cin >> x;
    x = ((x % 7) + 7) % 7;
    int mod1 = ((x % 7) * (x % 7)) % 7;
    mod1 *= 2;
    int ans1 = (mod1 % 7);
    int ans2 = ((11 % 7) * (x % 7)) % 7;
    cout << (ans1 + ans2) % 7 << endl;
    return 0;
}