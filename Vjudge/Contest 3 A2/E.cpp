#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n), brr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> brr[i];
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= x)
                cost += brr[i];
        }
        cout << cost << endl;
    }
    return 0;
}