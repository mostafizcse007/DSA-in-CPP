#include <bits/stdc++.h>
using namespace std;
vector<int> Majority_n_3(vector<int> &arr)
{
    int min = (arr.size() / 3) + 1;
    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
        if (mpp[arr[i]] == min)
        {
            ans.emplace_back(arr[i]);
        }
        else if (ans.size() == 2)
            break;
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
    vector<int> res = Majority_n_3(arr);
    for (auto it : res)
        cout << it << " ";
    return 0;
}