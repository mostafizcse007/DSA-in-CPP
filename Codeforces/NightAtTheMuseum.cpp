#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int cnt = 0;
    int val = abs('a' - str[0]);
    if (val <= 13)
        cnt += val;
    else
        cnt += (26 - val);
    for (int i = 1; i < str.size(); i++)
    {
        int temp = abs(str[i] - str[i - 1]);
        cnt += min(temp, 26 - temp);
    }
    cout << cnt << endl;
    return 0;
}