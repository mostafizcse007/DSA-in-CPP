#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> brr(m);
    for (int i = 0; i < m; i++)
        cin >> brr[i];
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    int cnt = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(arr[i] - brr[j]) <= k)
        {
            cnt++;
            i++;
            j++;
        }
        else if (arr[i] < brr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << cnt << endl;
    return 0;
}