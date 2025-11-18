#include <bits/stdc++.h>
using namespace std;
int secLarge(vector<int> &v, int n)
{
    int large = v[0], sec = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > large)
        {
            sec = large;
            large = v[i];
        }
        else if (v[i] < large && sec < v[i])
            sec = v[i];
    }
    if (sec == INT_MIN)
        return -1;
    return sec;
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.emplace_back(val);
    }
    cout << secLarge(v, n);
    return 0;
}