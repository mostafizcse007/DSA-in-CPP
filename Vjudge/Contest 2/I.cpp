#include <bits/stdc++.h>
using namespace std;
bool isDangerous(string &str)
{
    int maxiZero = INT_MIN, cntZ = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            cntZ++;
        maxiZero = max(maxiZero, cntZ);
        if (str[i] == '1')
            cntZ = 0;
    }
    int maxiOne = INT_MIN, cnt1 = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
            cnt1++;
        maxiOne = max(maxiOne, cnt1);
        if (str[i] == '0')
            cnt1 = 0;
    }
    if (maxiZero >= 7 || maxiOne >= 7)
        return true;
    return false;
}
int main()
{
    string s;
    cin >> s;
    if (isDangerous(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}