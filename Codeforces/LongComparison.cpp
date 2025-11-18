#include <bits/stdc++.h>
using namespace std;

void compareNumbers(long long a, long long b, long long c, long long d)
{
    long long len1 = to_string(a).length() + b;
    long long len2 = to_string(c).length() + d;
    if (len1 > len2)
    {
        cout << ">" << endl;
    }
    else if (len1 < len2)
    {
        cout << "<" << endl;
    }
    else
    {
        string num1 = to_string(a);
        string num2 = to_string(c);

        while (num1.length() < num2.length())
        {
            num1 += '0';
        }
        while (num2.length() < num1.length())
        {
            num2 += '0';
        }

        if (num1 == num2)
        {
            cout << "=" << endl;
        }
        else if (num1 > num2)
        {
            cout << ">" << endl;
        }
        else
        {
            cout << "<" << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        compareNumbers(a, b, c, d);
    }
    return 0;
}