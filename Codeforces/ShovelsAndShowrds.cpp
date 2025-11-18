#include <bits/stdc++.h>
using namespace std;
int minOp(int a, int b)
{
    int cnt = 0;
    if (a == 0 && b == 0)
        return 0;
    if ((a == 0 && b > 1) || (b == 0 && a > 1))
        return 0;
    if ((a == 1 && b > 1) || (b == 1 && a > 1))
        return 1;
    return min(min(a, b), (a + b) / 3);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << minOp(a, b) << endl;
    }
    return 0;
}