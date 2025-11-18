#include <iostream>
using namespace std;
int minMove(int a, int b)
{
    if (a == b)
        return a + a;
    return 2 * max(a, b) - 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << minMove(a, b) << endl;
    }
    return 0;
}