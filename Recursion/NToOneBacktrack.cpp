#include <iostream>
using namespace std;
void NToOne(int n, int cnt)
{
    if (n == 0)
        return;
    cnt++;
    NToOne(n - 1, cnt);
    cout << cnt << endl;
}
int main()
{
    int n;
    cin >> n;
    NToOne(n, 0);
    return 0;
}