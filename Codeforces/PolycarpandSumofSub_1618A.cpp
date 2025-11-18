#include <bits/stdc++.h>
using namespace std;
vector<long long> getEqualSum(vector<long long> &arr)
{
    vector<long long> ans;
    int n = arr.size();
    long long maxi = arr[6];
    long long sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = arr[i] + arr[j] + arr[k];
                if (sum == maxi)
                    return {arr[i], arr[j], arr[k]};
            }
        }
    }
    return {-1};
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        vector<long long> arr(7);
        for (int i = 0; i < 7; i++)
            cin >> arr[i];
        vector<long long> res = getEqualSum(arr);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}