#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntDay(vector<int> &arr)
{
    int cnt = 0, day = 1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= day)
        {
            cnt++;
            ++day;
        }
    }
    return cnt;
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
    cout << cntDay(arr) << endl;
    return 0;
}