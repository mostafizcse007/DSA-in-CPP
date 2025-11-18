#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 9;
vector<int> arr(N);
void precompute()
{
    arr[0] = 2;
    arr[1] = 3;
    int i = 2;
    int x = N;
    while (i < N)
    {
        ll val = arr[i - 1] + arr[i - 2];
        ll big = arr[i - 1] + 1;
        arr[i] = big;
        if ((3 * big) % val == 0)
        {
            arr[i] += 1;
        }
        i++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto st = clock();
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC;
    return 0;
}