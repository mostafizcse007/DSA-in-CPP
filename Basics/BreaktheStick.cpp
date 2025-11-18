#include <iostream>
using namespace std;
bool canBreak(int n, int k)
{
    if ((n % 2 == 0) && (k & 1))
        return 1;
    if ((n & 1) && (k % 2 == 0))
        return 0;
    if ((n & 1) && (k & 1))
        return 1;
    if (n % k == 0)
        return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (canBreak(n, k))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}