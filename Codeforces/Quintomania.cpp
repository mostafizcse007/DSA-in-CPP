#include <bits/stdc++.h>
using namespace std;
bool isPerfect(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int val = abs(arr[i] - arr[i + 1]);
        if (val != 7 && val != 5)
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (isPerfect(arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}