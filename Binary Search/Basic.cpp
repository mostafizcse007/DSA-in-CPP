#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v, int key)
{
    int start = 0, end = v.size() - 1;
    // int mid = (start + end) / 2;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (v[mid] == key)
            return mid;
        else if (key > v[mid])
            start = mid + 1;
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int n, key;
    cin >> n >> key;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << binarySearch(v, key) << endl;
}