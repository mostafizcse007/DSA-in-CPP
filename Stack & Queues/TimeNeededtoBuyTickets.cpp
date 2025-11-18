#include <bits/stdc++.h>
using namespace std;
int minTime(vector<int> &arr, int n, int k)
{
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            time += min(arr[k], arr[i]);
        }
        else
            time += min(arr[k] - 1, arr[i]);
    }
    return time;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minTime(arr, n, k) << endl;
    return 0;
}