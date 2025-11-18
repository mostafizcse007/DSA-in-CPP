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
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        vector<int> divs;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divs.push_back(i);
                if (n / i != i)
                    divs.push_back(n / i);
            }
        }
        int cnt = 0;
        for (auto it : divs)
        {
            if (it <= a)
            {
                for (auto i : divs)
                {
                    if (i <= b)
                    {
                        if (n % (1ll * it * i) == 0)
                        {
                            int z = n / (i * it);
                            if (z <= c)
                                cnt++;
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}