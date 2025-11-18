#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool can_construct(vector<int> &arr)
{
    ll sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i])
        {
            sum += (arr[i] % 10);
            arr[i] /= 10;
        }
    }
    if (sum % 3 == 0)
        return true;
    return false;
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
        if (can_construct(arr))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}