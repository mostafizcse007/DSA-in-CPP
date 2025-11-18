#include <bits/stdc++.h>
using namespace std;
long long int sumDiff(long long int &n)
{
    long long int sum = 0;
    if (n & 1)
    {
        long long int even_cnt = n / 2;
        long long int odd_cnt = even_cnt + 1;
        long long int even_sum = even_cnt * (even_cnt + 1);
        long long int odd_sum = odd_cnt * odd_cnt;
        return even_sum - odd_sum;
    }
    long long int c1 = n / 2;
    long long int c2 = n / 2;
    long long int s1 = c1 * (c1 + 1);
    long long int s2 = c2 * c2;
    return s1 - s2;
}
int main()
{
    long long int n;
    cin >> n;
    cout << sumDiff(n) << endl;
    return 0;
}