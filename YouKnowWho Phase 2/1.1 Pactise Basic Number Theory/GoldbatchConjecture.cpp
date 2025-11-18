#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
bitset<N> primes;
#define ll long long
void preCompute()
{
    primes[1] = false;
    for (int i = 2; i < N; i++)
        primes[i] = true;
    for (int i = 2; i * i < N; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j < N; j += i)
                primes[j] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preCompute();
    int t, x = 1;
    cin >> t;
    vector<int> facts;
    for (int i = 1; i < N; i++)
    {
        if (primes[i])
            facts.push_back(i);
    }
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (auto it : facts)
        {
            if (it > n)
                break;
            int extra = n - it;
            if (primes[extra] && it <= extra)
                cnt++;
        }
        cout << "Case " << x << ": " << cnt << endl;
        x++;
    }
    return 0;
}