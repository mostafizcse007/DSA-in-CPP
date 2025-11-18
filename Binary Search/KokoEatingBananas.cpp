#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
        maxi = max(maxi, arr[i]);
    return maxi;
}
int TimeRequired(vector<int> &arr, int m)
{
    int totalTime = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalTime += ceil((double)arr[i] / (double)m);
    }
    return totalTime;
}
int BinarySearch(vector<int> &arr, int hour)
{
    int size = arr.size();
    int low = 1, high = findMax(arr), ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int reqTime = TimeRequired(arr, mid);
        if (reqTime <= hour)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    int n, hour;
    cin >> n >> hour;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << BinarySearch(arr, hour) << endl;
    return 0;
}