#include <bits/stdc++.h>
using namespace std;
int manipulationSize(vector<string> &str)
{
    int size = str.size();
    if (size <= 1)
        return size;
    stack<string> st;
    st.push(str[0]);
    for (int i = 1; i < size; i++)
    {
        if (str[i] != st.top())
            st.push(str[i]);
        else
            st.pop();
    }
    return st.size();
}
int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    cout << manipulationSize(str) << endl;
    return 0;
}