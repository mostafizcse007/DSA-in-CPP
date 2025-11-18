#include <bits/stdc++.h>
using namespace std;
#define ll long long

int totalCnt(vector<int> &arr)
{
    int cnt = 0;
    unordered_map<int, int> mpp;
    for (auto x : arr)
        mpp[x]++;
    for (auto x : mpp)
        cnt += x.second / 2;
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << totalCnt(arr) << '\n';
    }
    return 0;
}