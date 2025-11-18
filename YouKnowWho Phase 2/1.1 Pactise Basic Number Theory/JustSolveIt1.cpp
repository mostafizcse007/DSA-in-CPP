#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
vector<int> spf(N, 0);
#define ll long long
void preCompute()
{
    for (int i = 2; i < N; i++)
        spf[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i; j < N; j += i)
                spf[j] = min(spf[j], i);
        }
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
        cout << spf[n] << " ";
        int dis_prime = 0, gpf = 0, total_prime = 0, total_div = 1;
        ll sum_div = 1;
        while (n > 1)
        {
            int prime = spf[n];
            dis_prime++;
            gpf = max(gpf, prime);
            int exp = 0, prime_pow = 1;
            while (n % prime == 0)
            {
                total_prime++;
                exp++;
                prime_pow *= prime;
                n /= prime;
            }
            total_div *= (exp + 1);
            sum_div *= ((1ll * prime_pow * prime - 1) / (prime - 1));
        }
        cout << gpf << ' ';
        cout << dis_prime << ' ';
        cout << total_prime << ' ';
        cout << total_div << ' ';
        cout << sum_div << endl;
    }
    return 0;
}