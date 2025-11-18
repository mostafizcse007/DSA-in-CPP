#include <bits/stdc++.h>
using namespace std;
vector<int> findIndex(vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        int index = target - arr[i];
        if (mpp.find(index) != mpp.end())
        {
            return {mpp[index], i};
        }
        mpp[arr[i]] = i;
    }
    return {-1, -1};
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> result = findIndex(arr, target);
    for (auto it : result)
        cout << it << " ";
    return 0;
}