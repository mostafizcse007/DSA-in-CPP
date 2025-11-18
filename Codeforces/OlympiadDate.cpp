#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_possible(vector<int> &digits)
{
    string val = "01032025";
    vector<int> store;

    for (char c : val)
    {
        store.push_back(c - '0');
    }

    sort(store.begin(), store.end());
    sort(digits.begin(), digits.end());

    return includes(digits.begin(), digits.end(),
                    store.begin(), store.end());
}

int solve(int n, vector<int> &arr)
{
    for (int i = 1; i <= n; i++)
    {
        vector<int> val(arr.begin(), arr.begin() + i);

        if (is_possible(val))
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve(n, arr) << '\n';
    }

    return 0;
}
