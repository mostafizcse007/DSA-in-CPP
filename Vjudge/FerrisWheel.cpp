#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntMin(vector<int> &arr, int x)
{
    int cnt = 0;
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        ll sum = arr[i] + arr[j];
        if (sum > x)
        {
            cnt++;
            j--;
        }
        else if (sum == x)
        {
            cnt++;
            i++;
            j--;
        }
        else
        {
            cnt++;
            i++;
            j--;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << cntMin(arr, x) << '\n';
    return 0;
}