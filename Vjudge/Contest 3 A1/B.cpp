#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, q;
    cin >> n >> q;
    vector<long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        ll sum = 0;
        for (int i = l; i < r; i++)
            sum += arr[i];
        cout << sum << endl;
    }
    return 0;
}