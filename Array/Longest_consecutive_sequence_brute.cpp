#include <bits/stdc++.h>
using namespace std;
int Longest(vector<int> &arr)
{
    set<int> arr1(arr.begin(), arr.end());
    vector<int> result;
    for (auto it : arr1)
        result.emplace_back(it);
    int count = 1, maxi = 1;
    for (int i = 0; i < result.size() - 1; i++)
    {
        if (result[i + 1] - result[i] == 1)
            count++;
        else
            count = 1;
        maxi = max(maxi, count);
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Longest(arr) << endl;
    return 0;
}