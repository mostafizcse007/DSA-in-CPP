#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int cnt = 1, maxi = INT_MIN;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
            cnt++;
        else
            cnt = 1;
        maxi = max(maxi, cnt);
    }
    cout << maxi << '\n';
    return 0;
}