#include <bits/stdc++.h>
using namespace std;
int uniqueChar(string &str)
{
    int cnt = 0;
    unordered_map<char, int> mpp;
    for (int i = 0; i < str.size(); i++)
    {
        if (mpp.find(str[i]) == mpp.end() && (str[i] >= 'a' && str[i] <= 'z'))
            cnt++;
        mpp[str[i]]++;
    }
    return cnt;
}
int main()
{
    string str;
    getline(cin, str, '}');
    cout << uniqueChar(str) << endl;
    return 0;
}