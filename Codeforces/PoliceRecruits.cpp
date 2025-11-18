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
    reverse(arr.begin(), arr.end());
    int i = 0;
    while (arr[i] != -1 and i < n)
        i++;
    int cnt_minus = 0;
    while (i < n)
    {
        if (arr[i] == -1)
            cnt_minus++;
        else
        {
            if (cnt_minus < arr[i])
                cnt_minus = 0;
            else
                cnt_minus -= arr[i];
        }
        i++;
    }
    // if (sum > 0)
    //     cout << 0 << '\n';
    // else
    //     cout << abs(sum) << '\n';
    cout << cnt_minus << '\n';
    return 0;
}