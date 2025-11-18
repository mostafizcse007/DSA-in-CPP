#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int val = 240 - k;
    vector<int> arr(10);
    arr[0] = 5;
    int j = 2;
    for (int i = 1; i <= 10; i++)
    {
        arr[i] = arr[i - 1] + (5 * j);
        j++;
    }
    int ans = n;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > val)
        {
            ans = i;
            break;
        }
    }
    if (ans > n)
        cout << n << '\n';
    else
        cout << ans << '\n';
    return 0;
}