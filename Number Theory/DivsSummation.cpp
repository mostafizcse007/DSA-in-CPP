#include <bits/stdc++.h>
using namespace std;
int N = 5e5 + 7;
vector<int> sums(N, 0);
#define ll long long
void preCompute()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            sums[j] += i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preCompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << sums[n] << endl;
    }
    return 0;
}