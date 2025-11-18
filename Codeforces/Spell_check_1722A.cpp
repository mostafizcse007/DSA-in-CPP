#include <bits/stdc++.h>
using namespace std;
string SpellCheck(vector<char> &str)
{
    if (str.size() != 5)
        return "NO";
    vector<char> temp;
    temp = {'T', 'i', 'm', 'r', 'u'};
    sort(str.begin(), str.end());
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] != str[i])
            return "NO";
    }
    return "YES";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        vector<char> str(len);
        for (int i = 0; i < len; i++)
            cin >> str[i];
        cout << SpellCheck(str) << endl;
    }
    return 0;
}