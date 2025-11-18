#include <bits/stdc++.h>
using namespace std;
int findMissing(int a, int b)
{
    set<int> st;
    st.insert(a);
    st.insert(b);
    for (int i = 1; i <= 3; i++)
    {
        if (st.find(i) == st.end())
            return i;
    }
    return 69;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << findMissing(a, b) << endl;
    return 0;
}