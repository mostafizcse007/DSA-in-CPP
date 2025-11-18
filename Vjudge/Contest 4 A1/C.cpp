#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(ll s, vector<pair<int, int>> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (s > arr[i].first)
        {
            s += arr[i].second;
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll s, n;
    cin >> s >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    if (isPossible(s, arr))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}