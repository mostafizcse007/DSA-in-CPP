#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
#define ll long long
vector<bool> primes(N, 1);
vector<int> track(N, 0);
vector<bool> valid(N);
void Seive()
{
    primes[0] = primes[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j < N; j += i)
                primes[j] = false;
        }
    }
}
bool checkDigit(int n)
{
    while (n)
    {
        if (n % 10 == 0)
            return true;
        n /= 10;
    }
    return false;
}
bool checkSuffix(int n)
{
    if (!primes[n])
        return false;
    if (checkDigit(n))
        return false;
    string str = to_string(n);
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        string suffix = str.substr(i);
        int num = stoi(suffix);
        if (!primes[num])
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Seive();
    for (int i = 1; i < N; i++)
        valid[i] = checkSuffix(i);
    for (int i = 1; i < N; i++)
        track[i] = track[i - 1] + valid[i];
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << track[n] << '\n';
    }
    return 0;
}
