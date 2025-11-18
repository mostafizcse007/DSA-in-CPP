#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 3 == 0)
        {
            int x = n / 3;
            cout << x << " " << x << endl;
        }
        else if (n % 3 == 2)
        {
            int c2 = ceil((double)n / 3);
            int c1 = n - (2 * c2);
            cout << c1 << " " << c2 << endl;
        }
        else
        {
            int c2 = n / 3;
            int c1 = n - (2 * c2);
            cout << c1 << " " << c2 << endl;
        }
    }
    return 0;
}