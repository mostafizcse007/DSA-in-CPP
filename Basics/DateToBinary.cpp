#include <bits/stdc++.h>
using namespace std;
string convertBinary(int n)
{
    if (n == 0)
        return "0";
    string ans = "";
    while (n > 0)
    {
        ans = char('0' + (n & 1)) + ans;
        n >>= 1;
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int i = 0;
    string s1, s2, s3;
    while (s[i] != '-')
    {
        s1.push_back(s[i]);
        i++;
    }
    i++;
    while (s[i] != '-')
    {
        s2.push_back(s[i]);
        i++;
    }
    i++;
    while (i < s.size())
    {
        s3.push_back(s[i]);
        i++;
    }
    int n1 = stoi(s1), n2 = stoi(s2), n3 = stoi(s3);
    string ans = convertBinary(n1) + '-' + convertBinary(n2) + '-' + convertBinary(n3);
    cout << ans << endl;
    return 0;
}