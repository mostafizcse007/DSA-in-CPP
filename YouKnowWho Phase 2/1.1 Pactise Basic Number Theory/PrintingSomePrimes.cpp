#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
bitset<N> check;
#define ll long long
void preCompute()
{

    check[1] = true;
    for (int i = 2; i * i < N; i++)
    {
        if (!check[i])
        {
            for (int j = i * i; j < N; j += i)
                check[j] = true;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preCompute();
    vector<int> primes;
    for (int i = 2; i < N; i++)
    {
        if (!check[i])
            primes.push_back(i);
    }
    int size = primes.size();
    for (int i = 0; i < size; i += 100)
        cout << primes[i] << '\n';
    return 0;
}