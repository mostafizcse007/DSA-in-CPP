#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        set<int> hashmap;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int third = -(arr[i] + arr[j]);
            if (hashmap.find(third) != hashmap.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashmap.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ans = threeSum(arr);
    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}