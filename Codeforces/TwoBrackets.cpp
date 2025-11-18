#include <bits/stdc++.h>
using namespace std;
int minOp(string &str)
{
    int openF = 0, openT = 0, cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            openF++;
        else if (str[i] == '[')
            openT++;
        else if (str[i] == ')')
        {
            if (openF)
            {
                openF--;
                cnt++;
            }
        }
        else if (str[i] == ']')
        {
            if (openT)
            {
                openT--;
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str;
        cin >> str;
        cout << minOp(str) << endl;
    }

    return 0;
}
