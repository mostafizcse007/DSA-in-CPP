#include <bits/stdc++.h>
using namespace std;
const int N = 20000009;
vector<bool> primes(N, true);
#define ll long long
vector<pair<int, int>> store;

void preCompute()
{
    primes[0] = primes[1] = false;
    for (int i = 4; i < N; i += 2)
        primes[i] = false;
    for (int i = 3; i * i < N; i += 2)
    {
        if (primes[i])
        {
            for (int j = i * i; j < N; j += 2 * i)
                primes[j] = false;
        }
    }
    for (int i = 2; i < N - 2; i++)
    {
        if (primes[i] and primes[i + 2])
            store.push_back({i, i + 2});
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preCompute();
    int t;
    while (cin >> t and t != 0)
    {
        cout << "(" << store[t - 1].first << ", " << store[t - 1].second << ")" << endl;
    }
    return 0;
}