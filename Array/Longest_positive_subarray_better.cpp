#include <bits/stdc++.h>
using namespace std;
int maxSubarray(vector<int> &arr, int target)
{
    int sum = 0, maxLen = 0;
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == target)
            maxLen = max(maxLen, i + 1);
        int rem = sum - target;
        if (mpp.find(rem) != mpp.end())
        {
            int len2 = i - mpp[rem];
            maxLen = max(len2, maxLen);
        }
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }
    return maxLen;
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
    cout << maxSubarray(arr, target) << endl;
    return 0;
}