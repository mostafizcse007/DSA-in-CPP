#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    set<int> st;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        auto val = st.find(b);
        if (a == 1)
            st.insert(b);
        else if (a == 2)
            st.erase(b);

        else
        {
            if (val != st.end())
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        }
    }
    return 0;
}