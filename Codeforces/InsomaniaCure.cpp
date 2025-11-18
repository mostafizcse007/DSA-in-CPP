#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntDiv(int k, int l, int m, int n, int d)
{
    set<int> st;
    for (int i = k; i <= d; i += k)
    {
        st.insert(i);
    }
    for (int i = l; i <= d; i += l)
    {
        st.insert(i);
    }
    for (int i = m; i <= d; i += m)
    {
        st.insert(i);
    }
    for (int i = n; i <= d; i += n)
    {
        st.insert(i);
    }
    return st.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    cout << cntDiv(k, l, m, n, d) << '\n';
    return 0;
}