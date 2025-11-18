#include <bits/stdc++.h>
using namespace std;

bool checkCombination(long long n)
{
    string num = to_string(n);
    while (num.find("33") != string::npos)
    {
        size_t pos = num.find("33");
        num.erase(pos, 2);
    }
    if (num.empty())
        return true;
    n = stoi(num);
    if (n == 0)
        return true;
    if (n < 33)
        return false;
    if (n % 33 == 0)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (checkCombination(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}