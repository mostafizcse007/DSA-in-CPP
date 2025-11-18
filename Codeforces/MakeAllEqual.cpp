#include <bits/stdc++.h>
using namespace std;
int makeEqual(vector<int> &arr, int n)
{
    unordered_map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    int maxi = 0, final = 0;
    for (auto it : mpp)
    {
        if (it.second > maxi)
        {
            maxi = it.second;
        }
    }
    return n - maxi;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << makeEqual(arr, n) << endl;
    }
    return 0;
}