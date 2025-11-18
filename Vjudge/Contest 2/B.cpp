#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    arr.clear();
    for (auto it : mpp)
    {
        if (it.second & 1)
            arr.push_back(it.first);
    }
    int sum = 0;
    for (int i = 1; i < arr.size(); i += 2)
        sum += (arr[i] - arr[i - 1]);
    cout << sum << endl;
    return 0;
}