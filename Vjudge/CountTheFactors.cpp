#include <bits/stdc++.h>
using namespace std;
int N = 1e6;
vector<int> spf(N + 10, 0);
#define ll long long
void preCompute()
{
    for (int i = 2; i < N; i++)
        spf[i] = i;
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            spf[j] = min(spf[j], i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preCompute();
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int cpy = n;
        unordered_set<int> st;
        while (n > 1)
        {
            st.insert(spf[n]);
            n /= spf[n];
        }
        cout << cpy << " : " << st.size() << endl;
    }
    return 0;
}