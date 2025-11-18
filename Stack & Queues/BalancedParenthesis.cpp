#include <bits/stdc++.h>
using namespace std;

bool checkBalanced(string &str) {
    stack<char> st;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[')
            st.push(str[i]);
        else {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();
            if ((str[i] == ')' && ch != '(') || 
                (str[i] == ']' && ch != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(); s
    while (n--) {
        string str;
        getline(cin, str);
        if (checkBalanced(str))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}