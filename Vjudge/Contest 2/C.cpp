#include <bits/stdc++.h>
using namespace std;
long long minOp(long long n, long long k)
{
    long long cnt = 0;
    while (n)
    {
        if (k == 1)
            return k;
        if (n % k != 0)
        {
            long long x = n % k;
            n -= x;
            cnt += x;
        }
        else if (n % k == 0)
        {
            n = n / k;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << minOp(n, k) << endl;
    }
    return 0;
}