#include <bits/stdc++.h>
using namespace std;
#define ll long long

int smallDigit(int n)
{
    int mini = INT_MAX;
    while (n)
    {
        if (mini > (n % 10))
            mini = n % 10;
        n /= 10;
    }
    return mini;
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
        cout << smallDigit(n) << '\n';
    }
    return 0;
}