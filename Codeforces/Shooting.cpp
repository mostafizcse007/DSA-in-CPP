#include <bits/stdc++.h>
using namespace std;
#define ll long long
int totalShots(vector<pair<int, int>> &arr)
{
    int n = arr.size();
    int shots = 0;
    for (int i = 1; i < n; i++)
        shots += (arr[i].first * i + 1);
    return shots + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<pair<int, int>> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = {arr[i], i + 1};
    sort(temp.rbegin(), temp.rend());
    cout << totalShots(temp) << endl;
    for (auto it : temp)
        cout << it.second << " ";
    cout << endl;
    return 0;
}