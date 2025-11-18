#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n & 1)
    {
        cout << floor(double(n) / 2) << endl;
        for (int i = 1; i < n - 2; i += 2)
            cout << 2 << " ";
        cout << 3;
        cout << endl;
    }
    else
    {
        cout << n / 2 << endl;
        for (int i = 0; i < n / 2; i++)
            cout << 2 << ' ';
        cout << endl;
    }
    return 0;
}