#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &arr, int target)
{
    int maxi = 0, sum = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == target)
            maxi = max(i + 1, maxi);
        else
        {
            if (mpp.find(sum) != mpp.end())
                maxi = max(maxi, i - mpp[sum]);
            else
                mpp[sum] = i;
        }
    }
    return maxi;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxLen(arr, target) << endl;
    return 0;
}