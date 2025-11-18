#include <bits/stdc++.h>
using namespace std;
#define ll long long
int trailing_zeroes(int n)
{
    int cnt = 0;
    while (n)
    {
        n /= 5;
        cnt += n;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << trailing_zeroes(n) << '\n';
    return 0;
}