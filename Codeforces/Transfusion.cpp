#include <bits/stdc++.h>
using namespace std;
bool isEqual(vector<long> &arr)
{
    int n = arr.size();
    long long sum = 0;
    for (auto it : arr)
        sum += it;
    if (sum % n != 0)
        return 0;
    long need = sum / n;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] == need)
            continue;
        else if (arr[i - 1] > need)
        {
            int temp = arr[i - 1] - need;
            arr[i - 1] = arr[i - 1] - temp;
            arr[i + 1] = arr[i + 1] + temp;
        }
        else if (arr[i - 1] < need)
        {
            int temp = need - arr[i - 1];
            arr[i - 1] = arr[i - 1] + temp;
            arr[i + 1] = arr[i + 1] - temp;
        }
    }
    for (auto it : arr)
    {
        if (it != need)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (isEqual(arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}