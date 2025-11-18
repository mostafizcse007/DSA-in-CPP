#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxDay(vector<int> &arr, int k)
{
    int cnt = 0, temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            temp++;
        if (temp == k)
        {
            cnt++;
            i++;
            temp = 0;
        }
        if (arr[i] == 1)
            temp = 0;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxDay(arr, k) << '\n';
    }
    return 0;
}