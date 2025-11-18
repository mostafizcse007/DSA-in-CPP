#include <bits/stdc++.h>
using namespace std;
int countNumber(vector<int> &arr)
{
    if (arr.size() < 3)
        return -1;
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << countNumber(arr) << endl;
    }
    return 0;
}