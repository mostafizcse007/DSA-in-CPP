#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    vector<int> num2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> num2[i];
    }
    set<int> uni(num.begin(), num.end());
    set<int> clc;
    for (int i = 0; i < m; i++)
    {
        if (uni.find(num2[i]) != uni.end())
        {
            clc.insert(num2[i]);
        }
    }
    vector<int> result;
    for (auto it : clc)
    {
        result.push_back(it);
    }
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}