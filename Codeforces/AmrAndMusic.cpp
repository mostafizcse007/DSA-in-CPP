#include <bits/stdc++.h>
using namespace std;
vector<int> maxConsume(vector<int> &arr, int k)
{
    vector<pair<int, int>> temp;
    for (int i = 0; i < arr.size(); i++)
        temp.push_back(make_pair(arr[i], i + 1));
    sort(temp.begin(), temp.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
            if(a.first==b.first)
            return a.second<b.second;
            return a.first<b.first; });
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        sum += temp[i].first;
        if (sum <= k)
            ans.push_back(temp[i].second);
        else
            break;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = maxConsume(arr, k);
    if (res.size() == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    cout << res.size() << endl;
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}