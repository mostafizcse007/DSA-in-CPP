#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<bool> primes(N, true);
vector<int> lp(N, 0), hp(N, 0);
#define ll long long

void Mark()
{
    primes[0] = primes[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (primes[i])
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                primes[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                    lp[j] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto st = clock();
    Mark();
    for (int i = 1; i <= 15; i++)
        cout << lp[i] << " " << hp[i] << endl;
    cerr << (1.0 * (clock() - st) / CLOCKS_PER_SEC) * 1000;
    return 0;
}