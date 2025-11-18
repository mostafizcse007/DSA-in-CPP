#include <bits/stdc++.h>
using namespace std;
int getMaxi(vector<int> &arr)
{
    int count = 0, maxi = 0;
    for (auto it : arr)
    {
        if (it == 0)
        {
            count++;
        }
        else
            count = 0;
        maxi = max(maxi, count);
    }
    return maxi;
}
int main()
{
    int t;
    cin >> t;
    vector<int> ans;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        ans.push_back(getMaxi(arr));
    }
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}