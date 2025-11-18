#include <bits/stdc++.h>
using namespace std;
void minOperations(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    if (arr.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i] - arr[i - 1]) > 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
        minOperations(arr);
    }
    return 0;
}