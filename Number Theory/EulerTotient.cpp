#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
vector<int> spf(N, 0);
#define ll long long
void preCompute()
{
    for (int i = 2; i < N; i++)
        spf[i] = i;
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            spf[j] = min(spf[j], i);
    }
}
vector<int> primeFact(int n)
{
    unordered_set<int> st;
    while (n > 1)
    {
        st.insert(spf[n]);
        n /= spf[n];
    }
    vector<int> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto x = clock();
    preCompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
            cout << 1 << endl;
        else
        {
            vector<int> primes = primeFact(n);
            double ans = 1;
            for (int i = 0; i < primes.size(); i++)
            {
                ans *= ((double)(primes[i] - 1) / (double)primes[i]);
            }
            ans *= n;
            cout << ans << endl;
        }
    }
    cerr << 1.0 * (clock() - x) / CLOCKS_PER_SEC << endl;
    return 0;
}