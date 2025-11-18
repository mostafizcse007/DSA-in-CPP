#include <bits/stdc++.h>
using namespace std;
int countSubarrays(vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int presum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        presum += arr[i];
        int remove = presum - target;
        count += mpp[remove];
        mpp[presum]++;
    }
    return count;
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
    cout << countSubarrays(arr, target) << endl;
    return 0;
}