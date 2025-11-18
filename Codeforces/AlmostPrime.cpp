#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
vector<int> spf(N, 0);
#define ll long long
void preCompute()
{
    for (int i = 2; i < N; i++)
        spf[i] = i;
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            spf[j] = min(i, spf[j]);
    }
}
bool twodiv(int n)
{
    unordered_set<int> st;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                st.insert(spf[i]);
                n /= spf[i];
            }
        }
    }
    if (n > 1)
        st.insert(n);
    if (st.size() == 2)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto x = clock();
    preCompute();
    int t;
    cin >> t;
    int cnt = 0;
    for (int i = 1; i <= t; i++)
    {
        if (twodiv(i))
            cnt++;
    }
    cout << cnt << endl;
    cerr << 1.0 * (clock() - x) / CLOCKS_PER_SEC << endl;
    return 0;
}