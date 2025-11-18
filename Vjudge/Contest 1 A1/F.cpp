#include <bits/stdc++.h>
using namespace std;

string minOp(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) > 1)
        {
            return "NO";
        }
    }
    return "YES";
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
        {
            cin >> arr[i];
        }
        cout << minOp(arr) << endl;
    }
    return 0;
}