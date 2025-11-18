#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[4];
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    string str;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int cal = (int)str[i] - 48;
        sum += arr[--cal];
    }
    cout << sum;
    return 0;
}