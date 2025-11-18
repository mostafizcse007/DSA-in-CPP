#include <bits/stdc++.h>
using namespace std;
int secLargest(vector<int> &v, int n)
{
    int largest = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] != largest)
        {
            largest = v[i];
            return largest;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.emplace_back(element);
    }
    sort(v.begin(), v.end());
    cout << secLargest(v, n);
    return 0;
}