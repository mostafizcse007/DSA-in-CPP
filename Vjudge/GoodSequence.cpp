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
    unordered_map<int, int> mpp;
    for (auto x : arr)
        mpp[x]++;
    int sum = 0;
    for (auto x : mpp)
    {
        if (x.first > x.second)
            sum += x.second;
        if (x.first < x.second)
            sum += (x.second - x.first);
    }
    cout << sum << '\n';
    return 0;
}