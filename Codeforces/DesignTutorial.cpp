#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a = 8, b = n - a;
    if (isPrime(b))
    {
        a += 1;
        b -= 1;
    }
    cout << a << " " << b << endl;
    return 0;
}