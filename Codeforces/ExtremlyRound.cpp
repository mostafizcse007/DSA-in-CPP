#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
vector<int> arr(N, 0);
#define ll long long
void precompute()
{
    for (int i = 1; i < N; i++)
    {
        int cpy = i, cnt = 0;
        while (cpy)
        {
            if ((cpy % 10) != 0)
                cnt++;
            cpy /= 10;
        }
        if (cnt == 1)
            arr[i] = 1;
        arr[i] += arr[i - 1];
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
        cout << arr[n] << '\n';
    }
    return 0;
}