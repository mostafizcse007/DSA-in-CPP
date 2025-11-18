#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i = 0;
    cin >> n;
    double ans = 0;
    while (n != 0)
    {
        int lsb = n % 10;
        if (lsb == 1)
        {
            ans += pow(2, i);
        }
        i++;
        n /= 10;
    }
    cout << ans;
}