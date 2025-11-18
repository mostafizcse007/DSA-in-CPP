#include <bits/stdc++.h>
using namespace std;
void moveZero(vector<int> &nums)
{
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            temp.emplace_back(nums[i]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }
    for (int i = temp.size(); i < nums.size(); i++)
    {
        nums[i] = 0;
    }
    for (auto it : nums)
    {
        cout << it << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    moveZero(nums);
}