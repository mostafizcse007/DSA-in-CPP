#include <bits/stdc++.h>
using namespace std;
string makeCondition(int a, int b)
{
    if (a == 0)
    {
        if (b & 1)
            return "NO";
        else
            return "YES";
    }
    else if (b == 0)
    {
        if (a & 1)
            return "NO";
        else
            return "YES";
    }
    b *= 2;
    int total = a + b;
    if (total & 1)
        return "NO";
    return "YES";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << makeCondition(a, b) << endl;
    }
    return 0;
}