#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long y = 2 * a;
        if (y <= b)
            cout << a << " " << y << endl;
        else
            cout << "-1 -1" << endl;
    }
    return 0;
}