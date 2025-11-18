#include <bits/stdc++.h>
using namespace std;
#define ll long long
int get_min(vector<int> &arr)
{
    if (arr[0] > 15)
        return 15;
    if (arr.size() == 1)
    {
        int val = arr[0] + 15;
        if (val > 90)
            return 90;
        return val;
    }

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] > 15)
            return arr[i - 1] + 15;
    }
    int val = arr[arr.size() - 1] + 15;
    if (val > 90)
        return 90;
    return val;
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
    cout << get_min(arr);
    return 0;
}