#include <bits/stdc++.h>
using namespace std;
#define ll long long
int max_seg(vector<char> &arr)
{
    int cnt = 1, maxi = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
            cnt++;
        else
            cnt = 1;
        maxi = max(maxi, cnt);
    }
    return maxi + 1;
}
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
        vector<char> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << max_seg(arr) << '\n';
    }
    return 0;
}