#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll minOp(int n, ll digit)
{
    int cur = 0, len = 0;
    while (1)
    {
        cur = (cur * 10 + digit) % n;
        len++;
        if (cur == 0)
            break;
    }
    return len;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n;
        ll digit;
        cin >> n >> digit;
        cout << "Case " << ++cs << ": " << (ll)minOp(n, digit) << endl;
    }
    return 0;
}