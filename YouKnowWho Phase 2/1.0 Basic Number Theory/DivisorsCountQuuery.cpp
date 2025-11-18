#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> divs(N + 1, 0);
#define ll long long
void PreCompute()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
            divs[j]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto st = clock();
    PreCompute();
    for (int i = 1; i <= 100; i++)
        cout << divs[i] << " ";
    cout << endl;
    auto en = clock();
    cerr << 1.0 * (en - st) / CLOCKS_PER_SEC << endl;
    return 0;
}