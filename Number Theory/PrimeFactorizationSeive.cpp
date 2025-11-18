#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<bool> primes(N, 1);
vector<int> hp(N, 0);
#define ll long long
void Mark()
{
    primes[0] = primes[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (primes[i])
        {
            hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                primes[j] = false;
                hp[j] = i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Mark();
    int num;
    cin >> num;
    vector<int> store;
    while (num > 1)
    {
        int factor = hp[num];
        while (num % factor == 0)
        {
            num /= factor;
            store.push_back(factor);
        }
    }
    for (auto it : store)
        cout << it << " ";
    return 0;
}