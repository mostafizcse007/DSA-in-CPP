#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e4 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;
#define ll long long
void preCompute()
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
    preCompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int divs = 1;
        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i] > n)
                break;
            int exp = 0;
            for (int j = primes[i]; j <= n; j += primes[i])
            {
                int temp = j;
                while (temp % primes[i] == 0)
                {
                    exp++;
                    temp /= primes[i];
                }
            }
            divs = 1ll * divs * (exp + 1) % mod;
        }
        cout << divs << endl;
    }
    return 0;
}