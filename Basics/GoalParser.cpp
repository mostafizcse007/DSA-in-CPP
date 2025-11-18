#include <bits/stdc++.h>
using namespace std;
string goalParser(string str)
{
    int size = str.size();
    string ans = "";
    int i = 0;
    while (i < size)
    {
        if (str[i] == 'G')
        {
            ans.push_back(str[i]);
            i++;
        }
        else if (str[i] == '(' && i < size - 1 && str[i + 1] == ')')
        {
            ans.push_back('o');
            i += 2;
        }
        else
        {
            ans.push_back('a');
            ans.push_back('l');
            i += 4;
        }
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    cout << goalParser(str) << endl;
    return 0;
}