#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(vector<int> &arr)
{
    long long sum = 0, large = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        large = max(large, sum);
        if (sum < 0)
            sum = 0;
    }
    return large;
}
int main()
{
    long long n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSubarraySum(arr) << endl;
    return 0;
}