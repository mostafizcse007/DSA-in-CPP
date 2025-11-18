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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n * k);
        for (int i = 0; i < n * k; i++)
        {
            cin >> arr[i];
        }

        ll sum = 0;
        int cpy = n;
        int step = cpy / 2;
        int index = n * k - step - 1;

        for (int i = 0; i < k; i++)
        {
            if (i == 0)
                sum += arr[index];
            else
                sum += arr[--index];
            index -= step;
        }
        cout << sum << '\n';
    }

    return 0;
}