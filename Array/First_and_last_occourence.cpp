#include <bits/stdc++.h>
using namespace std;
int first(vector<int> &v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
            return i;
    }
    return -1;
}
int last(vector<int> &v, int target)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == target)
            return i;
    }
    return -1;
}
pair<int, int> firstAndlast(vector<int> &v, int target)
{
    int firstIdx = first(v, target);
    int lastIdx = last(v, target);
    return {firstIdx, lastIdx};
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    pair<int, int> result = firstAndlast(v, target);
    cout << result.first << " " << result.second;
    return 0;
}