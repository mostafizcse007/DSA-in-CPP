#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, i = 1;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int x = abs(a - b) * 4;
        x += a * 4;
        x += 19;
        cout << "Case " << i << ": " << x << endl;
        i++;
    }
    return 0;
}