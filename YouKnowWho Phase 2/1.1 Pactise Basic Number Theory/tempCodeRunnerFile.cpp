#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;
#define ll long long
void Seive()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Seive();
    int t, cs = 0;
    cin >> t;
    // cout << primes.size();
    while (t--)
    {
        ll n;
        cin >> n;
        int divs = 1;
        for (auto x : primes)
        {
            if (1ll * x * x > n)
                break;
            int exp = 0;
            while (n % x == 0)
            {
                exp++;
                n /= x;
            }
            divs *= (exp + 1);
        }
        if (n > 1)
            divs *= 2;
        cout << "Case " << ++cs << ": " << --divs << endl;
    }
    return 0;
}