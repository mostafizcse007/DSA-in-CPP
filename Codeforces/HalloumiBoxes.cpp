#include <bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if ((k == 1 && n == 1) || (k > 1) || isSorted(arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}