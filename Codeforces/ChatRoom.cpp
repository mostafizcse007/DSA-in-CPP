#include <bits/stdc++.h>
using namespace std;
bool modifyStr(string &str)
{
    if (str.size() < 5)
        return 0;
    int first = str.find('h');
    int last = str.rfind('o');
    if (first == string::npos)
        return 0;
    if (last == string::npos)
        return 0;
    string newString = "";
    for (int i = first; i <= last; i++)
        newString.push_back(str[i]);
    int findE = newString.find('e');
    if (findE == string::npos)
        return 0;
    int cntL = 0;
    for (int i = findE; i < newString.size(); i++)
    {
        if (newString[i] == 'l')
            cntL++;
    }
    if (cntL < 2)
        return 0;
    return 1;
}
int main()
{
    string str;
    cin >> str;
    if (modifyStr(str))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    modifyStr(str);
    return 0;
}