#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int total = 0;
    total += (n / 100);
    n %= 100;
    total += (n / 20);
    n %= 20;
    total += (n / 10);
    n %= 10;
    total += (n / 5);
    n %= 5;
    total += (n / 1);
    n %= 1;
    cout << total << '\n';
    return 0;
}