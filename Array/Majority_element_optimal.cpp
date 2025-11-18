#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr, int size)
{
    unordered_map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    for (auto it : mpp)
    {
        if (it.second > size / 2)
            return it.first;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << majorityElement(arr, n) << endl;
    return 0;
}