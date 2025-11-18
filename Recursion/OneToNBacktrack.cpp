#include <iostream>
using namespace std;
void OneToN(int n)
{
    if (n == 0)
        return;
    OneToN(n - 1);
    cout << n << endl;
}
int main()
{
    int n;
    cin >> n;
    OneToN(n);
    return 0;
}