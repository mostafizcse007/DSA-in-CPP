#include <bits/stdc++.h>
using namespace std;
string easyString(string &str)
{
    if (str.size() == 1)
        return str;
    string newString = "";
    for (int i = 0; i < str.size(); i++)
    {
        newString.push_back(str[i]);
        newString.push_back('+');
    }
    newString.pop_back();
    return newString;
}
int main()
{
    string s;
    cin >> s;
    string ans = "";
    for (auto it : s)
    {
        if (it >= '1' && it <= '3')
            ans.push_back(it);
    }
    sort(ans.begin(), ans.end());
    cout << easyString(ans) << endl;
    return 0;
}