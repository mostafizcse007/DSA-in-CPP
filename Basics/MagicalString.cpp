#include <bits/stdc++.h>
using namespace std;
string magicalString(string &str)
{
    int x = 0;
    map<char, char> mpp;
    for (int i = 97; i <= 122; i++)
    {
        mpp[i] = 122 - x;
        x++;
    }
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        ans.push_back(mpp[str[i]]);
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    string res = magicalString(str);
    cout << res << endl;
    return 0;
}