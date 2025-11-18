#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<char> str(6);
        for (int i = 0; i < 6; i++)
            cin >> str[i];
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 3; i++)
            cnt1 += str[i];
        for (int i = 3; i < 6; i++)
            cnt2 += str[i];
        if (cnt1 == cnt2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}