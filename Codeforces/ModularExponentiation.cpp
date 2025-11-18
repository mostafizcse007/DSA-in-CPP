#include <iostream>
using namespace std;
long long modPow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int x = modPow(a, b / 2);
    if (b & 1)
        return x * x * a;
    return x * x;
}
int main()
{
    int n, m;
    cin >> n >> m;
    if (n > 30)
        cout << m << endl;
    else
    {
        long long temp = modPow(2, n);
        long long ans = m % temp;
        cout << ans << endl;
    }
    return 0;
}