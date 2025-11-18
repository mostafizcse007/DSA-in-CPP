#include <bits/stdc++.h>
using namespace std;
int oddFound(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    for (auto it : mpp)
    {
        if (it.second & 1)
            return it.first;
    }
    return -1;
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
        cout << oddFound(arr) << endl;
    }
    return 0;
}