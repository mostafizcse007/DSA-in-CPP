#include <bits/stdc++.h>
using namespace std;
#define ll long long
int max_segment(vector<int> &arr)
{
    if (arr.size() == 1)
        return 1;
    int maxi = INT_MIN, cnt = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= arr[i - 1])
            cnt++;
        else
            cnt = 1;
        maxi = max(maxi, cnt);
    }
    return maxi;
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
    cout << max_segment(arr) << '\n';
    return 0;
}