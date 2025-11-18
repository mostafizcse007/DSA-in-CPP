#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntDivs(int n)
{
    int cnt = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int exp = 0;
            while (n % i == 0)
            {
                exp++;
                n /= i;
            }
            cnt *= (exp + 1);
        }
    }
    if (n > 1)
        cnt *= 2;
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    cout << cntDivs(n) << endl;
    return 0;
}