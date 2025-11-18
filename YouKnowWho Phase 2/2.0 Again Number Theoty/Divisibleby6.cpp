#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    cin >> num;
    int size = num.size();
    int last = num[size - 1] - '0';
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += num[i] - '0';
    }
    if (sum % 3 == 0 && last % 2 == 0)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}