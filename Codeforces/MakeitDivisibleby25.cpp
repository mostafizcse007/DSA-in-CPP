#include <bits/stdc++.h>
using namespace std;
#define ll long long
int min_move(string &str)
{
    int i = str.size() - 1, dist1 = 0, dist2 = 0;
    while (i > 0)
    {
        if (str[i] == '5')
            break;
        i--;
        dist1++;
    }
    int f_5 = i;
    --f_5;
    i = str.size() - 1;
    while (i > 0)
    {
        if (str[i] == '0')
            break;
        i--;
        dist2++;
    }
    int f_0 = i;
    --f_0;
    while (f_5 >= 0)
    {
        if (str[f_5] == '7' || str[f_5] == '2')
            break;
        f_5--;
        dist1++;
    }
    while (f_0 >= 0)
    {
        if (str[f_0] == '0' || str[f_0] == '5')
            break;
        f_0--;
        dist2++;
    }
    return min(dist1, dist2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << min_move(str) << '\n';
    }
    return 0;
}