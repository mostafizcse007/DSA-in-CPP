#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long> arr(4);
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    unordered_map<long long, int> mpp;
    for (int i = 0; i < 4; i++)
        mpp[arr[i]]++;
    vector<int> temp;
    int cnt = 0;
    for (auto it : mpp)
    {
        if (it.second > 1)
        {
            temp.emplace_back(it.second);
            cnt = it.second;
        }
    }
    if (temp.size() == 0)
        cout << 0 << endl;
    else if (temp.size() == 2)
        cout << 2 << endl;
    else
        cout << cnt - 1 << endl;
    return 0;
}