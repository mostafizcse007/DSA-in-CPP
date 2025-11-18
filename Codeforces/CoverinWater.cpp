#include <bits/stdc++.h>
using namespace std;
int minOp(vector<char> &str)
{
    int cntD = 0, n = str.size();
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '.')
            cntD++;
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (str[i] == '.' and str[i + 1] == '.' and str[i + 2] == '.')
        {
            flag = true;
            break;
        }
    }
    if (flag)
        return 2;
    return cntD;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> str(n);
        for (int i = 0; i < n; i++)
            cin >> str[i];
        cout << minOp(str) << endl;
    }
    return 0;
}