#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000000;
vector<int> spf(MAXN + 1);
void sieve()
{
    for (int i = 2; i <= MAXN; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (spf[i] == i)
        { 
            for (int j = i * i; j <= MAXN; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
vector<int> getPrimeDivisors(int n)
{
    vector<int> primeDivisors;
    while (n != 1)
    {
        int prime = spf[n];
        if (primeDivisors.empty() || primeDivisors.back() != prime)
        {
            primeDivisors.push_back(prime);
        }
        n /= prime;
    }
    return primeDivisors;
}

int main()
{
    sieve();

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--)
    {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        vector<int> primeDivisors = getPrimeDivisors(n);
        cout << "Prime divisors of " << n << " are: ";
        for (int prime : primeDivisors)
        {
            cout << prime << " ";
        }
        cout << endl;
    }
    return 0;
}