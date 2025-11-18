#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    cin >> num;
    int digit_sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        digit_sum += (num[i] - '0');
    }
    if (digit_sum % 9 == 0)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}