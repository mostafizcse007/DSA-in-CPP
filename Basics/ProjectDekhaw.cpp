#include <bits/stdc++.h>
using namespace std;
#define ll long long
int fibo(int n)
{
    if (n <= 2)
        return n - 1;
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int web, moblie;
    cin >> web >> moblie;
    int sum = 0;
    for (int i = 1; i <= web + 1; i++)
        sum += fibo(i);
    for (int i = 1; i <= moblie + 1; i++)
        sum += fibo(i);
    cout << sum << endl;
    return 0;
}