#include <bits/stdc++.h>
using namespace std;

bool findSegment(string &s) {
    int first = s.find('1');
    int last = s.rfind('1');
    if (first == string::npos) {
        return false;
    }

    for (int i = first; i <= last; i++) {
        if (s[i] != '1') {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (findSegment(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}