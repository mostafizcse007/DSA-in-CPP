#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 50;
vector<ll> arr(N, 0);
ll fibo(int n)
{
    if (n <= 1)
        return n;
    if (arr[n])
        return arr[n];
    arr[n] = fibo(n - 1) + fibo(n - 2);
    return arr[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fibo(50) << '\n';
    return 0;
}