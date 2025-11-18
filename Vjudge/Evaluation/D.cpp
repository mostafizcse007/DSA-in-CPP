#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, k;
    cin >> q >> k;
    map<string, ll> mpp;
    while (q--)
    {
        string str;
        int val;
        cin >> str >> val;
        mpp[str] += val;
    }
    vector<ll> vals;
    for (auto it : mpp)
    {
        vals.push_back(it.second);
    }
    ll sum = 0;
    int i = 0;
    sort(vals.rbegin(), vals.rend());
    while (i < k and i < vals.size())
    {
        sum += vals[i];
        i++;
    }
    cout << sum << '\n';
    return 0;
}