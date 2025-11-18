#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<bool> primes(N + 1, true);
#define ll long long
void Seive()
{
    primes[0] = primes[1] = false;
    for (int i = 4; i <= N; i += 2)
        primes[i] = false;
    for (int i = 3; i <= N; i++)
    {
        if (primes[i])
        {
            for (ll j = (ll)i * i; j <= N; j += 2 * i)
                primes[j] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Seive();
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        ll num = round(sqrt(arr[i]));
        if (primes[num] && (ll)(num * num) == arr[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}