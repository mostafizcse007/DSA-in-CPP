#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, ans = "";
    cin >> str;
    int i = 0;
    while (i < str.size())
    {
        if (str[i] == '.')
        {
            ans.push_back('0');
            i++;
        }
        else if (str[i] == '-' && str[i + 1] == '.' && i + 1 < str.size())
        {
            ans.push_back('1');
            i += 2;
        }
        else if (str[i] == '-' && str[i + 1] == '-' && i + 1 < str.size())
        {
            ans.push_back('2');
            i += 2;
        }
    }
    cout << ans;
    return 0;
}