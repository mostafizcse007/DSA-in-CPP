#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<ll> divSum(N + 1, 0);
#define ll long long
void preCompute()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
            divSum[j] += i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preCompute();
    for (int i = 1; i <= 10; i++)
        cout << divSum[i] << " ";
    return 0;
}