#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    while (n != 0)
    {
        int last = n % 10;
        ans = ans * 10 + last;
        n /= 10;
    }
    cout << ans;
}