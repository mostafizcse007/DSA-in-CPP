#include <bits/stdc++.h>
using namespace std;
int Position(vector<int> &arr, int n)
{
    if (arr[0] != arr[1] && arr[0] != arr[2])
        return 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1])
            return i + 1;
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << Position(arr, n) << endl;
    }
    return 0;
}