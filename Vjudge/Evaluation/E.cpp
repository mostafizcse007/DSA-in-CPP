#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    map<string, int> mpp;
    while (t--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            string b;
            int c;
            cin >> b >> c;
            mpp[b] += c;
        }
        else if (a == 2)
        {
            string b;
            cin >> b;
            mpp.erase(b);
        }
        else
        {
            string b;
            cin >> b;
            cout << mpp[b] << '\n';
        }
    }
    return 0;
}