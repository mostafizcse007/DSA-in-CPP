#include <bits/stdc++.h>
using namespace std;
int maxMeeting(vector<int> &start, vector<int> &end)
{
    int cnt = 1;
    int n = start.size();
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
        temp.push_back({end[i], start[i]});
    sort(temp.begin(), temp.end());
    int en = temp[0].first;
    for (int i = 1; i < n; i++)
    {
        if (temp[i].second > en)
        {
            en = temp[i].first;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> st(n), end(n);
    for (int i = 0; i < n; i++)
        cin >> st[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];
    cout << maxMeeting(st, end) << endl;
    return 0;
}