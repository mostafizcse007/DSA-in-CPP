#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findTarget(vector<int> &arr, int target)
{
    int size = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            set<int> hashset;
            for (int k = j + 1; k < size; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                int fourth = target - (sum);
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}