#include <iostream>
using namespace std;
void NtoOne(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    n--;
    NtoOne(n);
}
int main()
{
    int n;
    cin >> n;
    NtoOne(n);
    return 0;
}