#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int cnt = 0;
    for (auto it : str)
    {
        if (it == '4' || it == '7')
            cnt++;
    }
    if (cnt == 7 || cnt == 4)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}