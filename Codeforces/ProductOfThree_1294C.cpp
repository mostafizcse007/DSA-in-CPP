#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        int a = 1, b = 1, c = 1;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                a = i;
                break;
            }
        }
        num = num / a;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0 && i != a)
            {
                b = i;
                num /= b;
                break;
            }
        }
        c = num;
        if (a != 1 && b != 1 && c != 1 && a != b && b != c && c != a)
        {
            cout << "yes" << endl;
            cout << a << " " << b << " " << c << endl;
        }
        else
            cout << "no" << endl;
    }
    return 0;
}
