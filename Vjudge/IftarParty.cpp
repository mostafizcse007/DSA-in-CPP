#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int c = 0;
    while (t--)
    {
        int p, l;
        cin >> p >> l;
        int n = p - l;
        vector<int> ans;
        for (int i = 1; (long long)i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i > l)
                    ans.push_back(i);
                if ((n / i) != i and l < (n / i))
                    ans.push_back(n / i);
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case " << ++c << ": ";
        if (ans.empty())
            cout << "impossible" << endl;
        else
        {
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}