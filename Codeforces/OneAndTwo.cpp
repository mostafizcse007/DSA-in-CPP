#include <bits/stdc++.h>
using namespace std;
#define ll long long
int is_possible(vector<int> &arr)
{
    int cnt_two = 0;
    for (auto x : arr)
    {
        if (x == 2)
            cnt_two++;
    }
    if (cnt_two & 1)
        return -1;
    if (cnt_two == 0)
        return 1;
    int seg = cnt_two / 2, cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 2)
            ++cnt;
        if (seg == cnt)
            return i + 1;
    }
    return 69;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << is_possible(arr) << '\n';
    }
    return 0;
}