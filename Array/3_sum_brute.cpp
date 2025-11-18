#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &arr)
{

    set<vector<int>> uni;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    uni.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(uni.begin(), uni.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> res = threeSum(arr);
    for (auto it : res)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}