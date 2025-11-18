#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> v2[i];
    }
    set<int> uni;
    for (int i = 0; i < n1; i++)
    {
        uni.insert(v1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        uni.insert(v2[i]);
    }
    for (auto it : uni)
        cout << it << " ";
    return 0;
}