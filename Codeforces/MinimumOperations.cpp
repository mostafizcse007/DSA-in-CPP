#include <iostream>
using namespace std;
int minOperations(int n, int k)
{
    int cnt = 0;
    if (k == 1)
    {
        return n;
    }
    while (n > 0)
    {
        cnt += n % k;
        n /= k;
    }

    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << minOperations(n, k) << endl;
    }

    return 0;
}
