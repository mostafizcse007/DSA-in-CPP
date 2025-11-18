#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int sp = n - i;
        for (int j = 1; j <= sp; j++)
            cout << ' ';
        for (int j = sp; j < n; j++)
            cout << '*';
        for (int j = 1; j < i; j++)
            cout << '*';
        cout << '\n';
    }
    return 0;
}