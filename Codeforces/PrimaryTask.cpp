#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if ((n >= 102 && n <= 109) || (n >= 1010 && n <= 1099))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}