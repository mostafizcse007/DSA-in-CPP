#include <bits/stdc++.h>
using namespace std;
int convertDecimal(string str)
{
    int size = str.size();
    int total = 0, p2 = 1;
    while (size--)
    {
        int num = (str[size] - '0');
        if (num == 1)
            total += p2;
        p2 *= 2;
    }
    return total;
}
int main()
{
    string s;
    cin >> s;
    cout << convertDecimal(s) << endl;
    return 0;
}