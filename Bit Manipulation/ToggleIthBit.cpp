#include <iostream>
using namespace std;
int clearBit(int n, int x)
{
    return (n ^ (1 << x));
}
int main()
{
    int n, x;
    cin >> n >> x;
    cout << clearBit(n, x) << endl;
    return 0;
}