#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
vector<int> divs(N, 0);
#define ll long long
void precompute()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            divs[j]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << divs[n] << '\n';
    }
    return 0;
}