#include <iostream>
using namespace std;
int setBit(int n, int x)
{
    return (n | (1 << x));
}
int main()
{
    int n, x;
    cin >> n >> x;
    cout << setBit(n, x) << endl;
    return 0;
}