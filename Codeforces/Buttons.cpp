#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_possible(int a, int b, int c)
{
    if (a > b)
        return true;
    if (b > a)
        return false;
    if (c & 1)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (is_possible(a, b, c))
            cout << "First" << '\n';
        else
            cout << "Second" << '\n';
    }
    return 0;
}