#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        sum += abs(s[i] - s[i + 1]);
    }
    cout << sum;
}