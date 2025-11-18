#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int x = 0;
    vector<pair<int, int>> ans;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++)
        {
            if (isPrime(i))
            {
                int exp = 0;
                for (int j = 1; j <= n; j++)
                {
                    int cpy = j;
                    while (cpy % i == 0)
                    {
                        exp++;
                        cpy /= i;
                    }
                }
                ans.push_back({i, exp});
            }
        }
        int size = ans.size();
        cout << "Case " << ++x << ": " << n << " = ";
        for (int k = 0; k < size - 1; k++)
        {
            cout << ans[k].first << " (" << ans[k].second << ") * ";
        }
        cout << ans[size - 1].first << " (" << ans[size - 1].second << ")" << endl;
        ans.clear();
    }
    return 0;
}