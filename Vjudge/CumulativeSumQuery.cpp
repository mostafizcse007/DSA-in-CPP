#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] += prefix[i - 1] + arr[i];
    while (q--)
    {
        int left, right;
        cin >> left >> right;
        if (left == 0)
            cout << prefix[right] << endl;
        else
            cout << prefix[right] - prefix[left - 1] << endl;
    }
    return 0;
}