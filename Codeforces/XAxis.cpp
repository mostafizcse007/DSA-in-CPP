#include <bits/stdc++.h>
using namespace std;
int smallValue(vector<int> &arr)
{
    int mini = INT_MAX;
    int i = 0;
    int limit = 3;
    while (limit--)
    {
        int final = abs(arr[0] - arr[i]) + abs(arr[1] - arr[i]) + abs(arr[2] - arr[i]);
        mini = min(mini, final);
        i++;
    }
    return mini;
}
int main()
{
    int t;
    cin >> t;
    vector<int> ans;
    while (t--)
    {
        vector<int> arr(3);
        for (int i = 0; i < 3; i++)
            cin >> arr[i];
        ans.push_back(smallValue(arr));
    }
    for (auto it : ans)
        cout << it << endl;
    return 0;
}