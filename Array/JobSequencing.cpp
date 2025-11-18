#include <bits/stdc++.h>
using namespace std;
int getMax(vector<int> &deadline)
{
    int maxi = -1;
    for (auto it : deadline)
        maxi = max(maxi, it);
    return maxi;
}
pair<int, int> JobSequencing(vector<int> &id, vector<int> &deadline,
                             vector<int> &profit)
{
    vector<pair<int, int>> temp;
    int n = id.size();
    for (int i = 0; i < n; i++)
        temp.push_back({profit[i], deadline[i]});
    sort(temp.rbegin(), temp.rend());
    int maxi = getMax(deadline);
    vector<bool> arr(maxi + 1, false);
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (!arr[temp[i].second])
        {
            arr[temp[i].second] = true;
            cnt++;
            sum += temp[i].first;
        }
        else
        {
            int j = temp[i].second;
            while (j > 0)
            {
                if (!arr[j] & j > 0)
                {
                    arr[j] = true;
                    cnt++;
                    sum += temp[i].first;
                    break;
                }
                j--;
            }
        }
    }
    return {cnt, sum};
}
int main()
{
    int n;
    cin >> n;
    vector<int> id(n), deadline(n), profit(n);
    for (int i = 0; i < n; i++)
        cin >> id[i];
    for (int i = 0; i < n; i++)
        cin >> deadline[i];
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    pair<int, int> res = JobSequencing(id, deadline, profit);
    cout << res.first << " " << res.second << endl;
    return 0;
}