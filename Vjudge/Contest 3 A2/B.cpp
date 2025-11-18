#include <bits/stdc++.h>
using namespace std;
bool checkDiv(int n)
{
    int oddDiv = 0, evenDiv = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i & 1)
                oddDiv++;
            if (i % 2 == 0)
                evenDiv++;
            if ((n / i) != i)
            {
                if ((n / i) & 1)
                    oddDiv++;
                if ((n / i) % 2 == 0)
                    evenDiv++;
            }
        }
    }
    return oddDiv == evenDiv;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << checkDiv(n) << endl;
    }
    return 0;
}