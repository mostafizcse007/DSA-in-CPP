#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> ans;
    while (t--)
    {
        vector<char> str(3);
        for (int i = 0; i < 3; i++)
            cin >> str[i];
        int sum = 0;
        sum += str[0] - 48;
        sum += str[2] - 48;
        ans.emplace_back(sum);
    }
    for (auto it : ans)
        cout << it << endl;
    return 0;
}