#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll count_ways(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    return count_ways(n - 1) + count_ways(n - 3);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << count_ways(n) << '\n';
    return 0;
}