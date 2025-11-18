#include <iostream>
using namespace std;
int modExpo(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int x = modExpo(a, b / 2, m) % m;
    int ans = (x % m * x % m) % m;
    if (b & 1)
        ans = (ans % m * a % m) % m;
    return ans;
}
int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << modExpo(a, b, m) << endl;
    return 0;
}