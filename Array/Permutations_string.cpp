#include <bits/stdc++.h>
using namespace std;
void helper(string &s, vector<string> &ans, int index)
{
    if (index == s.size() - 1)
    {
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[i], s[index]);
        helper(s, ans, index + 1);
        swap(s[i], s[index]);
    }
}
vector<string> getPermutations(string &s)
{
    vector<string> ans;
    int index = 0;
    helper(s, ans, index);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> res = getPermutations(s);
    for (auto it : res)
    {
        cout << it << endl;
    }
    return 0;
}