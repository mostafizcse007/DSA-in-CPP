#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    str.append("WUB");
    int i = 0;
    string ans = "";
    while (i < str.size())
    {
        if (str[i] == 'W' and str[i + 1] == 'U' and str[i + 2] == 'B')
        {
            i += 3;
        }
        else
        {
            while (!(str[i] == 'W' and str[i + 1] == 'U' and str[i + 2] == 'B') and (i < str.size() - 2))
            {
                ans.push_back(str[i]);
                i++;
            }
            ans.push_back(' ');
        }
    }
    cout << ans << '\n';
    return 0;
}