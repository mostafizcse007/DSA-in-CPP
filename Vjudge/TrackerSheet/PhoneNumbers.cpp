#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int cntE = 0;
    for (auto it : arr)
    {
        if (it == '8')
            cntE++;
    }
    if (cntE == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    unordered_map<char, int> mpp;
    for (auto it : arr)
        mpp[it]++;
    int sum = 0;
    for (auto it : mpp)
        sum += it.second;
    int ans = sum / 11;
    if (ans <= cntE)
        cout << ans << endl;
    else
        cout << cntE << endl;
    return 0;
}