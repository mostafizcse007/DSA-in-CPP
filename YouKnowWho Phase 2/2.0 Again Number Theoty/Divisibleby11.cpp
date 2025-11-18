#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    cin >> num;
    int sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (i & 1)
            sum += (num[i] - '0');
        else
            sum -= (num[i] - '0');
    }
    if (sum % 11 == 0)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}