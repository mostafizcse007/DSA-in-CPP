#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int butt, k;
    while (cin >> butt >> k)
    {
        int ans = butt;
        while (butt >= k)
        {
            int temp = butt / k;
            ans += temp;
            butt = temp + (butt % k);
        }
        cout << ans << endl;
    }
    return 0;
}