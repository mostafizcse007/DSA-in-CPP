#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (index == arr.size() - 1)
    {
        ans.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        helper(arr, ans, index + 1);
        swap(arr[i], arr[index]);
    }
}
vector<vector<int>> generatePermute(vector<int> &arr)
{
    vector<vector<int>> ans;
    int index = 0;
    helper(arr, ans, index);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> res = generatePermute(arr);
    for (auto it : res)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}