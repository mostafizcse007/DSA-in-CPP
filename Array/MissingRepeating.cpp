#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mpp;
    int maxi = INT_MIN;
    for (auto it : arr)
        maxi = max(maxi, it);
    for (auto it : arr)
        mpp[it]++;
    int a = -1, b = -1;
    for (int i = 1; i <= maxi; i++)
    {
        if (mpp.find(i) == mpp.end())
        {
            a = i;
            break;
        }
    }
    for (auto it : mpp)
    {
        if (it.second > 1)
        {
            b = it.first;
            break;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}