#include <bits/stdc++.h>
using namespace std;
int N = 1e5 + 7;
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
    auto x = clock();
    PreCompute();
    for (int i = 2; i < N; i++)
        cout << spf[i] << " ";
    cout << endl;
    cerr << 1.0 * (clock() - x) / CLOCKS_PER_SEC * 1000;
    return 0;
}