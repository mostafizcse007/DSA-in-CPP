#include <bits/stdc++.h>
using namespace std;
#define ll long long
int Cnt(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    for (auto it : mpp)
    {
        if (it.second >= 3)
            return it.first;
    }
    return -1;
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
        cout << Cnt(arr) << endl;
    }
    return 0;
}