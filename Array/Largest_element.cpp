#include <bits/stdc++.h>
using namespace std;
int largest(vector<int> &v)
{
    int big = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > big)
            big = v[i];
    }
    return big;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << largest(v);
}