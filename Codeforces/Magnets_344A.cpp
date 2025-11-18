#include <bits/stdc++.h>
using namespace std;
int totalCount(vector<string> &str)
{
    int count = 1;
    if (str.size() == 1)
        return count;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != str[i - 1])
            count++;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    vector<string> str;
    while (t--)
    {
        string temp;
        cin >> temp;
        str.push_back(temp);
    }
    cout << totalCount(str) << endl;
    return 0;
}