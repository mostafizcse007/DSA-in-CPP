#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 9;
#define ll unsigned long long
vector<ll> phi(N, 0);

void preCompute()
{
    for (int i = 0; i < N; i++)
        phi[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    for (int i = 1; i < N; i++)
        phi[i] = phi[i - 1] + 1ll * phi[i] * phi[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preCompute();
    int cs = 0, t;
    cin >> t;
    while (t--)
    {
        int low, high;
        cin >> low >> high;
        cout << "Case " << ++cs << ": " << phi[high] - phi[low - 1] << endl;
    }
    //cout << phi[N - 1] << endl;
    return 0;
}