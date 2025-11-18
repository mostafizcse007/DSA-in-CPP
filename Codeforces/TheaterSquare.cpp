#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long m, n, a;
    cin >> m >> n >> a;
    long long ans = ceil(double(m) / a) * ceil(double(n) / a);
    cout << ans << endl;
    return 0;
}