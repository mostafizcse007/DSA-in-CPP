#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        set<int> st{l, r, d, u};
        if (st.size() == 1)
            cout << "YES" << '\n';
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}