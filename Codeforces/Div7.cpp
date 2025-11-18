#include <iostream>
using namespace std;

int makeDivisibleBy7(int n)
{
    if (n % 7 == 0)
    {
        return n;
    }
    for (int i = 0; i <= 9; ++i)
    {
        int modified = (n / 10) * 10 + i;
        if (modified % 7 == 0)
        {
            return modified;
        }
    }
    return n;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << makeDivisibleBy7(n) << endl;
    }
    return 0;
}
