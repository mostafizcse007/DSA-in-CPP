#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1;
        cin >> str1;
        string str2 = "codeforces";
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            if (str1[i] != str2[i])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}