#include <bits/stdc++.h>
using namespace std;
int minLength(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    if (mpp.size() == 1)
        return n;
    return 1;
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
        cout << minLength(arr) << endl;
    }
    return 0;
}