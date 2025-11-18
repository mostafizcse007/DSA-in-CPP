#include <bits/stdc++.h>
using namespace std;
void FindSum(vector<int> &nums, int target)
{
    vector<int> store;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                store.emplace_back(i);
                store.emplace_back(j);
                break;
            }
        }
    }
    for (auto it : store)
    {
        cout << it << " ";
    }
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    FindSum(nums, target);
    return 0;
}