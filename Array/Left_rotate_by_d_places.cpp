#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    d %= n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> temp(d);
    for (int i = 0; i < d; i++)
    {
        temp[i] = v[i];
    }
    for (int i = d; i < n; i++)
    {
        v[i - d] = v[i];
    }
    for (int i = n - d; i < n; i++)
    {
        v[i] = temp[i - d - 1];
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}