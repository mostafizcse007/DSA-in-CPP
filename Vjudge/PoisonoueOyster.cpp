#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "sick" and s2 == "fine")
        cout << 2 << '\n';
    else if (s2 == "sick" and s1 == "fine")
        cout << 3 << '\n';
    else if (s2 == "fine" and s1 == "fine")
        cout << 4 << '\n';
    else
        cout << 1 << '\n';
    return 0;
}