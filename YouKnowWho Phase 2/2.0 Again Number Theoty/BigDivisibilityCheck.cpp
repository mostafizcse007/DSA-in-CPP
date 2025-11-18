#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int num;
    cin >> str >> num;
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        ans = (ans * 10 + (str[i] - '0')) % num;
    }
    cout << ans << '\n';
    return 0;
}