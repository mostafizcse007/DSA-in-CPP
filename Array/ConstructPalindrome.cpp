#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<char, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    int cnt = 0;
    for (auto it : mpp)
    {
        if (it.second & 1)
            cnt++;
    }
    --cnt;
    if (cnt <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}