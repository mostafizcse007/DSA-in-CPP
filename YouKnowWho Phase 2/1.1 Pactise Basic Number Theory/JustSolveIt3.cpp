#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
vector<int> cnt(N, 0), mul(N, 0);
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            mul[i] += cnt[j];
    }
    for (int i = 1; i <= 1e6; i++)
        cout << mul[i] << ' ';
    cout << endl;
    return 0;
}