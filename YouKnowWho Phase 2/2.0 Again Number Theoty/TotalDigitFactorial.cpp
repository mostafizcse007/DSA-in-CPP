#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (log10(i));
    }
    sum += 1;
    cout << floor(sum) << '\n';
    return 0;
}