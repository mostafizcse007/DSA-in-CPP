#include <bits/stdc++.h>
using namespace std;
vector<int> countListOfList(char str[][4], int n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (str[i][j] == '#')
            {
                ans.emplace_back(j + 1);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char str[n][4];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
                cin >> str[i][j];
        }
        vector<int> result = countListOfList(str, n);
        for (auto it : result)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}