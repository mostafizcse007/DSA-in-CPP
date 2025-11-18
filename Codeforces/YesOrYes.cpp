#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        for (int i = 0; i < 3; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        }
        if (str == "yes")
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}