#include <iostream>
using namespace std;
bool checkBitLeft(int n, int x)
{
    return (n & (1 << x));
}
bool checkBitright(int n, int x)
{
    return (1 & (n >> x));
}
int main()
{
    int n, x;
    cin >> n >> x;
    cout << checkBitLeft(n, x) << endl;
    cout << checkBitright(n, x) << endl;
    return 0;
}