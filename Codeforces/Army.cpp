#include <bits/stdc++.h>
using namespace std;
int desierdRank(vector<int> &arr, int a, int b)
{
    int year = 0;
    for (int i = a - 1; i < b - 1; i++)
        year += arr[i];
    return year;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n - 1; i++)
    {
        int el;
        cin >> el;
        arr.push_back(el);
    }
    int a, b;
    cin >> a >> b;
    cout << desierdRank(arr, a, b) << endl;
    return 0;
}