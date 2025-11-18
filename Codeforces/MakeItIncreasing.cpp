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
        bool possible = true;

        for (int i = n - 2; i >= 0; i--)
        {
            while (arr[i] >= arr[i + 1] && arr[i] > 0)
            {
                arr[i] /= 2;
                cnt++;
            }
            if (arr[i] >= arr[i + 1])
            {
                possible = false;
                break;
            }
        }

        if (possible)
            cout << cnt << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}