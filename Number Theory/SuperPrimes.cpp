#include <bits/stdc++.h>
using namespace std;
int N = 1e5;
vector<bool> primes(N + 1, true);
void Seive(int n)
{
    primes[0] = false;
    primes[1] = false;
    for (int i = 4; i <= N; i += 2)
        primes[i] = false;
    for (int i = 3; i * i <= N; i += 2)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= N; j += 2 * i)
                primes[j] = false;
        }
    }
}
bool checkDigit(int x)
{
    while (x)
    {
        int last = x % 10;
        if (!primes[last])
            return false;
        x /= 10;
    }
    return true;
}
int main()
{
    Seive(N);
    int x;
    while (cin >> x)
    {
        if (!primes[x])
            cout << "Nada" << endl;
        else if (checkDigit(x) && primes[x])
            cout << "Super" << endl;
        else
            cout << "Primo" << endl;
    }
    return 0;
}
