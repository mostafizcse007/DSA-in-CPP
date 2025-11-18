#include <bits/stdc++.h>
using namespace std;
int maxCookies(vector<int> &greed, vector<int> &cookie)
{
    int n = greed.size(), m = cookie.size();
    sort(greed.begin(), greed.end());
    sort(cookie.begin(), cookie.end());
    int l = 0, r = 0, cnt = 0;
    while (l < n && r < m)
    {
        if (cookie[r] >= greed[l])
        {
            cnt++;
            l++;
            r++;
        }
        else
            r++;
    }
    return cnt;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cookie(n);
    vector<int> greed(m);
    for (int i = 0; i < n; i++)
        cin >> cookie[i];
    for (int i = 0; i < m; i++)
        cin >> greed[i];
    cout << maxCookies(greed, cookie) << endl;
    return 0;
}