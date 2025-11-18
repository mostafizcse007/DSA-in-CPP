#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int t, a;
    cin >> t >> a;
    vector<int> arr(n);
    double close = INTMAX_MAX;
    int ind = -1;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        double temp = t - (arr[i] * .006);
        double num = abs(temp - a);
        if (num < close)
        {
            close = num;
            ind = i + 1;
        }
    }
    cout << ind << '\n';
    return 0;
}