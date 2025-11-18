#include <iostream>
using namespace std;
int claculateDay(long long n, int a, int b, int c)
{
    if (n <= a)
        return 1;
    if (n <= a + b)
        return 2;
    if (n <= a + b + c)
        return 3;

    int sum = a + b + c;
    int day = (n / sum) * 3;
    int remaining = n % sum;

    if (remaining == 0)
        return day;
    if (remaining <= a)
        return day + 1;
    if (remaining <= a + b)
        return day + 2;
    return day + 3;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        int a, b, c;
        cin >> n >> a >> b >> c;
        cout << claculateDay(n, a, b, c) << endl;
    }
    return 0;
}