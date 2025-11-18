#include <bits/stdc++.h>
using namespace std;
int maxA1(vector<int> &arr, vector<int> &brr, int k)
{
    sort(arr.begin(), arr.end());
    sort(brr.rbegin(), brr.rend());
    for (int i = 0; i < k; i++)
    {
        if (brr[i] > arr[i])
            swap(arr[i], brr[i]);
    }
    int sum = 0;
    for (auto it : arr)
        sum += it;
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), brr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> brr[i];
        cout << maxA1(arr, brr, k) << endl;
    }
    return 0;
}