#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
        int cpy = n;
        n = 2 * n - 2;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            arr[i] = temp;
        }

        vector<string> val;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].size() == cpy - 1)
                val.push_back(arr[i]);
        }
        string s1 = val[0], s2 = val[1];
        reverse(s1.begin(), s1.end());
        if (s1 == s2)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}