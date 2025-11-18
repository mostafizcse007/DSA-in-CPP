#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> IndexElementRelation(vector<int> &arr)
{
    vector<int> ans;
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
        mpp[arr[i]] = i + 1;
    for (auto it : mpp)
        ans.emplace_back(it.second);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = IndexElementRelation(arr);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}