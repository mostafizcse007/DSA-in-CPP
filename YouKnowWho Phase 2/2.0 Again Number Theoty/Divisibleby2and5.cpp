#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    if (str[str.size() - 1] == '0')
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}