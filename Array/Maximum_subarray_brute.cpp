#include <bits/stdc++.h>
using namespace std;
int maximumSubarrayLength(vector<int> &arr, int target)
{
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == target)
            {
                int len = j - i + 1;
                maxi = max(maxi, len);
            }
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
    cout << maximumSubarrayLength(arr, target) << endl;
    return 0;
}