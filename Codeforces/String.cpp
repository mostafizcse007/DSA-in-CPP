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
        int cnt = 0;
        for (auto it : str)
        {
            if (it == '1')
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}