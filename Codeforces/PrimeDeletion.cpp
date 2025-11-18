#include <bits/stdc++.h>
using namespace std;
int smallPrime(string str)
{
    for (auto it : str)
    {
        if (it == '1')
            return 13;
        if (it == '3')
            return 31;
    }
    return 69;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << smallPrime(str) << endl;
    }
    return 0;
}