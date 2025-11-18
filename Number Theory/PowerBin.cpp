#include <iostream>
using namespace std;
int powerBin(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int x = powerBin(a, b / 2);
    if (b & 1)
        return x * x * a;
    return x * x;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << powerBin(a, b) << endl;
    return 0;
}