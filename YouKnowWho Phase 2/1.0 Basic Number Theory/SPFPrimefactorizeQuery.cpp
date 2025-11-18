#include <bits/stdc++.h>
using namespace std;
int N = 1e4 + 7;
vector<bool> primes(N + 1, 1);
vector<int> spf(N + 1, 0);
#define ll long long
void PreCompute()
{
    for (int i = 2; i < N; i++)
        spf[i] = i;
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            spf[j] = min(spf[j], i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto st = clock();
    PreCompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        while (n > 1)
        {
            ans.push_back(spf[n]);
            n /= spf[n];
        }
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
    return 0;
}