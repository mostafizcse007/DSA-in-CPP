#include <bits/stdc++.h>
using namespace std;
#define ll long long
int minPrice(int n, int a, int b)
{
    if (n == 1)
        return a;
    else if (a * 2 <= b)
        return n * a;
    else
    {
        if (n & 1)
            return (n / 2) * b + a;
        else
            return (n / 2) * b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        cout << minPrice(n, a, b) << endl;
    }
    return 0;
}