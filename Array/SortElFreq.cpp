#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int> sortByFreq(vector<int> &arr)
{
    map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    vector<pair<int, int>> store;
    for (auto it : mpp)
        store.push_back(make_pair(it.first, it.second));
    sort(store.begin(), store.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second; });
    vector<int> ans;
    for (int i = 0; i < store.size(); i++)
    {
        while (store[i].second--)
            ans.push_back(store[i].first);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> res = sortByFreq(arr);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}