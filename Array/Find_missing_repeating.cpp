#include <bits/stdc++.h>
using namespace std;
vector<int> MissingRepeating(vector<int> &arr)
{
    vector<int> ans;
    map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    for (int i = 1; i <= arr.size(); i++)
    {
        if (mpp.find(i) == mpp.end())
            ans.push_back(i);
        if (mpp[i] > 1)
        {
            ans.push_back(i);
            mpp[i]--;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = MissingRepeating(arr);
    for (auto it : res)
        cout << it << " ";
    return 0;
}