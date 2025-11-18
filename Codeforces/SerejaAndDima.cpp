#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll x = 0, y = 0;
    int cnt = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (cnt % 2 == 0)
        {
            if (arr[i] > arr[j])
            {
                x += arr[i];
                i++;
            }
            else
            {
                x += arr[j];
                j--;
            }
        }
        else
        {
            if (arr[i] > arr[j])
            {
                y += arr[i];
                i++;
            }
            else
            {
                y += arr[j];
                j--;
            }
        }
        cnt++;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}