#include <bits/stdc++.h>
using namespace std;
#define ll long long
int digit_sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (true)
    {
        int sum = digit_sum(n);
        if (sum % 4 == 0)
        {
            cout << n << '\n';
            break;
        }
        n++;
    }
    return 0;
}