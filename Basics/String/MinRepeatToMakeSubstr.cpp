#include <bits/stdc++.h>
using namespace std;
int minRepeat(string &str1, string &str2)
{
    string temp = str1;
    int cnt = 1;
    while (str1.size() < str2.size())
    {
        cnt++;
        str1 += temp;
    }
    if (str1.find(str2) != -1)
        return cnt;
    str1 += temp;
    cnt++;
    if (str1.find(str2) != -1)
        return cnt;
    return -1;
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << minRepeat(str1, str2) << endl;
    return 0;
}