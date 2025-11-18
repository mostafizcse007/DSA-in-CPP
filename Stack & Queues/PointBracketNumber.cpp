#include <bits/stdc++.h>
using namespace std;
vector<int> bracketNumber(string &str)
{
    stack<char> st;
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            cnt++;
            st.push(cnt);
            ans.push_back(cnt);
        }
        else if (str[i] == ')')
        {
            int top = st.top();
            ans.push_back(top);
            st.pop();
        }
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    vector<int> res = bracketNumber(str);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}