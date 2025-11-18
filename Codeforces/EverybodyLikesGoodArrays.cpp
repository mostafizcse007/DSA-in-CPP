#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if ((arr[i] & 1) and (arr[i - 1] & 1) or (arr[i] % 2 == 0) and (arr[i - 1] % 2 == 0))
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}