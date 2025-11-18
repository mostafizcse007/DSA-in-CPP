#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    k %= arr.size();
    // LEFT reverse(arr.begin(), arr.begin() + k);
    // reverse(arr.begin() + k, arr.end());
    // reverse(arr.begin(), arr.end());

    // RIGHT reverse(arr.begin(), arr.end());
    // reverse(arr.begin(), arr.begin() + k);
    // reverse(arr.begin() + k, arr.end());
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}