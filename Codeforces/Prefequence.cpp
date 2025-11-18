#include <bits/stdc++.h>
using namespace std;
#define ll long long
int max_subs(string &arr, string &brr)
{
    int i = 0, j = 0, cnt = 0;
    int n = arr.size(), m = brr.size();
    while (i < n && j < m)
    {
        if (arr[i] == brr[j])
        {
            cnt++;
            i++;
        }
        j++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string arr, brr;
        cin >> arr >> brr;
        cout << max_subs(arr, brr) << '\n';
    }
    return 0;
}