#include <bits/stdc++.h>
using namespace std;
vector<char> getWords(char str[8][8], int row, int col)
{
    vector<char> ans;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (str[i][j] != '.')
                ans.push_back(str[i][j]);
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        char str[8][8];
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                cin >> str[i][j];
        }
        vector<char> result(getWords(str, 8, 8));
        for (auto it : result)
            cout << it;
        cout << endl;
    }
    return 0;
}