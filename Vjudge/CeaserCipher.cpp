#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    unordered_set<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        int temp = a[i] - b[i];
        if (temp < 0)
            temp += 26;
        st.insert(temp);
    }
    if (st.size() == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}