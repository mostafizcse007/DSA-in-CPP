#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long diff = x - y;
        if (diff == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}