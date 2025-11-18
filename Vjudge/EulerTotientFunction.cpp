#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = __gcd(i, n);
            if (x == 1)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}