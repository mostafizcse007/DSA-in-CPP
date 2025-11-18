#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<string> ans;
    while (t--)
    {
        vector<int> arr(3);
        for (int i = 0; i < 3; i++)
            cin >> arr[i];
        if (arr[0] < arr[1] && arr[1] < arr[2])
            ans.emplace_back("STAIR");
        else if (arr[1] > arr[0] && arr[1] > arr[2])
            ans.emplace_back("PEAK");
        else
            ans.emplace_back("NONE");
    }
    for (auto it : ans)
        cout << it << endl;
    return 0;
}