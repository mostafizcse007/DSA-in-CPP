#include <bits/stdc++.h>
using namespace std;
#define ll long long
int min_moves(int n)
{
    int cnt = 0;
    while (true)
    {
        if (n % 5 == 0)
            return -1;
        if (n == 1)
            break;
        else if (n % 6 == 0)
            n /= 6;
        else
            n *= 2;
        cnt++;
    }
    return cnt;
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
        cout << min_moves(n) << '\n';
    }

    return 0;
}