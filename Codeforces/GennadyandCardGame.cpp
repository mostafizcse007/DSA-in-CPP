#include <bits/stdc++.h>
using namespace std;
bool playGame(string s, vector<string> &str)
{
    for (int i = 0; i < 5; i++)
    {
        string temp = str[i];
        if (s[0] == temp[0] || s[1] == temp[1])
            return 1;
    }
    return 0;
}
int main()
{
    string s;
    cin >> s;
    vector<string> str(5);
    for (int i = 0; i < 5; i++)
        cin >> str[i];
    if (playGame(s, str))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}