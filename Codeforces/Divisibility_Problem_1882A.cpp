#include <iostream>
using namespace std;

long long int makeDivisible(long long int a, long long int b)
{
    return (b - a % b) % b;
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        cout << makeDivisible(a, b) << endl;
    }
    return 0;
}
