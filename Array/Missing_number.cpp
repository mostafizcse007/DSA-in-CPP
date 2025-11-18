#include <bits/stdc++.h>
using namespace std;
long long findMissingNumber(vector<int> &arr)
{
    unordered_map<long long, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for (int i = 1; i <= arr.size() + 1; i++)
    {
        if (mpp.find(i) == mpp.end())
            return i;
    }
    return -1;
}
int main()
{
    long long n;
    cin >> n;
    n -= 1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMissingNumber(arr) << endl;
    return 0;
}