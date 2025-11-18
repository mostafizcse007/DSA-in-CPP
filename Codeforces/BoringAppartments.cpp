#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n)
{
    int digit = log10(n) + 1;
    int num = n % 10;
    --num;
    if (digit == 1)
        cout << (num * 10) + 1 << '\n';
    else if (digit == 2)
        cout << (num * 10) + 3 << '\n';
    else if(digit == 3)
        cout << (num * 10) + 6 << '\n';
    else
        cout << (num * 10) + 10 << '\n';
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
        solve(n);
    }
    return 0;
}