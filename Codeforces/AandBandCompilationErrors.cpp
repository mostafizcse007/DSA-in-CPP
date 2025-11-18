#include <bits/stdc++.h>
using namespace std;
pair<int, int> missingError(vector<int> &arr, vector<int> &brr, vector<int> &crr)
{
    unordered_map<int, int> m1, m2, m3;
    for (auto it : arr)
        m1[it]++;
    for (auto it : brr)
        m2[it]++;
    for (auto it : crr)
        m3[it]++;
    int n = arr.size();
    pair<int, int> ans;
    for (int i = 0; i < n; i++)
    {
        if (m1[arr[i]] != m2[arr[i]])
        {
            ans.first = arr[i];
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (m2[brr[i]] != m3[brr[i]])
        {
            ans.second = brr[i];
            break;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), brr(n - 1), crr(n - 2);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
        cin >> brr[i];
    for (int i = 0; i < n - 2; i++)
        cin >> crr[i];
    pair<int, int> ans = missingError(arr, brr, crr);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}