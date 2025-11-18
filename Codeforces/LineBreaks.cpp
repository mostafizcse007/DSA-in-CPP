#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i].size();
            if (sum <= m)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}