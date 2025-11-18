#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> shuffle(vector<int> &arr)
{
    int i = 0, j = arr.size() - 1;
    vector<int> ans;
    while (i <= j)
    {
        if (i == j)
            ans.push_back(arr[i]);
        else
        {
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
        }
        i++;
        j--;
    }
    return ans;
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
        if (arr[0] == arr[n - 1])
            cout << "NO" << '\n';
        else
        {
            cout << "YES" << '\n';
            vector<int> res = shuffle(arr);
            for (auto x : res)
                cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}