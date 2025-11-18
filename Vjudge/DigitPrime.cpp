#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
vector<int> primes(N, 1);
#define ll long long
int get_digit(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
void precompute()
{
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i < N; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j < N; j += i)
                primes[j] = 0;
        }
    }
    for (int i = N; i >= 0; i--)
    {
        if (primes[i] == 1 and primes[get_digit(i)] == 1)
            continue;
        else
            primes[i] = 0;
    }
    for (int i = 1; i < N; i++)
        primes[i] += primes[i - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == 0)
            printf("%d\n", primes[r]);
        else if (r == 0)
            printf("%d\n", primes[0]);
        else
            printf("%d\n", primes[r] - primes[l - 1]);
    }
    return 0;
}