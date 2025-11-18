#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> Seive(int n)
{
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 4; i <= n; i += 2)
        primes[i] = false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += 2 * i)
                primes[j] = false;
        }
    }
    return primes;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, x;
    cin >> n >> d >> x;
    int stP = 0, cnt = 0;
    vector<bool> primes = Seive(n);
    for (int i = d; i <= n; i++)
    {
        if (primes[i] && (i - stP) >= x)
        {
            cnt++;
            stP = i;
        }
    }
    cout << cnt << endl;
    return 0;
}